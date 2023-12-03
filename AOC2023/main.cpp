#include <iostream>
using namespace std;

int checkForNumbers(string inputLine, int i){
    //TODO: Impliment this
}

int findSumToAdd(string inputLine) {
    int firstNum = 0;
    int secondNum = 0;

    for (int i = 0; i < inputLine.length(); i++) {

        if (isdigit(inputLine[i])) {
            firstNum = inputLine[i] - '0'; // Correctly convert char to int
            
            for (int j = inputLine.length() - 1; j > i; j--) {
                if (isdigit(inputLine[j])) {
                    secondNum = inputLine[j] - '0'; // Correctly convert char to int
                    return firstNum * 10 + secondNum; // found both numbers
                }
            }
            return firstNum * 10 + firstNum;//only contains one number
            //FOUND. 
        }
    }

    return 0; // Return 0 if no digits are found
}

int main() {
    string inputLine = "";
    int sum = 0;
    while (cin >> inputLine) { // reading input from input.txt
        sum = sum + findSumToAdd(inputLine);
    }
    cout << "Sum of entire input " << sum << endl;
}
