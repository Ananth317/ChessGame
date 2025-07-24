#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(Color c) : Piece(c, (c == Color::WHITE) ? 'P' : 'p') {};
    
    bool isValidMove(const Position& from, const Position& to, const Board& board) const override;
};

#endif // PAWN_H
