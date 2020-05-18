#include "Board.h"
#include "PlainBoardPrinter.h"

int main(int argc, char *argv[])
{
    Board board{};
    PlainBoardPrinter printer(&board);
    printer.Print();
	return 0;
}
