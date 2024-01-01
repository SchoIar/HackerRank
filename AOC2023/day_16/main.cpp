#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// Description: Checks if beam is out of bounds.
bool isOutOfBounds(int indexX, int indexY, const vector<string> &vec)
{
    if (0 <= indexX && indexX < vec.size() && 0 <= indexY && indexY < vec[indexX].length())
        return false;
    return true;
}

/* Description: Recursive traversal of the beam from the specified index
                to the specified direction.
                Sets visitedSquares to be visited upon
*/
void traverse(int indexX, int indexY, char direction, vector<string> vec)
{

    if (isOutOfBounds(indexX, indexY, vec))
        return;
    /*

        if(vec[indexX][indexY] == "|" and direction is right or left)
            ...
        else if(vec[indexX][indexY] == "-" and direction is up or down
            ...
        else if(vec[indexX][indexY] == "\")
            ...
        else if(vec[indexX][indexY] == "/")
            ...
        else
            ... //is treated like a .; continue in direction.

    */
}
int main()
{
    vector<string> vec;
    vector<string> visitedSquares;

    string inputLine;
    int sum = 0;

    while (getline(cin, inputLine))
    {
        vec.push_back(inputLine);
    }
}
