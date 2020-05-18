#include "PlainBoardPrinter.h"

PlainBoardPrinter::PlainBoardPrinter(Board* board)
{
	this->board = board;
}

void PlainBoardPrinter::Print()
{
    for (short i = 0; i < board->x; i++)
    {
        for (short j = 0; j < board->y; j++) std::cout << board->board[i][j] << ' ';
        std::cout << std::endl;
    }
    return;
}