#include "Board.h"

Board::Board() : x(8), y(8)
{
    board = new char * [x];
    for (short i = 0; i < x; i++) board[i] = new char [y];
    ArrangeChess();
}

Board::~Board()
{
    for (short i = 0; i < x; ++i) delete [] board[i];
    delete [] board;
}

void Board::ArrangeChess()
{
    char chess[] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};

    for (short i = 0; i < x; ++i)
    {
        board[0][i] = chess[i];
        board[7][i] = toupper(chess[i]);

        board[1][i] = 'p';
        board[6][i] = toupper('p');

        for (short j = 2; j <= 5; ++j) board[j][i] = '=';
    }
    return;
}