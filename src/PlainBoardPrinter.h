#pragma once

#include "Board.h"
#include <iostream>
// ..

class PlainBoardPrinter {
public:
    PlainBoardPrinter(Board* board);
    void PrintBoard();

private:
    Board* board;
};