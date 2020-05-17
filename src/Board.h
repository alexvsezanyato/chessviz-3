#pragma once

#include <vector>
#include <cctype>
#include <iostream>

class Board
{
public:

    Board();
    ~Board();

    void Print();

private:

    void ArrangeChess();

    short x, y;
    char** board;
};