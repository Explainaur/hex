#ifndef BOARD_H
#include "board.h"
#endif

#ifndef POINT_CPP
#include "point.cpp"
#endif

#ifndef _GLIBCXX_IOSTREAM
#include <iostream>
#endif

#ifndef _GLIBCXX_TR1_MATH_H
#include <math.h>
#endif

#ifndef _GLIBCXX_IOMANIP
#include <iomanip>
#endif

#ifndef _GLIBCXX_DEBUG_STRING
#include <string>
#endif

#define DEBUG_MODE true

Board::Board(COLOR first)
{
    current = first;

#if (DEBUG_MODE == true)
    if (first == WHITE)
        current = BLUE;
#endif
}

void Board::move(int x, int y)
{
#if (DEBUG_MODE == true)
    if (x > BOARD_SIZE || y > BOARD_SIZE)
    {
        std::cout << "out of range!" << std::endl;
        std::cout << "x = " << x << ", y = " << y << std::endl;
        std::cout << "-----------------------" << std::endl;
    }
#endif

    board[x][y].changeTo(current);
    // refresh the board
    current = (current == BLUE) ? RED : BLUE;
}

void Board::printBoard()
{
#if (DEBUG_MODE == false)
    std::cout << std::flush;
#endif

    std::string str = "\033[37m";
    std::string start = "";

    std::cout << "      \033[32m";
    for (int i = 0; i < BOARD_SIZE; i++)
        std::cout << std::setw(3) << i;
    std::cout << std::endl;

    for (int i = 0; i < BOARD_SIZE; i++)
    {
        start += " ";
        std::cout << "\033[33m" << i << "\t" << start;
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            switch (board[i][j].color)
            {
            case WHITE:
                str = "\033[37m";
                break;
            case RED:
                str = "\033[31m";
                break;
            case BLUE:
                str = "\033[34m";
                break;
            default:
                str = "\033[37m";
                break;
            }
            std::cout << str << "0\033[37m  ";
        }
        std::cout << std::endl;
    }
}