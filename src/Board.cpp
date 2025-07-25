//
// Created by blueoranges on 7/10/25.
//

#include "../inc/Board.h"
#include "../inc/Pieces.h"
#include <iostream>
#include <cctype>


// TODO:: Add piece movement rules
// TODO:: Check for Check and Checkmate
// TODO:: Capture piece logic

// Function that prints the board onto the console
void Board::printBoard() {
    std::cout << std::endl;
    std::cout << "Chess Board:" << std::endl << std::endl;
    std::cout << "    A   B   C   D   E   F   G   H" << std::endl;

    for (int i = 8; i > 0; i--) {
        std::cout << i;
        for (int j = 0; j < 8; j++) {
            std::cout << " | ";
            std::cout << "" << board[8 - i][j];
        }
        std::cout << " | " << std::endl << std::endl;
    }
    std::cout << "    A   B   C   D   E   F   G   H" << std::endl;
    std::cout << std::endl;
}

// Set the player in play
void Board::setPlayer(Player player) {
    this->player = player;
}

//  Get the player piece to move and to new location
void Board::movePiece() {

    std::string startPosition;
    std::string endPosition;
    //  Extract the piece to be moved
    char piece = ' ';
    bool validMove = false;

    if (player == WHITE) {
        std::cout << "White Player" << std::endl;
        do {
            getMove(startPosition, endPosition);

            // Check if valid piece
            if (isupper(startPosition[0])) {
                validMove = true;
            }
            else {
                std::cout << "Not your piece. Try again. " << std::endl;
            }
        }while(!validMove);
        piece = startPosition[0];
        setPlayer(BLACK);
    }
    else if (player == BLACK) {
        std::cout << "Black Player" << std::endl;
        do {
            getMove(startPosition, endPosition);
            // Check if valid piece
            if (islower(startPosition[0])) {
                validMove = true;
            }
            else {
                std::cout << "Not your piece. Try again. " << std::endl;
            }
        }while(!validMove);
        piece = startPosition[0];
        setPlayer(WHITE);
    }
    // Extract row, and colum
    int col = startPosition[1] - 'a';
    int row = 8 - (startPosition[2] - '0');
    int newCol = endPosition[0] - 'a';
    int newRow = 8 - (endPosition[1] - '0');

    // Move piece
    board[newRow][newCol] = piece;
    board[row][col] = ' ';

}

// Get the piece and new placement indexes
void Board::getMove(std::string& startPosition, std::string& endPosition) {
    bool validInput = false;
    do {
        std::cout << "Enter piece to move: ";
        std::cin >> startPosition;
        std::cout << "Enter target location: ";
        std::cin >> endPosition;

        // Validate the size of the input to ensure is in correct format
        if (startPosition.length() < 3 || endPosition.length() < 2 || startPosition.length() > 3 || endPosition.length() > 2) {
            std::cout << "Not a valid formated input. (Ex. Pc4) " << std::endl;
        }
        else if (!isalpha(startPosition[0]) || !isalpha(endPosition[0]) || !isalpha(startPosition[1]) || !isdigit(startPosition[2]) || !isdigit(endPosition[1])) {
            std::cout << "Not a valid formated input. (Ex. Pc4) " << std::endl;
        }
        else {
            validInput = true;
        }

    }while (!validInput);
}

auto Board::getPlayer() {
    return player;
}
