Teleword Puzzle Solver
This Python program solves Teleword puzzles like those published in Dawn newspaper. A Teleword consists of a 15×15 letter grid and a list of hidden words placed horizontally, vertically, or diagonally — both forwards and backwards. The goal is to highlight all given words and reveal the hidden "Teleword" by reading the leftover letters row by row.

Features:
Reads puzzle input from teleword.txt (15x15 grid + word list).

Displays the grid and word list.

Offers 3 user options:

S - Solve puzzle instantly and color-code letter overlaps.

T - Solve step-by-step, revealing one word at a time.

X - Solve instantly and display detailed puzzle statistics.

Statistics Displayed:
Time to solve (excluding stats calculation)

Longest, shortest, and average word lengths

Word distribution (horizontal/vertical/diagonal and direction breakdown)

Teleword scatter (number of rows used in the final hidden word)

Heaviest row and column (most word overlaps)

