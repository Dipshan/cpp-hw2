// File: knightsTour.cpp
// This file implements the KnightsTour class methods: constructor, solver, and board formatter.

#include <iostream> // for standard input and output streams
#include "knightsTour.h"

// Constructor implementation
KnightsTour::KnightsTour(int boardSize, int startRow, int startCol)
    : boardSize(boardSize), startRow(startRow), startCol(startCol) {
}

// Find Knight's Tour solutions up to @param numSolutions
KnightsTour::Solutions KnightsTour::findSolutions(int numSolutions) {
    // Store all solutions
    Solutions solutions;

    // Create empty board filled with zeros
    Board board(boardSize, std::vector<int>(boardSize, 0));

    // Mark starting position as first move
    board[startRow][startCol] = 1;

    // Start recursive search from starting position
    solveTour(board, startRow, startCol, 2, solutions, numSolutions);

    return solutions; // Return found solutions
}

// Recursive function to solve knight's tour
void KnightsTour::solveTour(std::vector<std::vector<int> > &board, int row, int col, int moveCount,
                            std::vector<std::vector<std::vector<int> > > &solutions, int maxSolutions) {
    // Stop if enough solutions found
    if (solutions.size() >= maxSolutions) return;

    // Complete solution when all squares visited
    if (moveCount > boardSize * boardSize) {
        solutions.push_back(board); // Save solution
        return;
    }

    // Try all 8 possible knight moves
    for (const auto &move: moves) {
        int newRow = row + move.first; // Calculate new row
        int newCol = col + move.second; // Calculate new column

        // Check if move is valid
        if (isValidMove(board, newRow, newCol)) {
            board[newRow][newCol] = moveCount; // Mark square with move number

            // Recursively try next move
            solveTour(board, newRow, newCol, moveCount + 1, solutions, maxSolutions);

            board[newRow][newCol] = 0; // Backtrack (undo move)
        }
    }
}

// Convert solution board to string for display
std::string KnightsTour::solutionToString(const std::vector<std::vector<int> > &solution) {
    std::string result; // String to build output
    int size = solution.size(); // Board size

    // Loop through each row
    for (int i = 0; i < size; i++) {
        // Loop through each column in row
        for (int j = 0; j < size; j++) {
            // Add number with spacing for alignment
            if (solution[i][j] < 10) {
                result += std::to_string(solution[i][j]) + "   "; // 3 spaces for single digit
            } else if (solution[i][j] < 100) {
                result += std::to_string(solution[i][j]) + "  "; // 2 spaces for double-digit
            } else {
                result += std::to_string(solution[i][j]) + " "; // 1 space for triple digit
            }
        }
        result += "\n";
    }

    return result;
}
