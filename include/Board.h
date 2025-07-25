#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include "Piece.h"

class Board {
private:
    Color currentTurn;
    std::vector<std::vector<std::unique_ptr<Piece>>> grid;
    
public:
    Board();

    void display() const;
    Color getCurrentTurn() const {
        return currentTurn;
    }
    bool movePiece(const Position& from, const Position& to);
    const Piece* getPieceAt(const Position& pos) const;
};

#endif // BOARD_H
