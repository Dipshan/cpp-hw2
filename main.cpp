// File: main.cpp
// Description:
// - Entry point of the application.
// - This is a C++ program that solves the Knight's Tour problem using a backtracking algorithm.
// - The program allows users to specify the board size, starting position, and number of solutions to find.

#include <fstream> // for file input and output operations
#include <iostream> // for standard input and output streams
#include <string> // defines the std::string class, which is used for handling text data
#include <vector> // defines the std::vector class, a dynamic array that can grow or shrink in size
#include <sstream> // for string stream processing (istringstream)
#include <limits> // for numeric limits (streamsize)
#include "knightsTour/knightsTour.h"

// Get validated integer input from user within specified range
// @param prompt The message to display to the user
// @param min The minimum acceptable value
// @param max The maximum acceptable value
// @return A validated integer input from the user
int getInt(const std::string &prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt; // Display prompt to user
        // Check if input is valid integer and within specified range
        if (std::cin >> value && value >= min && value <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
            return value; // Return valid input
        }
        // Clear invalid input and display error message
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter a number between " << min << " and " << max << ".\n";
    }
}

// Get and validate starting position input from user
// @param boardSize The size of the board for validation
// @param row Reference to store the validated row position (1-indexed)
// @param col Reference to store the validated column position (1-indexed)
void getStartPosition(int boardSize, int &row, int &col) {
    std::string input; // Store user input as string

    while (true) {
        std::cout << "Enter initial location (row, column): ";
        std::getline(std::cin, input); // Read entire line of input

        std::istringstream ss(input); // Create string stream for parsing
        char comma; // To check for comma separator

        // Validate input format (two integers separated by comma) and value range
        if (ss >> row >> comma >> col && comma == ',' &&
            row >= 1 && row <= boardSize &&
            col >= 1 && col <= boardSize) {
            return; // Input is valid, exit loop
        }
        std::cout << "Invalid format. Use: row,column (e.g., 1,2)\n";
    }
}

// Main program function - entry point of the application
int main() {
    std::cout << "Knight's Tour" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    // Get board size from user (4-8)
    int boardSize = getInt("Enter board size (4-8): ", 4, 8);

    // Get number of solutions to find (1-100)
    int numSolutions = getInt("Enter number of solutions (1-100): ", 1, 100);

    int startRow, startCol;
    // Get starting position from user (1-indexed)
    getStartPosition(boardSize, startRow, startCol);

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "Solving for " << numSolutions << " solutions on a " << boardSize
            << "x" << boardSize << " board starting at (" << startRow << ", " << startCol << ")...\n";

    // Create knight's tour solver instance (convert to 0-indexed for internal use)
    KnightsTour tour(boardSize, startRow - 1, startCol - 1);
    // Find requested number of solutions using backtracking algorithm
    auto solutions = tour.findSolutions(numSolutions);

    // Open output file for writing results
    std::ofstream outFile("../knightsTour.out");
    if (!outFile) {
        std::cerr << "Could not create output file!" << std::endl;
        return 1; // Exit with error code if file creation fails
    }

    // Write solution summary to file
    outFile << "Found " << solutions.size() << " solutions for a " << boardSize
            << "x" << boardSize << " board starting at ("
            << startRow << ", " << startCol << ")\n\n";

    // Write each solution to file with proper formatting
    for (size_t i = 0; i < solutions.size(); ++i) {
        outFile << "Solution " << i + 1 << ":\n"
                << KnightsTour::solutionToString(solutions[i]) << std::endl;
    }

    std::cout << solutions.size() << " solutions written to knightsTour.out\n";
    return 0;
}
