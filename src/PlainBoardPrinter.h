#pragma once

#include <iostream>
#include "Board.h"
// ..

class PlainBoardPrinter
{
public:

	PlainBoardPrinter(Board* board);
	void Print();

private:

	Board* board;
};