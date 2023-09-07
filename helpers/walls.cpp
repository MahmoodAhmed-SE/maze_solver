#include <vector>
#include <string>

using namespace std;

bool isWall(Position p, vector<string> lines)
{
    bool checkthis = lines[p.y][p.x] == '#';
    if(lines[p.y][p.x] == '#')
    {
        return true;
    } 
    else 
    {
        return false;
    }
}

vector<Position> getDirections(Position pos, vector<string> lines)
{
    vector<Position> directions;

    Position top = Position(pos.x, pos.y - 1);
    Position right = Position(pos.x + 1, pos.y);
    Position bottom = Position(pos.x, pos.y + 1);
    Position left = Position(pos.x - 1, pos.y);
    
    if(!isWall(top, lines) && !top.tried)
    {
        directions.push_back(top);
    }
    if(!isWall(right, lines) && !right.tried)
    {
        directions.push_back(right);
    }
    if(!isWall(bottom, lines) && !bottom.tried)
    {
        directions.push_back(bottom);
    }
    if(!isWall(left, lines) && !left.tried)
    {
        directions.push_back(left);
    }
    
    return directions;
}