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


    void solveMaze()
    {
    /*
    1. we check each current point's available direction
    and we store the number of the derictions available (empty space) and we deal
    with the number as the number of loops that should be done until we reach a wall block (#).
    then we get back to the other direction and so on..

    2. we move to the next position in the next loop and 
    then we once again do the same strategy 1 and then 2 and so on.

    3. if any of the sequance of the loops reach the 
    end point we break the loop.


    -- we start our current position from the start point.
    */

    basic_regex emptyPathPattern(" ");
    bool notreached = true;

    
    while(notreached)
    {
        int currentRowPosition = pointsPosition[0][0]; 
        int currentColumnPosition = pointsPosition[0][1]; 
        
        
        // top, right, bottom, left.
        string directions[] = {
            lines[currentRowPosition - 1][currentColumnPosition - 1], 
            lines[currentRowPosition][currentColumnPosition + 1], 
            lines[currentRowPosition + 1][currentColumnPosition + 1], 
            lines[currentRowPosition][currentColumnPosition - 1]
            };


        for(int directionsIndex = 0; directionsIndex < 4; directionsIndex++)
        {
            
        }
        
    }
    }


};