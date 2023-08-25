#include <fstream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

class MazeSolver
{
    private:
    fstream *mazeFileStream;
    vector<string> *lines;
    int **pointsPosition;
    
    // Maze starting points. \note   [row, column] 
    int startPointPosition[2] = {pointsPosition[0][0], pointsPosition[0][1]};

    /*
    We store the points [row, column] of (empty space) path that we come into in this vector. 
    This enables us to track where our position at in the maze.
    */ 
    vector<int[2]> pathPoints;

    public:
    MazeSolver() = delete;
    MazeSolver(fstream *mazeFileStream, vector<string> *lines, int **pointsPosition) 
        : mazeFileStream(mazeFileStream), lines(lines), pointsPosition(pointsPosition) {};
        
    void getPosAndLines()
    {
        basic_regex pointRecoginationPattern("[a-zA-Z]");
        int pointIndex = 0;
        int lineIndex = 0;
        string tempLine;

        
        /*
        Adding string line by string line into "lines" vector pointer. 
        Simealtaniously, scanning for start and end points of the maze into the vector 
        pointer's pointer "pointsPosition" 
        */
        while (getline(*mazeFileStream, tempLine))
        {
            lines->push_back(tempLine);
            
            if(regex_search(tempLine, pointRecoginationPattern))
            {
                for(int index = 0; index < tempLine.length() && pointIndex < 2; index++)
                {
                    if(regex_search(string(1, tempLine[index]), pointRecoginationPattern))
                    {
                        pointsPosition[pointIndex][0] = lineIndex;
                        pointsPosition[pointIndex][1] = index;
                        pointIndex++;
                    }
                }
            };
            

            lineIndex++;
        }
    }


    /*
    1. we check each current point's available direction
    and we store the number of the derictions available (empty space) and we deal
    with the number as the number of loops that should be done until we reach a wall block (#).
    then we get back to the other direction and so on..
    
    2. we move to the next position in the next loop and 
    then we once again do the same strategy 1 and then 2 and so on.
    
    3. if any of the sequance of the loops reach the 
    end point we break the loop.
    
    we start our current position from the start point.
    */
    void solveMaze()
    {

        basic_regex emptyPathPattern(" ");
        
        int currentPosition[2] = {startPointPosition[0], startPointPosition[1]};
        
        int top[2], left[2], bottom[2], right[2]; 
        
        if (1 < currentPosition[0]){
            top[0] = currentPosition[0] - 1;
            top[1] = currentPosition[1];
        } 
        if (currentPosition[0] < (*lines).size()){
            bottom[0] = currentPosition[0] + 1;
            bottom[1] = currentPosition[1];
        }
        if (1 < currentPosition[1]){
            left[0] = currentPosition[0];
            left[1] = currentPosition[1] - 1;
        }
        if (currentPosition[1] < (*lines).size()){
            right[0] = currentPosition[0];
            right[1] = currentPosition[1] + 1;
        }
        
        int *directions[4] = {top, right, bottom, left};

        bool isReached = false;
        while(!isReached)
        {
            
        }
        
    
    }


};