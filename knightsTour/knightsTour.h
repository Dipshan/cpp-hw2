// File: knightsTour.h
// This file defines the KnightsTour class for solving the Knight's Tour problem using backtracking

#ifndef KNIGHTSTOUR_H
#define KNIGHTSTOUR_H

#include <string> // defines the std::string class, used for handling text data
#include <vector> // defines the std::vector class, a dynamic array that can grow or shrink in size
#include <utility> // defines std::pair, used for knight move offsets

// Class to solve Knight's Tour problem on an N x N chessboard
class KnightsTour {
public:
    // Alias for a chessboard (2D vector of ints)
    using Board = std::vector<std::vector<int> >;

    // Alias for a collection of solutions (vector of boards)
    using Solutions = std::vector<Board>;

    // Constructor to initialize board and starting position
    // @param boardSize The size of the chess board (N x N)
    // @param startRow The starting row position for the knight (0-indexed)
    // @param startCol The starting column position for the knight (0-indexed)
    KnightsTour(int boardSize, int startRow, int startCol);

    // Finds the specified number of complete Knight's Tour solutions
    // @param numSolutions The maximum number of solutions to find
    // @return A vector of solutions, where each solution is a 2D board
    [[nodiscard]] Solutions findSolutions(int numSolutions);

    // Converts a solution board to a printable string representation
    // @param solution A 2D vector representing a single Knight's Tour solution
    // @return A formatted string showing the board with move numbers
    static std::string solutionToString(const Board &solution);

private:
    int boardSize; // Size of chess board (N x N)
    int startRow; // Starting row position (0-indexed)
    int startCol; // Starting column position (0-indexed)

    // All 8 possible Knight moves from a point as (deltaRow, deltaColumn) pairs
    static constexpr std::pair<int, int> moves[8] = {
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, // Right/down moves
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1} // Left/up moves
    };

    // Recursive function to find Knight's Tour solutions using backtracking
    // @param board The current state of the chess board
    // @param row The current row position of the knight
    // @param col The current column position of the knight
    // @param moveCount The current move number (starts at 1)
    // @param solutions Reference to the vector collecting all found solutions
    // @param maxSolutions The maximum number of solutions to collect
    void solveTour(Board &board, int row, int col, int moveCount,
                   Solutions &solutions, int maxSolutions);

    // Checks if a move to the given position is valid
    // @param board The current state of the chess board
    // @param row The target row position to check
    // @param col The target column position to check
    // @return True if the move is within bounds and the square is unvisited, false otherwise
    [[nodiscard]] inline bool isValidMove(const Board &board, int row, int col) const {
        return row >= 0 && row < boardSize &&
               col >= 0 && col < boardSize &&
               board[row][col] == 0;
    }
};

#endif
