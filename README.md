# CS501 HW2

### Author: Deepshan Adhikari
### Email: deepadh@siue.edu
### Student ID: 800846035

---

### Project Description
- This is a C++ program that solves the Knight's Tour problem using a backtracking algorithm.
- The Knight's Tour is a chess puzzle where a knight must visit every square on an N×N chessboard exactly once.
- The program allows users to specify the board size, starting position, and number of solutions to find.
- All found solutions are written to an output file (knightsTour.out) with formatted board displays.

---

### Features
The program provides the following functionalities:
1. **Custom Board Size:** Allows users to specify chessboard dimensions from 4×4 to 8×8.
2. **Flexible Starting Position:** Users can choose any valid starting position for the knight on the board.
3. **Multiple Solutions:** Finds and displays multiple complete Knight's Tour solutions (up to 100).
4. **Input Validation:** Validates all user inputs for board size, position format, and solution count.
5. **Formatted Output:** Generates clean, aligned output showing the knight's move sequence on the board.
6. **File Output:** Saves all solutions to a text file with proper formatting and numbering.
7. **Backtracking Algorithm:** Uses efficient recursion with backtracking to explore all possible paths.

---

### Algorithm & Data Structures
The program uses a backtracking algorithm (depth-first search) to systematically explore all possible knight moves:
- **3D Vector Structure:** std::vector<std::vector<std::vector<int>>> stores multiple solutions, where each solution is a 2D board of integers representing move sequences.
- **Knight Moves:** Pre-defined set of 8 possible L-shaped moves stored as coordinate pairs.
- **Recursive Backtracking:** The solveTour() function recursively explores paths, backtracks when dead ends are reached, and collects complete solutions.
- **Validation:** The isValidMove() function ensures moves stay within bounds and visit unvisited squares.

---

### Project Structure:
```
HW2/
 ├--knightsTour
      ├-- knightsTour.cpp   // implementation of Knight's Tour
      ├-- knightsTour.h    // header file with class definition for knightsTour.cpp
 ├-- knightsTour.out      // output file (generated at runtime)
 ├-- main.cpp            // main program with user interface
```
---

### How to Compile and Run
This program is designed to be compiled and run using **CLion IDE**. But can also be use in **VSCode**.
1. Open the project in CLion or VSCode.
2. Click on green play button on top of main.cpp file to run the code.
3. Click on red stop button to terminate the process.

### Output Format
Each solution in the output file shows:
- Move numbers in sequential order (1 to N×N)
- Proper alignment for single, double, and triple-digit numbers
- Clear grid representation of the knight's path
- Solution numbering and summary statistics

```
Example Output Snippet:

Solution 1:
1   4   7   10
12  9   2   5
3   6   11  8
13  16  15  14  
```