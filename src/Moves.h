#pragma once

#include <vector>
#include <regex>
#include <string>
#include <fstream>
#include "Move.h"
// ..

class Moves
{
public:

	Moves(std::string path);
	bool Read();
	void ParseRegex(std::smatch* parts, Move* move1, Move* move2);
	Move At(short position);
	short Ctoi(char position);

	short count = 0;

private:

	std::ifstream stream;
	std::string path;
	std::vector<Move> moves;
};