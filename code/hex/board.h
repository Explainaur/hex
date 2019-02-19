#ifndef BOARD_H
#define BOARD_H 1

#ifndef POINT_H
#include "point.h"
#endif

#ifndef BOARD_SIZE
#define BOARD_SIZE 5
#endif

/**
 * @author Jason
 */
class Board
{
public:
  Board(COLOR first);

  void printBoard();

protected:
  COLOR current;

  void move(int x, int y);

private:
  Point board[BOARD_SIZE][BOARD_SIZE];
};

#endif
