#include "board.cpp"

#ifndef _GLIBCXX_DEBUG_SET
#include <set>
#endif

class Robot : Board
{
  public:
    Robot(COLOR first, COLOR s);
    void take(int x, int y);
    void printBoard();

  protected:
    double trend[3];
    double energy[3];
    std::set<std::pair<int, int>> clusters[3];

  private:
    COLOR self;
    double weight[BOARD_SIZE][BOARD_SIZE];
    void generateMove();
};

/**
 * Initialize
 * @author Jason
 * 
 * @param COLOR first to play
 * @param COLOR color of robot
 * @return NULL
 */
Robot::Robot(COLOR first, COLOR s) : Board(first)
{
    self = s;

    energy[BLUE] = INFINITY;
    energy[RED] = INFINITY;

    clusters[BLUE] = {};
    clusters[RED] = {};

    trend[BLUE] = INFINITY;
    trend[RED] = INFINITY;

    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            weight[i][j] = INFINITY;

#if (DEBUG_MODE == true)
    if (s == WHITE)
        self = BLUE;

    std::string str = (first == BLUE) ? "\033[34mBLUE\033[37m" : "\033[31mRED\033[37m";

    std::cout << "Robot initialized, ";
    std::cout << str << " plays first!" << std::endl;

    str = (self == BLUE) ? "\033[34mBLUE\033[37m" : "\033[31mRED\033[37m";

    std::cout << "Robot plays the role of " << str << ", good luck!" << std::endl
              << std::endl;
#endif

    if (self == current)
        generateMove();
};

/**
 * @author Jason
 * 
 * @param int x
 * @param int y
 * @return NULL
 */
void Robot::take(int x, int y)
{
    Board::move(x, y);

#if (DEBUG_MODE == true)
    if (self != current)
        return;
#endif

    generateMove();

#if (DEBUG_MODE == true)
    std::cout << "trend = " << exp(trend[self] / trend[current]) << std::endl;
#endif
};

/**
 * Generate a best move
 * 
 * @return NULL
 */
void Robot::generateMove()
{
    int x = -1, y = -1;
    std::set<std::pair<int, int>> points;

    // refresh energy
    // generate allowable points
    // calculate weight of the points

    // print the best choise
    std::cout << x << " " << y << std::endl
              << std::endl;
    Board::move(x, y);
}

void Robot::printBoard()
{
    Board::printBoard();
}
