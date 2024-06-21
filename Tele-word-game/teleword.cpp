#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <windows.h>
using namespace std;

bool horilr(char grid[15][15], char word[15], int count, int counter[15][15], char choice) {
    int k, z, i = 0, j;
    while (i < 15) {
        j = 0;
        while (j < 15) {
            k = 0;
            z = 0;
            if (word[k] == grid[i][j]) {
                while (k < count) {
                    if (word[k++] == grid[i][j++]) {
                        z++;
                        if (z == count) {
                            for (int y = 0; y < count; y++) {
                                counter[i][j - y - 1]++;
                            }
                            if (choice == 'T') {
                                char w;
                                cout << "press any to continue";
                                cin >> w;
                            }
                            return true;
                        }
                    } else {
                        j -= z;
                        break;
                    }
                }
            }
            j++;
        }
        i++;
    }
    return false;
}

bool horiRL(char grid[15][15], char word[20], int count, int counter[15][15], char choice) {
    int k, z, i = 15, j;
    while (i > 0) {
        j = 14;
        while (j >= 0) {
            k = 0;
            z = 0;
            if (word[k] == grid[i][j]) {
                while (k < count) {
                    if (word[k++] == grid[i][j--]) {
                        z++;
                        if (z == count) {
                            for (int y = 0; y < count; y++) {
                                counter[i][j + y + 1]++;
                            }
                            if (choice == 'T') {
                                char w;
                                cout << "press any to continue";
                                cin >> w;
                            }
                            return true;
                        }
                    } else {
                        j += z;
                        break;
                    }
                }
            }
            j--;
        }
        i--;
    }
    return false;
}

bool vertDT(char grid[15][15], char word[20], int count, int counter[15][15], char choice) {
    int k, z, i, j = 15;
    while (j > 0) {
        i = 14;
        while (i >= 0) {
            k = 0;
            z = 0;
            if (word[k] == grid[i][j]) {
                while (k < count) {
                    if (word[k++] == grid[i--][j]) {
                        z++;
                        if (z == count) {
                            for (int y = 0; y < count; y++) {
                                counter[i + y + 1][j]++;
                            }
                            if (choice == 'T') {
                                char w;
                                cout << "press any to continue";
                                cin >> w;
                            }
                            return true;
                        }
                    } else {
                        i += z;
                        break;
                    }
                }
            }
            i--;
        }
        j--;
    }
    return false;
}

bool vertTD(char grid[15][15], char word[20], int count, int counter[15][15], char choice) {
    int k, z, i, j = 0;
    while (j < 15) {
        i = 0;
        while (i < 15) {
            k = 0;
            z = 0;
            if (word[k] == grid[i][j]) {
                while (k < count) {
                    if (word[k++] == grid[i++][j]) {
                        z++;
                        if (z == count) {
                            for (int y = 0; y < count; y++) {
                                counter[i - y - 1][j]++;
                            }
                            if (choice == 'T') {
                                char w;
                                cout << "press any to continue";
                                cin >> w;
                            }
                            return true;
                        }
                    } else {
                        i -= z;
                        break;
                    }
                }
            }
            i++;
        }
        j++;
    }
    return false;
}

bool digonalleftTD(char grid[15][15], char word[20], int count, int counter[15][15], char choice) {
    int k, z, i = 0, j;
    while (i < 15) {
        j = 0;
        while (j < 15) {
            k = 0;
            z = 0;
            if (word[k] == grid[i][j]) {
                while (k < count) {
                    if (word[k++] == grid[i++][j++]) {
                        z++;
                        if (z == count) {
                            for (int y = 0; y < count; y++) {
                                counter[i - y - 1][j - y - 1]++;
                            }
                            if (choice == 'T') {
                                char w;
                                cout << "press any to continue";
                                cin >> w;
                            }
                            return true;
                        }
                    } else {
                        i -= z;
                        j -= z;
                        break;
                    }
                }
            }
            j++;
        }
        i++;
    }
    return false;
}

bool digonalrightDT(char grid[15][15], char word[20], int count, int counter[15][15], char choice) {
    int k, z, i = 14, j;
    while (i >= 0) {
        j = 14;
        while (j >= 0) {
            k = 0;
            z = 0;
            if (word[k] == grid[i][j]) {
                while (k < count) {
                    if (word[k++] == grid[i--][j--]) {
                        z++;
                        if (z == count) {
                            for (int y = 0; y < count; y++) {
                                counter[i + y + 1][j + y + 1]++;
                            }
                            if (choice == 'T') {
                                char w;
                                cout << "press any to continue";
                                cin >> w;
                            }
                            return true;
                        }
                    } else {
                        i += z;
                        j += z;
                        break;
                    }
                }
            }
            j--;
        }
        i--;
    }
    return false;
}

bool digonalrightTD(char grid[15][15], char word[20], int count, int counter[15][15], char choice) {
    int k, z, i, j = 0;
    while (j < 15) {
        i = 14;
        while (i >= 0) {
            k = 0;
            z = 0;
            if (word[k] == grid[i][j]) {
                while (k < count) {
                    if (word[k++] == grid[i--][j++]) {
                        z++;
                        if (z == count) {
                            for (int y = 0; y < count; y++) {
                                counter[i + y + 1][j - y - 1]++;
                            }
                            if (choice == 'T') {
                                char w;
                                cout << "press any to continue";
                                cin >> w;
                            }
                            return true;
                        }
                    } else {
                        i += z;
                        j -= z;
                        break;
                    }
                }
            }
            i--;
        }
        j++;
    }
    return false;
}

bool digonalleftDT(char grid[15][15], char word[20], int count, int counter[15][15], char choice) {
    int k, z, i, j = 14;
    while (j >= 0) {
        i = 0;
        while (i < 15) {
            k = 0;
            z = 0;
            if (word[k] == grid[i][j]) {
                while (k < count) {
                    if (word[k++] == grid[i++][j--]) {
                        z++;
                        if (z == count) {
                            for (int y = 0; y < count; y++) {
                                counter[i - y - 1][j + y + 1]++;
                            }
                            if (choice == 'T') {
                                char w;
                                cout << "press any to continue";
                                cin >> w;
                            }
                            return true;
                        }
                    } else {
                        i -= z;
                        j += z;
                        break;
                    }
                }
            }
            i++;
        }
        j--;
    }
    return false;
}

int main() {
    char value = 0;
    int f = 0;
    while (f == 0) {
        cout << "1. Press S to solve the puzzle at once.\n";
        cout << "2. Press T to solve the puzzle step by step.\n";
        cout << "3. Press X to print puzzle statistics.\n";
        cin >> value;
        if (value == 'S' || value == 'T' || value == 'X') {
            break;
        }
    }

    int counter[15][15] = {0};  // Initialize counter array with zeros
    auto start_time = chrono::high_resolution_clock::now();  // Start timer

    char a1[15][15];
    char words[1000];
    char awords[1000] = " ";
    fstream newfile;
    newfile.open("tel.txt");
    if (newfile.is_open()) {
        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 15; j++) {
                newfile >> a1[i][j];
                cout << a1[i][j] << " ";
            }
            cout << endl;
        }
    }
    cout << endl;

    int k = 0;
    while (!newfile.eof()) {
        if (k < 2) {
            newfile.getline(words, 1000);
        }
        if (k >= 2) {
            newfile.getline(awords, 1000);
            cout << awords << "\n";
        }
        k++;
    }
    newfile.close();

    int wc1 = 0;
    k = 0;

    for (int i = 1; i < 1000; i++) {
        awords[i] = toupper(awords[i]);
        if (awords[i + 1] == ',') {
            i += 3;
            wc1++;
            k++;
        }
        if (awords[i + 1] == '.') {
            k++;
            break;
        }
    }

    const int x = wc1 + 1;
    char awd[x][15];
    int z = 0;
    int wl_arr[100] = {0};

    k = 0;
    for (int i = 0; i < x; i++) {
        for (int j = z; j < 1000; j++) {
            if (awords[j] == ',') {
                wl_arr[i] = k;
                z = j + 2;
                k = 0;
                break;
            }
            if (awords[j] == '.') {
                wl_arr[i] = k;
                break;
            }
            awd[i][k++] = awords[j];
        }
    }

    int sum = 0;
    for (int i = 0; i < wc1; i++) {
        sum += wl_arr[i];
    }
    int max = *max_element(wl_arr, wl_arr + wc1);
    int min = *min_element(wl_arr, wl_arr + wc1);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < wl_arr[i]; j++) {
            cout << awd[i][j];
        }
        cout << wl_arr[i] << "\n";
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            cout << a1[i][j];
        }
        cout << endl;
    }

    for (int i = 0; i < 46; i++) {
        int con = wl_arr[i];
        horilr(a1, awd[i], con, counter, value);
        horiRL(a1, awd[i], con, counter, value);
        vertDT(a1, awd[i], con, counter, value);
        vertTD(a1, awd[i], con, counter, value);
        digonalleftTD(a1, awd[i], con, counter, value);
        digonalleftDT(a1, awd[i], con, counter, value);
        digonalrightDT(a1, awd[i], con, counter, value);
        digonalrightTD(a1, awd[i], con, counter, value);
    }

    if (value == 'X') {
        auto end_time = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
        cout << "Time to solve = " << duration << " microseconds" << endl;
        cout << "Max word length = " << max << endl;
        cout << "Min word length = " << min << endl;
        cout << "Average word length = " << sum / x << endl;
    }

    return 0;
}
