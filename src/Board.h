#pragma once

#include <vector>
#include <cctype>

class Board
{
public:

    Board();
    ~Board();

    bool MoveChess(short* from, short* to, char postfix);
    bool MoveChess(short* from, short* to);

    short x, y;
    char** board;

private:

    void ArrangeChess();
};