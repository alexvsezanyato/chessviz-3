#pragma once

#include <vector>
#include <cctype>

class Board
{
public:

    Board();
    ~Board();

    short x, y;
    char** board;

private:

    void ArrangeChess();
};