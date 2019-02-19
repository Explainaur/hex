#include "hex/robot.hpp"

int main()
{
    COLOR color;
    char c;

    std::cout << "Please input the role of robot:[b/r] >";
    std::cin >> c;
    color = (c == 'b') ? BLUE : RED;

    Robot *robot = new Robot(RED, color);

    int x, y;
    while (true)
    {
        robot->printBoard();

        std::cout << "Please input the point:[x y] >";
//        std::cin >> x >> y;
        x = getchar();
        y = getchar();
        robot->take((int)x, (int)y);
    }
    return 0;
}
