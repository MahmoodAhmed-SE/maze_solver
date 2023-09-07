#include <vector>
#include <string>


struct Position {
    int x;
    int y;
    bool tried = false;
    
    Position(){};
    Position(int x, int y) : x(x), y(y) {};
};

bool isPositionsEqual(Position p1, Position p2)
{
    if (p1.x == p2.x && p1.y == p2.y)
    {
        return true;
    }

    return false;
}

Position getLastPosition(std::vector<Position> path, int size)
{
    return path[size - 1];
}