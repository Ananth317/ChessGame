#include "Board.h"
#include <iostream>
#include <iomanip>

Board::Board() {
    grid.resize(8);
    for (auto& row : grid)
        row.resize(8);
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
    // Just a stub for now
    return false;
}