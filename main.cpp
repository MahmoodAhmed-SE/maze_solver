#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main(void)
{
    // initiating and opening maze text file
    fstream mazeFileStream("example.txt");
    
    string tempLine;

    string lines[13];
    cout << "hello ";
    short int i = 0;
    while (getline(mazeFileStream, tempLine))
    {
        lines[i] = tempLine;
        i++;
    }

    for (string line : lines)
    {
        cout << line << endl;
    }

    // close maze text file
    mazeFileStream.close();

    return 0;
}