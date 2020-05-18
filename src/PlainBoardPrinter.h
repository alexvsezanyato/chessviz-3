#pragma once

#include <iostream>
#include "Board.h"
// ..

class PlainBoardPrinter
{
public:

	PlainBoardPrinter(Board* board);
	void PrintBoard();

private:

	Board* board;
};