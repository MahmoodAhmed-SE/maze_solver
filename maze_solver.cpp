#include <fstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

struct Position {
    int x;
    int y;
    bool tried = false;
    
    Position(){};
    Position(int x, int y) : x(x), y(y) {};
};



class MazeSolver
{
    private:
    string pathToMazeFile;
    vector<string> lines;
    vector<Position> endPoints;

    public:
    MazeSolver() = delete;
    MazeSolver(string pathToMazeFile) : pathToMazeFile(pathToMazeFile)
    {
        fstream mazeFile;
        mazeFile.open(pathToMazeFile);
        
        regex pointPattern("[a-zA-Z]");


        int tempLineIndex = 0;
        string tempLine;
        while(getline(mazeFile, tempLine))
        {
            lines.push_back(tempLine);
            if (regex_search(tempLine, pointPattern))
            {
                for(int characterIndex = 0; characterIndex < tempLine.size() && endPoints.size() < 2; characterIndex++)
                {
                    if(regex_search(string(1, tempLine[characterIndex]), pointPattern))
                    {
                        Position point = Position(characterIndex, tempLineIndex);
                        endPoints.push_back(point); 
                    }

                    if(endPoints.size() == 2)
                    {
                        break;
                    }
                }
            } 

            tempLineIndex++;
        }

        
        
        mazeFile.close();
    }
    
    
    /*
    path == queue
    specific direction
    int loopPositionStartedPlusHowManyAvailab

    for  
    
    
    */
    bool isWall(Position p)
    {
        if(lines[p.y][p.x] == '#')
        {
            return true;
        } 
        else 
        {
            return false;
        }
    }

    bool isPositionsEqual(Position p1, Position p2)
    {
        if (p1.x == p2.x && p1.y == p2.y)
        {
            return true;
        }

        return false;
    }

    vector<Position> getDirections(Position pos)
    {
        vector<Position> directions;

        Position top = Position(pos.x, pos.y - 1);
        Position right = Position(pos.x + 1, pos.y);
        Position bottom = Position(pos.x, pos.y + 1);
        Position left = Position(pos.x - 1, pos.y);
        
        if(!isWall(top))
        {
            directions.push_back(top);
        }
        if(!isWall(right))
        {
            directions.push_back(right);
        }
        if(!isWall(bottom))
        {
            directions.push_back(bottom);
        }
        if(!isWall(left))
        {
            directions.push_back(left);
        }
        
        return directions;
    }
    
    Position getLastPosition(vector<Position> path)
    {
        return path[path.size() - 1];
    }

    vector<Position> path = {endPoints[0]};
    void solve(Position direction = Position(-5, -5))
    {
        if (direction.x == -5)
        {
            direction = getLastPosition(path);
        }
        
        if(path.size() > 1)
        {
            if (!isPositionsEqual(getLastPosition(path), direction))
            {
                path.push_back(direction);
            }
        }

        vector<Position> directions = getDirections(direction);
        
        for(Position direction : directions)
        {

            if(isPositionsEqual(direction, endPoints[1]))
            {
                cout << "solved";
                break;
            }

            solve(direction);
        }

    }
};