#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool checkIndex(char c){
    return c != '.' && !isdigit(c); // Return true for symbols
}

bool checkBorders(const vector<string>& vec, int i, int j) {
    // Check immediate surroundings
    for (int a = max(0, i - 1); a <= min(i + 1, static_cast<int>(vec.size()) - 1); a++) {
        for (int b = max(0, j - 1); b <= min(j + 1, static_cast<int>(vec[a].length()) - 1); b++) {
            if ((a != i || b != j) && checkIndex(vec[a][b])) { // Check surrounding indices, excluding the current index
                return true;
            }
        }
    }
    return false;
}

int wholeNumber(const vector<string>& vec, int i, int& j){
    string numberOfGames = "";

    // finding "front of number"
    int jTemp = j;
    while (jTemp >= 0 && isdigit(vec[i][jTemp])) {
        numberOfGames = vec[i][jTemp--] + numberOfGames;
    }

    jTemp = j + 1;

    // finding "back of number"
    while (jTemp < vec[i].length() && isdigit(vec[i][jTemp])) {
        numberOfGames += vec[i][jTemp++];
    }

    j = jTemp - 1; // Update j to the last digit of the number
    return stoi(numberOfGames);
}

int main() {
    vector<string> vec;
    string inputLine;
    int sum = 0;

    while (getline(cin, inputLine)) { // Reading each line of input
        vec.push_back(inputLine);
    }

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].length(); j++) {
            if (isdigit(vec[i][j]) && checkBorders(vec, i, j)) {
                sum += wholeNumber(vec, i, j);
            }
        }
    }

    cout << "Sum of entire input: " << sum << endl;
    return 0;
}
