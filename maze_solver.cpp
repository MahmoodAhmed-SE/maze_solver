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
                        Position point;
                        point.y = characterIndex;
                        point.x = tempLineIndex;
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
    
    void solve()
    {

    }
};