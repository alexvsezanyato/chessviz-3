#include "Board.h"
#include "Move.h"
#include "gtest/gtest.h"

class BoardTest: public ::testing::Test
{
protected:

    void SetUp()
    {
        // ..
    }

    void TearDown()
    {
        // ..
    }

    Board board{};
};

TEST_F(BoardTest, MoveChess)
{
    short position[2] = {0, 0};
    char chess = board.board[position[0]][position[1]];
    short destination[2] = {5, 5};

    Move move;
    move.chess = chess;

    *(move.position + 0) = *(position + 0);
    *(move.position + 1) = *(position + 1);

    *(move.destination + 0) = *(destination + 0);
    *(move.destination + 1) = *(destination + 1);

    board.MoveChess(move);
    ASSERT_TRUE(board.board[destination[0]][destination[1]] == chess);
    ASSERT_TRUE(board.board[position[0]][position[1]] == '=');
}

TEST_F(BoardTest, TurnChessInto)
{
    short position[2] = {0, 0};
    char chess = board.board[position[0]][position[1]];
    short destination[2] = {5, 5};
    char turnedChess = 'Q';

    Move move;
    move.chess = chess;

    *(move.position + 0) = *(position + 0);
    *(move.position + 1) = *(position + 1);

    *(move.destination + 0) = *(destination + 0);
    *(move.destination + 1) = *(destination + 1);

    move.postfix = turnedChess;
    board.MoveChess(move);

    ASSERT_TRUE(board.board[destination[0]][destination[1]] == turnedChess);
    ASSERT_TRUE(board.board[position[0]][position[1]] == '=');
}

TEST_F(BoardTest, IsChess)
{
    ASSERT_TRUE(board.IsChess('K'));
    ASSERT_TRUE(board.IsChess('Q'));
    ASSERT_TRUE(board.IsChess('R'));
    ASSERT_TRUE(board.IsChess('N'));
    ASSERT_TRUE(board.IsChess('B'));
}