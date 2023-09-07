#include "helpers/index.cpp"


using namespace std;


class MazeSolver
{
    private:
    string pathToMazeFile;
    vector<string> lines;
    vector<Position> endPoints;

    public:
    MazeSolver() = delete;
    /*
    In the custom class constructor, we take the path to maze text file as (pathToMazeFile) 
    which is the maze that we want to solve, and get each line as a string in the vector (lines) 
    while we check for the end points a and b that should be solved and connected by a path 
    and we store them in the vector (endPoints) 
    */
    MazeSolver(string pathToMazeFile) : pathToMazeFile(pathToMazeFile)
    {
        fstream mazeFile(pathToMazeFile);
        // this patter for recognising the endpoints
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
    */
    vector<Position> queue;
    void solve()
    {
        vector<Position> path = {endPoints[0]};
        Position position = getLastPosition(path, path.size());
        
        if(path.size() > 1)
        {
            if (!isPositionsEqual(getLastPosition(path, path.size()), position))
            {
                path.push_back(position);
            }
        }
        
        vector<Position> directions = getDirections(position, lines);
        if(directions.size() > 1)
        {
            queue.push_back(position);
        }

        for(int i = 0; i < directions.size(); i++)
        {
            if (!directions[i].tried) 
            {
                // solve(directions[i]);
            }
        }

    }
};