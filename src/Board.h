#pragma once

#include "Move.h"
#include <cctype>
#include <vector>

class Board {
public:
    Board();
    ~Board();

    bool MoveChess(Move move);
    bool IsChess(char symbol);

    short x, y;
    char** board;

private:
    void ArrangeChess();
};