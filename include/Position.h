#ifndef POSITION_H
#define POSITION_H

struct Position {
    int row, column;

    Position(int r = 0, int c = 0) : row(r), column(c) {}
};

#endif // POSITION_H
