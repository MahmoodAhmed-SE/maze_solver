#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "./maze_solver.cpp"

using namespace std;


int main(void)
{   
    MazeSolver exampleSolver = MazeSolver("example.txt");
    exampleSolver.solve();


    return 0;
}