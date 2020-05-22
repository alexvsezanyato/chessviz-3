#pragma once

#include <string>
// ..

struct Move {
    short group = 0;
    char chess = ' ';
    short position[2];
    char type = '-';
    short destination[2];
    char postfix = ' ';
    std::string alias = "null";
};