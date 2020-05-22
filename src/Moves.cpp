#include "Moves.h"
#include "Move.h"
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
// ..

short Moves::ChessCtoi(char position)
{
    switch (position) {
    case 'a':
        return 0;
    case 'b':
        return 1;
    case 'c':
        return 2;
    case 'd':
        return 3;
    case 'e':
        return 4;
    case 'f':
        return 5;
    case 'g':
        return 6;
    case 'h':
        return 7;
    default:
        return 0;
    }
}

void Moves::ParseRegex(std::smatch* parts, Move* move1, Move* move2)
{
    move1->group = std::stoi(parts->str(1));
    move1->alias = parts->str(1) + ". " + parts->str(2);
    if (parts->str(3).size())
        move1->chess = parts->str(3).at(0);

    move1->position[1] = Moves::ChessCtoi(parts->str(4).at(0));
    move1->position[0] = 8 - std::stoi(parts->str(5));
    move1->type = parts->str(6).at(0);
    move1->destination[1] = Moves::ChessCtoi(parts->str(7).at(0));
    move1->destination[0] = 8 - std::stoi(parts->str(8));
    if (parts->str(9).size())
        move1->postfix = parts->str(9).at(0);

    if (!parts->str(10).size())
        return;
    // ..

    move2->group = std::stoi(parts->str(1));
    move2->alias = parts->str(1) + ". " + parts->str(10);
    if (parts->str(11).size())
        move1->chess = parts->str(11).at(0);

    move2->position[1] = Moves::ChessCtoi(parts->str(12).at(0));
    move2->position[0] = 8 - std::stoi(parts->str(13));
    move2->type = parts->str(14).at(0);
    move2->destination[1] = Moves::ChessCtoi(parts->str(15).at(0));
    move2->destination[0] = 8 - std::stoi(parts->str(16));
    if (parts->str(17).size())
        move2->postfix = parts->str(17).at(0);
}

bool Moves::Read()
{
    std::string buffer;
    // ..

    while (std::getline(stream, buffer)) {
        std::string regmv
                = "([K, Q, R, B, N])?([a-h])([1-8])([-,x])([a-h])([1-8])([K, "
                  "Q, R, B, N, #, +]?)";
        std::regex regex("([1-9]+). (" + regmv + ")( " + regmv + ")?");
        std::smatch parts;

        if (std::regex_match(buffer, parts, regex)) {
            Move move1, move2;
            ParseRegex(&parts, &move1, &move2);
            moves.push_back(move1), count++;
            if (move2.alias != "null")
                moves.push_back(move2), count++;
        } else
            return false;
    }
    return true;
}

Move Moves::At(short position)
{
    return moves.at(position);
}

Moves::Moves(std::string path)
{
    this->path = path;
    stream.open(path);

    if (stream) {
        if (!Read())
            std::cout << "Invalid input data \n";
        stream.close();
    } else
        std::cout << "Can't open file \"" << path << "\"\n";
}