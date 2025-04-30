//Teleword Solver
#include<fstream>
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>

using namespace std;
int horizontalF = 0, horizontalB = 0, verticalF = 0, verticalB = 0;
int forwarddiagnalF = 0, forwarddiagnalB = 0, backdiagnalF = 0, backdiagnalB = 0;



void readfile(char puzzle[][15], char search[][15], int& totalwords) {
	ifstream file("doc.txt");

	if (file.is_open()) {

		int j = 0;
		while (!file.eof() && j < 15) {
			for (int i = 0; i < 15;i++) {
				file >> puzzle[j][i];
			}
			j++;
		}
		totalwords = 0;
		while (!file.eof()) {
			file >> search[totalwords++];

		}

	}
	else
		cout << "file not open"<<endl;


	file.close();

}

void colorgrid(char character, int count) {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	if (count == 0) {
		SetConsoleTextAttribute(color, 7);
		cout << character << ' ';
	}
	else if (count == 1) {
		SetConsoleTextAttribute(color, 6);
		cout << character << ' ';
	}
	else if (count == 2) {
		SetConsoleTextAttribute(color, 1);
		cout << character << ' ';
	}
	else if (count > 2) {
		SetConsoleTextAttribute(color, 4);
		cout << character << ' ';
	}


}

void printteleword(int countappears[][15], char puzzle[][15]) {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, 7);
	cout << "Teleword: ";
	for (int i = 0;i < 15;i++) {                       //concatinating the letters not used 
		for (int j = 0;j < 15;j++) {
			if (countappears[i][j] == 0) {
				cout << puzzle[i][j];
			}
		}
	}
}

void SearchWordbyWord(int words, char searchStrings[][15], char puzzle[][15], int countappears[][15], int wordlencount[]) {
	
	int rr, cc, wordlen = 0, col = 0;
	char firstletter;

	for (int i = 0;i < 15;i++) {                         //printing grid before search
		for (int j = 0;j < 15;j++) {
			colorgrid(puzzle[i][j], countappears[i][j]);
		}
		cout << endl;
	}


	for (int z = 0; z < words;z++) {                                //loops through all words; one word searched at a time
		firstletter = searchStrings[z][0];
		for (wordlen = 0;searchStrings[z][wordlen] != ',' && searchStrings[z][wordlen] != '.';wordlen++) {}
		wordlencount[z] = wordlen;                                  //word length of every word added to an array 
		int counter = 0;

		for (int i = 0;i < 15;i++) {                                //horizontal forward

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					int k = j + 1;
					col = 1;
					while (1) {
						if (puzzle[i][k] == searchStrings[z][col++]) {
							counter++;

						}
						else
							break;
						if (counter == wordlen - 1) {
							horizontalF++;
							for (int h = j;h - j < wordlen;h++) {
								countappears[i][h]++;
							}
							break;
						}
						k++;
					}
				}
			}
		}

		for (int i = 0;i < 15;i++) {                                         //horizontal backward

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					int k = j - 1;
					col = 1;
					while (k > -1) {
						if (puzzle[i][k] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							horizontalB++;
							for (int h = j;j - h < wordlen;h--) {
								countappears[i][h]++;
							}
							break;
						}
						k--;
					}
				}
			}
		}
		for (int i = 0;i < 15;i++) {                                        //vertical down

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					int k = i + 1;
					col = 1;
					while (1) {
						if (puzzle[k][j] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							verticalF++;
							for (int h = i;h - i < wordlen;h++) {
								countappears[h][j]++;
							}
							break;
						}
						k++;

					}
				}
			}
		}
		for (int i = 0;i < 15;i++) {                                         //vertical up

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					int k = i - 1;
					col = 1;
					while (k > -1) {
						if (puzzle[k][j] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							verticalB++;
							for (int h = i;i - h < wordlen;h--) {
								countappears[h][j]++;
							}
							break;
						}
						k--;

					}
				}
			}
		}
		for (int i = 0;i < 15;i++) {

			for (int j = 0; j < 15;j++) {           //leftup to rightdown 
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					col = 1;
					int r = i + 1;
					int c = j + 1;
					while (1) {
						if (puzzle[r++][c++] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							forwarddiagnalF++;
							for (rr = i, cc = j;(rr - i) < wordlen && (cc - j) < wordlen;rr++, cc++) {
								countappears[rr][cc]++;
							}
							break;
						}
					}
				}
			}
		}
		for (int i = 0;i < 15;i++) {                //lowerright to upperleft 

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					col = 1;
					int r = i - 1;
					int c = j - 1;
					while (r >= 0 && c >= 0) {
						if (puzzle[r--][c--] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							forwarddiagnalB++;
							for (rr = i, cc = j;(i - rr) < wordlen && (j - cc) < wordlen;rr--, cc--) {
								countappears[rr][cc]++;
							}
							break;
						}
					}
				}
			}
		}
		for (int i = 0;i < 15;i++) {                       //upperright to lowerleft

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					col = 1;
					int r = i + 1;
					int c = j - 1;
					while (c >= 0) {
						if (puzzle[r++][c--] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							backdiagnalB++;
							for (rr = i, cc = j; (rr - i) < wordlen && (j - cc) < wordlen;rr++, cc--) {
								countappears[rr][cc]++;
							}
							break;
						}
					}
				}
			}
		}
		for (int i = 0;i < 15;i++) {                         //lowerleft to upperright

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					col = 1;
					int r = i - 1;
					int c = j + 1;
					while (r >= 0 && c >= 0) {
						if (puzzle[r--][c++] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							backdiagnalF++;
							for (rr = i, cc = j;(i - rr) < wordlen && (cc - j) < wordlen;rr--, cc++) {
								countappears[rr][cc]++;
							}
							break;
						}
					}
				}
			}
		}
		wordlen = 0;
		cout << endl << endl;

		system("pause");
		system("cls");

		for (int i = 0;i < 15;i++) {                            //prints the grid after each corresponding search
			for (int j = 0;j < 15;j++) {
				colorgrid(puzzle[i][j], countappears[i][j]);
			}
			cout << endl;
		}


	}
	cout << endl;
	printteleword(countappears, puzzle);                  //teleword printed
}

void SearchOnce(int words, char searchStrings[][15], char puzzle[][15], int countappears[][15], int wordlencount[]) {

	int rr, cc, wordlen = 0, col = 0;
	char firstletter;

	for (int z = 0; z < words;z++) {
		firstletter = searchStrings[z][0];
		for (wordlen = 0;searchStrings[z][wordlen] != ',' && searchStrings[z][wordlen] != '.';wordlen++) {}
		wordlencount[z] = wordlen;
		int counter = 0;

		for (int i = 0;i < 15;i++) {

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					int k = j + 1;
					col = 1;
					while (1) {
						if (puzzle[i][k] == searchStrings[z][col++]) {
							counter++;

						}
						else
							break;
						if (counter == wordlen - 1) {
							horizontalF++;
							for (int h = j;h - j < wordlen;h++) {
								countappears[i][h]++;
							}
							break;
						}
						k++;
					}
				}
			}
		}

		for (int i = 0;i < 15;i++) {

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					int k = j - 1;
					col = 1;
					while (k > -1) {
						if (puzzle[i][k] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							horizontalB++;
							for (int h = j;j - h < wordlen;h--) {
								countappears[i][h]++;
							}
							break;
						}
						k--;
					}
				}
			}
		}
		for (int i = 0;i < 15;i++) {

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					int k = i + 1;
					col = 1;
					while (1) {
						if (puzzle[k][j] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							verticalF++;
							for (int h = i;h - i < wordlen;h++) {
								countappears[h][j]++;
							}
							break;
						}
						k++;

					}
				}
			}
		}
		for (int i = 0;i < 15;i++) {

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					int k = i - 1;
					col = 1;
					while (k > -1) {
						if (puzzle[k][j] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							verticalB++;
							for (int h = i;i - h < wordlen;h--) {
								countappears[h][j]++;
							}
							break;
						}
						k--;

					}
				}
			}
		}
		for (int i = 0;i < 15;i++) {

			for (int j = 0; j < 15;j++) {           //leftup to rightdown 
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					col = 1;
					int r = i + 1;
					int c = j + 1;
					while (1) {
						if (puzzle[r++][c++] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							forwarddiagnalF++;
							for (rr = i, cc = j;(rr - i) < wordlen && (cc - j) < wordlen;rr++, cc++) {
								countappears[rr][cc]++;
							}
							break;
						}
					}
				}
			}
		}
		for (int i = 0;i < 15;i++) {                //lowerright to upperleft 

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					col = 1;
					int r = i - 1;
					int c = j - 1;
					while (r >= 0 && c >= 0) {
						if (puzzle[r--][c--] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							forwarddiagnalB++;
							for (rr = i, cc = j;(i - rr) < wordlen && (j - cc) < wordlen;rr--, cc--) {
								countappears[rr][cc]++;
							}
							break;
						}
					}
				}
			}
		}
		for (int i = 0;i < 15;i++) {                       //upperright to lowerleft

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					col = 1;
					int r = i + 1;
					int c = j - 1;
					while (c >= 0) {
						if (puzzle[r++][c--] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							backdiagnalB++;
							for (rr = i, cc = j; (rr - i) < wordlen && (j - cc) < wordlen;rr++, cc--) {
								countappears[rr][cc]++;
							}
							break;
						}
					}
				}
			}
		}
		for (int i = 0;i < 15;i++) {                         //lowerleft to upperright

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					col = 1;
					int r = i - 1;
					int c = j + 1;
					while (r >= 0 && c >= 0) {
						if (puzzle[r--][c++] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							backdiagnalF++;
							for (rr = i, cc = j;(i - rr) < wordlen && (cc - j) < wordlen;rr--, cc++) {
								countappears[rr][cc]++;
							}
							break;
						}
					}
				}
			}
		}
		wordlen = 0;
		
	}
	cout << endl;
	for (int i = 0;i < 15;i++) {
		for (int j = 0;j < 15;j++) {
			colorgrid(puzzle[i][j], countappears[i][j]);
		}
		cout << endl;
	}
	cout << endl;
	
	printteleword(countappears, puzzle);
}

void countStats(int words, char searchStrings[][15], char puzzle[][15], int countappears[][15], int rowcount[],int colcount[]) {
	int rr, cc, wordlen = 0, col = 0;

	char firstletter;
	horizontalF = 0, horizontalB = 0, verticalF = 0, verticalB = 0;
	forwarddiagnalF = 0, forwarddiagnalB = 0, backdiagnalF = 0, backdiagnalB = 0;
	
	
	
	for (int z = 0; z < words;z++) {
		firstletter = searchStrings[z][0];
		for (wordlen = 0;searchStrings[z][wordlen] != ',' && searchStrings[z][wordlen] != '.';wordlen++) {}
		
		int counter = 0;

		for (int i = 0;i < 15;i++) {                         //horizontal forward

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					int k = j + 1;
					col = 1;
					while (1) {
						if (puzzle[i][k] == searchStrings[z][col++]) {
							counter++;

						}
						else
							break;
						if (counter == wordlen - 1) {
							rowcount[i]++;
							
							horizontalF++;
							for (int h = j;h - j < wordlen;h++) {
								countappears[i][h]++;
								colcount[h]++;
							}
							break;
						}
						k++;
					}
				}
			}
		}

		for (int i = 0;i < 15;i++) {                       //horizontal backward

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					int k = j - 1;
					col = 1;
					while (k > -1) {
						if (puzzle[i][k] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							horizontalB++;
							rowcount[i]++;
							
							for (int h = j;j - h < wordlen;h--) {
								countappears[i][h]++;
								colcount[h]++;
							}
							break;
						}
						k--;
					}
				}
			}
		}
		for (int i = 0;i < 15;i++) {

			for (int j = 0; j < 15;j++) {                    //vertical down
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					int k = i + 1;
					col = 1;
					while (1) {
						if (puzzle[k][j] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							
							colcount[j]++;
							verticalF++;
							for (int h = i;h - i < wordlen;h++) {
								countappears[h][j]++;
								rowcount[h]++;
							}
							break;
						}
						k++;

					}
				}
			}
		}
		for (int i = 0;i < 15;i++) {

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					int k = i - 1;
					col = 1;
					while (k > -1) {
						if (puzzle[k][j] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							verticalB++;
				
							colcount[j]++;
							for (int h = i;i - h < wordlen;h--) {
								countappears[h][j]++;
								rowcount[h]++;
							}
							break;
						}
						k--;

					}
				}
			}
		}
		for (int i = 0;i < 15;i++) {

			for (int j = 0; j < 15;j++) {           //upperleft to lowerright 
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					col = 1;
					int r = i + 1;
					int c = j + 1;
					while (1) {
						if (puzzle[r++][c++] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							forwarddiagnalF++;
							
							for (rr = i, cc = j;(rr - i) < wordlen && (cc - j) < wordlen;rr++, cc++) {
								countappears[rr][cc]++;
								rowcount[rr]++;
								colcount[cc]++;
							}
							break;
						}
					}
				}
			}
		}
		for (int i = 0;i < 15;i++) {                //lowerright to upperleft 

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					col = 1;
					int r = i - 1;
					int c = j - 1;
					while (r >= 0 && c >= 0) {
						if (puzzle[r--][c--] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							forwarddiagnalB++;
							
							for (rr = i, cc = j;(i - rr) < wordlen && (j - cc) < wordlen;rr--, cc--) {
								countappears[rr][cc]++;
								rowcount[rr]++;
								colcount[cc]++;
							}
							break;
						}
					}
				}
			}
		}
		for (int i = 0;i < 15;i++) {                       //upperright to lowerleft

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					col = 1;
					int r = i + 1;
					int c = j - 1;
					while (c >= 0) {
						if (puzzle[r++][c--] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							backdiagnalB++;
							
							for (rr = i, cc = j; (rr - i) < wordlen && (j - cc) < wordlen;rr++, cc--) {
								countappears[rr][cc]++;
								rowcount[rr]++;
								colcount[cc]++;
							}
							break;
						}
					}
				}
			}
		}
		for (int i = 0;i < 15;i++) {                         //lowerleft to upperright

			for (int j = 0; j < 15;j++) {
				if (puzzle[i][j] == firstletter) {
					counter = 0;
					col = 1;
					int r = i - 1;
					int c = j + 1;
					while (r >= 0 && c >= 0) {
						if (puzzle[r--][c++] == searchStrings[z][col++]) {
							counter++;
						}
						else
							break;
						if (counter == wordlen - 1) {
							backdiagnalF++;
							
							for (rr = i, cc = j;(i - rr) < wordlen && (cc - j) < wordlen;rr--, cc++) {
								countappears[rr][cc]++;
								rowcount[rr]++;
								colcount[cc]++;
							}
							break;
						}
					}
				}
			}
		}
		wordlen = 0;

	}
	
	
}

void stats(int wordlencount[], int totalwords, int countappears[][15], char puzzle[][15], int rowcount[], int colcount[]) {
	int min = wordlencount[0], max = wordlencount[0];
	int total = 0;
	int scatter = 0;
	for (int i = 0; i < totalwords;i++) {     //calc min and max word length
		if (wordlencount[i] > max)
			max = wordlencount[i];
		if (wordlencount[i] < min) {
			min = wordlencount[i];
		}
		total += wordlencount[i];
	}

	bool found = false;                    //calculating scatter of teleword
	for (int i = 0;i < 15;i++) {
		found = false;
		for (int j = 0;j < 15;j++) {
			if (countappears[i][j] == 0) {
				found = true;
			}
		}
		if (found == true)
			scatter++;
	}

	int maxrow = rowcount[0];
	int maxcol = colcount[0];
	int rownum = 0, colnum = 0;
	for (int i = 0;i < 15;i++) {           //calculating heaviest row and heaviest column
		if (rowcount[i] > maxrow) {
			maxrow = rowcount[i];
			rownum = i;
		}
		if (colcount[i] > maxcol) {
			maxcol = colcount[i];
			colnum = i;
		}
	}

	cout << "Longest word length: " << max << endl;
	cout << "Shortest word length: " << min << endl;
	cout << "Average word length: " << total / totalwords<<endl;
	cout << "Word Distribution:  ";
	cout << "Horizontal: " << horizontalF + horizontalB << "(" << horizontalF << ", " << horizontalB << ")";
	cout << ", Vertical: " << verticalF + verticalB << "(" << verticalF << ", " << verticalB << ")";
	cout << ", Diagonal: " << forwarddiagnalF + backdiagnalF + forwarddiagnalB + backdiagnalB << "(" << forwarddiagnalF + backdiagnalF << ", " << forwarddiagnalB + backdiagnalB << ")";
	cout << endl;
	cout << "Teleword Scatter: " << scatter<< endl;
	cout << "Heaviest Row: " << rownum << endl;
	cout << "Heaviest column: " << colnum<<endl;

}

int main() {
	clock_t start, end;
	int totalwords = 0;
	char choice = ' ';
	char puzzle[15][15];
	char searchStrings[100][15];       //stores words to be searched
	int countappears[15][15] = { 0 };     //stores number of time each character is used in the puzzle
	int wordlencount[100]={0};            //stores length of each word to search
	int rowcount[20]={0};
	int colcount[20]={0};

	readfile(puzzle, searchStrings, totalwords);

	for (int i = 0;i < 15;i++)                         //printing grid once
	{
		for (int j = 0;j < 15;j++)
		{
			cout << puzzle[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;

	for (int i = 0;i < totalwords;i++) {
		cout << searchStrings[i] << ' ';
	}

	for (int i = 0;i < totalwords;i++) {
		for (int j = 1;searchStrings[i][j] != ',' && searchStrings[i][j] != '.';j++) {
			searchStrings[i][j] -= 'a' - 'A';
		}
	}
	
	cout << endl;
	cout << "1. Press S to solve the puzzle at once." << endl;
	cout << "2. Press T to solve the puzzle step by step." << endl;
	cout << "3. Press X to print puzzle statistics." << endl;
	
	cin >> choice;
	
	if (choice == 'S') {
		SearchOnce(totalwords, searchStrings, puzzle, countappears, wordlencount);
	}
	else if (choice == 'T') {
		SearchWordbyWord(totalwords, searchStrings, puzzle, countappears, wordlencount);
	}
	else if (choice == 'X') {
		
		start = clock();
		SearchOnce(totalwords, searchStrings, puzzle, countappears, wordlencount);
		end = clock();
		cout << endl;
		countStats(totalwords, searchStrings, puzzle, countappears, rowcount,colcount);
		
		double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
		cout << "Time Taken : " << fixed<< time_taken ;
		cout << " sec " << endl;
		
		stats(wordlencount, totalwords,countappears,puzzle,rowcount,colcount);
	}

	
	return 0;
}
