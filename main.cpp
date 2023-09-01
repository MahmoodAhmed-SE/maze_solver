#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include "./maze_solver.cpp"

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

    MazeSolver ms = MazeSolver(mazeFileStream, lines, pointsPosition);
    
    // cout << (*lines)[1] << endl;

    
    ms.solveMaze();

    
    


    // close maze text file.
    (*mazeFileStream).close();


    delete mazeFileStream;
    delete2DArray(pointsPosition, 2);

    return 0;
}