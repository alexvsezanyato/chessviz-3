#include "Moves.h"
#include "gtest/gtest.h"

TEST(MovesTest, ChessCharToShort)
{
    char symbols[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    for (int i = 0; i < 8; i++) {
        ASSERT_TRUE(Moves::ChessCtoi(symbols[i]) == i);
    }
}