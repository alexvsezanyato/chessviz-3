#pragma once

#include "Move.h"
#include <fstream>
#include <regex>
#include <string>
#include <vector>
// ..

class Moves {
public:
    Moves(std::string path);
    bool Read();
    void ParseRegex(std::smatch* parts, Move* move1, Move* move2);
    Move At(short position);
    static short ChessCtoi(char position);

    short count = 0;

private:
    std::ifstream stream;
    std::string path;
    std::vector<Move> moves;
};