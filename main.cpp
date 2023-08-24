#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>


using namespace std;

int** create2DArray(int rows, int cols) {
    int** array = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }
    return array;
}

void delete2DArray(int** array, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

void getPosAndLines(fstream *mazeFileStream, vector<string> *lines, int **pointsPosition)
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

int main(void)
{   
    // initiating and opening maze text file.
    fstream *mazeFileStream = new fstream;
    (*mazeFileStream).open("./example.txt");
    
    vector<string> *lines = new vector<string>;

    /*
        Maze start point line index is at [0][0] and its line character index is at [0][1].
        Maze end point line index is at [1][0] and its line character index is at [1][1].
    */ 
    int** pointsPosition = create2DArray(2, 2);

    getPosAndLines(mazeFileStream, lines, pointsPosition);
    



    // cout << (*lines)[pointsPosition[0][0]][pointsPosition[0][1]] << endl;
    // cout << (*lines)[pointsPosition[1][0]][pointsPosition[1][1]];




    // close maze text file.
    (*mazeFileStream).close();


    delete mazeFileStream;
    delete2DArray(pointsPosition, 2);

    return 0;
}