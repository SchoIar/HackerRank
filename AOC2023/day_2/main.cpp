#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <cctype> // for isdigit()

// Description: gets the number of games associated with an input
int getNumberOfGames(const string& myString, int index) {
    string numberOfGames = "";
    while (isdigit(myString[index - 2])) {
        numberOfGames = myString[index - 2] + numberOfGames;
        index--;
    }
    return numberOfGames.empty() ? 0 : stoi(numberOfGames);
}
// Description: Function that checks if a game is valid-
// Invalid games contain more then 12 red cubes, 13 green cubes, and 14 blue cubes
bool isValid(string myString){
    int rSum = 0;
    int gSum = 0;
    int bSum = 0;
    for(int i = 5; i < myString.length(); i++){ //iterate through string. if is an ID
        if(tolower(myString[i]) == 'r')
            rSum = rSum + getNumberOfGames(myString, i);
        if(tolower(myString[i]) == 'g')
            gSum = gSum + getNumberOfGames(myString, i);
        if(tolower(myString[i]) == 'b')
            bSum = bSum + getNumberOfGames(myString, i);
        if(tolower(myString[i]) == ';'){
            bSum = 0;
            rSum = 0;
            gSum = 0;
        }
        if (!(rSum <= 12 && gSum <= 13 && bSum <= 14))
            return false;

    }
    return (rSum <= 12 && gSum <= 13 && bSum <= 14);
}

// Descrition: Returns gameID; 
// Precondition: Game ID is assumed to start at index 5 of the string.
int getGameID(string myString){
    int i = 5;
    string gameId = "";
    while(isdigit(myString[i])){
        gameId = gameId + myString[i];
        i = i + 1;
    }
    return stoi(gameId);
}

int main() {
    string inputLine;
    int sum = 0;
    while (getline(cin, inputLine)) { // Reading each line of input
        if(isValid(inputLine))
            sum += getGameID(inputLine);
    }
    cout << "Sum of entire input: " << sum << endl;
}
