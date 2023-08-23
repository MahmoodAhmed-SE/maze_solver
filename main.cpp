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

    while (getline(*mazeFileStream, tempLine))
    {
        lines->push_back(tempLine);
        

        for(int index = 0; index < tempLine.length() && lineIndex < 2; index++)
        {
            if(regex_search(string(1, tempLine[index]), pointRecoginationPattern))
            {
                pointsPosition[pointIndex][0] = lineIndex;
                pointsPosition[pointIndex][1] = index;
                pointIndex++;
            }
        }
        

        lineIndex++;
    }
}

int main(void)
{   
    // initiating and opening maze text file.
    fstream *mazeFileStream = new fstream;
    (*mazeFileStream).open("./example.txt");

    vector<string> *lines = new vector<string>;
    int** pointsPosition = create2DArray(2, 2);

    getPosAndLines(mazeFileStream, lines, pointsPosition);
    
    cout << pointsPosition[0][0];
    cout << pointsPosition[0][1] << endl;
    cout << pointsPosition[1][0];
    cout << pointsPosition[1][1] << endl;



    // close maze text file.
    (*mazeFileStream).close();


    delete mazeFileStream;
    delete2DArray(pointsPosition, 2);

    return 0;
}