#include <fstream>
#include <vector>
#include <string>
#include <regex>

class MazeSolver
{
    private:

    public:
    MazeSolver(fstream *mazeFileStream, vector<string> *lines, int **pointsPosition);
    
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
    we check each current point's available directions
    we store the number of the derictions and we deal
    with them as the number of loops should be done
    we get to the next position in the next loop and 
    then we iterate the same strategy that we did
    if any of the sequance of the loops reache the 
    end point we break the loops.

    we start the current position with the start point.
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
}