#include <iostream>
#include <iomanip>
#include "Board.h"
#include "Pawn.h"

Board::Board() 
: currentTurn(Color::WHITE) {
    grid.resize(8);
    for (auto& row : grid)
        row.resize(8);
    // Place white pawns
    for (int col = 0; col < 8; ++col) {
        grid[6][col] = std::make_unique<Pawn>(Color::WHITE);
    }

    // Place black pawns
    for (int col = 0; col < 8; ++col) {
        grid[1][col] = std::make_unique<Pawn>(Color::BLACK);
    }
}

void Board::display() const {
    std::cout << "  a b c d e f g h\n";
    for (int row = 0; row < 8; ++row) {
        std::cout << 8 - row << " ";
        for (int col = 0; col < 8; ++col) {
            const Piece* piece = grid[row][col].get();
            if (piece)
                std::cout << piece->getSymbol() << " ";
            else
                std::cout << ". ";
        }
        std::cout << 8 - row << "\n";
    }
    std::cout << "  a b c d e f g h\n";
}

const Piece* Board::getPieceAt(const Position& pos) const {
    return grid[pos.row][pos.column].get();
}

bool Board::movePiece(const Position& from, const Position& to) {
    auto& piece = grid[from.row][from.column];
    if(!piece) {
        return false;
    }

    if(piece->getColor() != currentTurn) {
        return false; // Not the player's turn
    }

    if(!piece->isValidMove(from, to, *this)) {
        return false; // Invalid move according to piece rules
    }

    grid[to.row][to.column] = std::move(piece); // Move the piece
    currentTurn = (currentTurn == Color::WHITE) ? Color::BLACK : Color::WHITE; // Switch turns
    return true; // Move successful
}