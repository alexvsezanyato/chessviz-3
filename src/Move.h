#pragma once

struct Move {
    short group;
    short position[2];
    char type;
    short destination[2];
    char postfix = ' ';
    std::string alias = "null";
};