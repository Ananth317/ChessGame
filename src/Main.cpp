#include <string>
#include <windows.h>
#include <iostream>
#include "Board.h"

void clearConsole() {
    system("cls");
}

Position parseInput(const std::string& input) {
    if (input.length() != 2) {
        return Position(-1, -1); // Invalid input
    }

    char file = tolower(input[0]);
    char rank = input[1];
    if (file < 'a' || file > 'h' || rank < '1' || rank > '8') {
        return Position(-1, -1); // Invalid input
    }

    int column = file - 'a';
    int row = 8 - (rank - '0'); // Convert rank to row index
    return Position(row, column);
}    

int main() {
    std::string fromString, toString;
    
    Board board;
    
    while(true) {
        clearConsole();
        board.display();

        std::cout << (board.getCurrentTurn() == Color::WHITE ? "White" : "Black") << "'s move: ";
        std::cout << "Enter move: ";
        std::cin >> fromString >> toString;

        Position from = parseInput(fromString);
        Position to = parseInput(toString);
        if(from.row == -1 || to.row == -1) {
            std::cout << "Invalid input. Please enter moves in the format 'e2 e4'." << std::endl;
            continue;
        }
        if(!board.movePiece(from, to)) {
            std::cout << "Invalid move.\n";
            std::cin.ignore();
            std::cin.get(); // Pause so player can see error
        }
    }
    return 0;
}