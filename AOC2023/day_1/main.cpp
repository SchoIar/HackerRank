#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Check for written numbers between 1 - 9 in inputLine at a specific point
int checkForNumbers(string inputLine, int i){
    vector<pair<string, int>> numbers = {
        {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };

    for (const auto& num : numbers) {
        string name = num.first;
        int value = num.second;

        if (inputLine.length() >= i + name.length()) {
            if (inputLine.substr(i, name.length()) == name) {
                return value;
            }
        }
    }
    return -1;
}

// Find sum of all calibration values in a line
int findSumToAdd(string inputLine) {
    int firstNum = -1;
    int secondNum = -1;

    // Find the first number (digit or word)
    for (int i = 0; i < inputLine.length(); i++) {
        if (isdigit(inputLine[i])) {
            firstNum = inputLine[i] - '0';
            break;
        } else {
            int num = checkForNumbers(inputLine, i);
            if (num != -1) {
                firstNum = num;
                break;
            }
        }
    }

    // Find the last number (digit or word)
    for (int i = inputLine.length() - 1; i >= 0; i--) {
        if (isdigit(inputLine[i])) {
            secondNum = inputLine[i] - '0';
            break;
        } else {
            int num = checkForNumbers(inputLine, i);
            if (num != -1) {
                secondNum = num;
                break;
            }
        }
    }

    // Combine numbers to form a two-digit number, if both are found
    if (firstNum != -1 && secondNum != -1) {
        return firstNum * 10 + secondNum;
    }
    return 0; // Return 0 if no valid numbers are found
}

int main() {
    string inputLine;
    int sum = 0;
    while (getline(cin, inputLine)) { // Reading each line of input
        sum += findSumToAdd(inputLine);
    }
    cout << "Sum of entire input: " << sum << endl;
}
