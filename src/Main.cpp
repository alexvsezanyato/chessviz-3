#include "Board.h"
#include "Moves.h"
#include "PlainBoardPrinter.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "Invalid command. ";
        std::cout << "First param must be data file name \n";
        return 1;
    }
    const std::string path = argv[1];
    Moves moves(path);

    Board board{};
    PlainBoardPrinter printer(&board);

    for (short i = 0; i < moves.count; ++i) {
        Move move = moves.At(i);

        std::cout << move.alias << "\n";
        if (!board.MoveChess(move)) {
            std::cout << "Can't move chess \n";
            return 1;
        }
        std::cout << std::endl;

        printer.PrintBoard();
        std::cout << std::endl;
    }
    return 0;
}
