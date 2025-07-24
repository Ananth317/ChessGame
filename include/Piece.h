#ifndef PIECE_H
#define PIECE_H

#include "Position.h"

enum class Color {
    WHITE,
    BLACK
};

class Board;

class Piece {
protected:
    Color color;
    char symbol;

public:
    Piece(Color c, char s) : color(c), symbol(s) {}
    virtual ~Piece() {}

    Color getColor() const {
        return color;
    }

    char getSymbol() const {
        return symbol;
    }

    virtual bool isValidMove(const Position& from, const Position& to, const Board& board) const = 0;
};
#endif // PIECE_H
