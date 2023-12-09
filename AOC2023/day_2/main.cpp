#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Description: Function that checks if a game is invalid -
// Invalid games contain more then 12 red cubes, 13 green cubes, and 14 blue cubes
bool isInvalidGame(string myString){
    return true;
}

int getGameID(string myString){
    //inputLine[5]; //game ID
    //while inputLine[i] is not a number, 
    return int(myString[5]);
}

int main() {
    string inputLine;
    int sum = 0;
    while (getline(cin, inputLine)) { // Reading each line of input
        if(isInvalidGame(inputLine))
            sum += getGameID(inputLine);
    }
    cout << "Sum of entire input: " << sum << endl;
}
