#include "PlainBoardPrinter.h"

PlainBoardPrinter::PlainBoardPrinter(Board* board)
{
    this->board = board;
}

void PlainBoardPrinter::PrintBoard()
{
    for (short i = 0; i < board->x; i++) {
        std::cout << (board->x - i) << ' ';
        for (short j = 0; j < board->y; j++)
            std::cout << board->board[i][j] << ' ';
        std::cout << std::endl;
    }
    std::cout << "  ";
    for (short i = 0; i < board->y; i++)
        std::cout << (char)('a' + (char)i) << ' ';
    std::cout << std::endl;
    return;
}