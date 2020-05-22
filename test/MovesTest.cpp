#include "../src/Moves.h"
#include "gtest/gtest.h"

TEST(MovesTest, ChessCharToShort)
{
    Moves moves("Data");
    ASSERT_TRUE(moves.Ctoi('a') == 0);
    ASSERT_TRUE(moves.Ctoi('b') == 1);
    ASSERT_TRUE(moves.Ctoi('c') == 2);
    ASSERT_TRUE(moves.Ctoi('d') == 3);
    ASSERT_TRUE(moves.Ctoi('e') == 4);
    ASSERT_TRUE(moves.Ctoi('f') == 5);
    ASSERT_TRUE(moves.Ctoi('g') == 6);
    ASSERT_TRUE(moves.Ctoi('h') == 7);
}