#include "Board.h"
#include <iostream>

bool IsChess(char symbol)
{
    switch (symbol) {
    case 'K':
    case 'Q':
    case 'R':
    case 'B':
    case 'N':
        return true;
    default:
        return false;
    }
}

Board::Board() : x(8), y(8)
{
    board = new char*[x];
    for (short i = 0; i < x; i++)
        board[i] = new char[y];
    ArrangeChess();
}

Board::~Board()
{
    for (short i = 0; i < x; ++i)
        delete[] board[i];
    delete[] board;
}

void Board::ArrangeChess()
{
    char chess[] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};

    for (short i = 0; i < x; ++i) {
        board[0][i] = chess[i];
        board[7][i] = toupper(chess[i]);

        board[1][i] = 'p';
        board[6][i] = toupper('p');

        for (short j = 2; j <= 5; ++j)
            board[j][i] = '=';
    }
    return;
}

bool Board::MoveChess(Move move)
{
    short* from = move.position;
    short* to = move.destination;

    if (from[0] >= x || from[0] < 0)
        if (from[1] >= y || from[1] < 0)
            return false;

    if (to[0] >= x || to[0] < 0)
        if (to[1] >= y || to[1] < 0)
            return false;

    if (IsChess(move.chess))
        if (move.chess != board[from[0]][from[1]])
            return false;

    if (board[from[0]][from[1]] == '=')
        return false;

    if (IsChess(move.postfix)) {
        board[to[0]][to[1]] = move.postfix;
        board[from[0]][from[1]] = '=';
    } else {
        board[to[0]][to[1]] = board[from[0]][from[1]];
        board[from[0]][from[1]] = '=';
    }
    return true;
}