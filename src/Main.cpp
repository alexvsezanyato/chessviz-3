#include "Board.h"
#include "PlainBoardPrinter.h"
#include "Moves.h"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid command. ";
		std::cout << "First param must be data file name \n";
		return 1;
	}
	const std::string path = argv[1];
	Moves moves(path);

    Board board{};
    PlainBoardPrinter printer(&board);

    for (short i = 0; i < moves.count; ++i)
    {
    	Move move = moves.At(i);
		board.MoveChess(move.position, move.destination, move.postfix);

		std::cout << move.alias << "\n";
		std::cout << std::endl;

		printer.PrintBoard();
		std::cout << std::endl;
    }
	return 0;
}
