#include "Pawn.h"
#include "Board.h"

bool Pawn::isValidMove(const Position& from, const Position& to, const Board& board) const {
    int direction = (color == Color::WHITE) ? -1 : 1; // White moves up, Black moves down
    int startRow = (color == Color::WHITE) ? 6 : 1; // Starting row for pawns

    // Move forward by 1
    if (to.column == from.column && to.row == from.row + direction && !board.getPieceAt(to)) {
        return true;
    }

    // Move forward by 2 from starting position
    if (to.column == from.column &&
        from.row == startRow &&
        to.row == from.row + 2 * direction &&
        !board.getPieceAt(to) &&
        !board.getPieceAt({from.row + direction, from.column})) {
        return true;
    }

    // (We'll add diagonal capture logic later)
    return false;
}
