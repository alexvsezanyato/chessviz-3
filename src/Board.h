#pragma once

#include <cctype>
#include <vector>
#include "Move.h"

class Board {
public:
    Board();
    ~Board();

    bool MoveChess(Move move);

    short x, y;
    char** board;

private:
    void ArrangeChess();
};