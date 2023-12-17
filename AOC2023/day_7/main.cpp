#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cctype>

using namespace std;

int whatType(const string &hand)
{
    map<char, int> frequency;
    for (char card : hand)
    {
        frequency[card]++;
    }

    int maxCount = 0, secondMaxCount = 0;
    bool isPair = false, isThreeOfAKind = false;

    for (const auto &pair : frequency)
    {
        if (pair.second == 2)
        {
            isPair = true;
            secondMaxCount = 2;
        }
        else if (pair.second == 3)
        {
            isThreeOfAKind = true;
            maxCount = 3;
        }
        else if (pair.second == 4)
        {
            return 4; // four of a kind
        } else if (pair.second == 5){
            return 5; // five of a kind
        }
    }

    if (isThreeOfAKind && isPair)
        return 6; // full house
    if (isThreeOfAKind)
        return 3; // three of a kind
    if (isPair && secondMaxCount == 2)
        return 2; // two pairs
    if (isPair)
        return 1; // one pair
    return 0; // no pair or other hand
}

int main()
{
    vector<string> fives, fours, fullhouses, threes, twos, ones, nones;

    string line;
    while (getline(cin, line)) //reading input; placing it into proper bins
    {
        string hand = line.substr(0, line.find(" "));
        int type = whatType(hand);

        switch (type)
        {
        case 5:
            fives.push_back(line);
            break;
        case 4:
            fours.push_back(line);
            break;
        case 6:
            fullhouses.push_back(line);
            break;
        case 3:
            threes.push_back(line);
            break;
        case 2:
            twos.push_back(line);
            break;
        case 1:
            ones.push_back(line);
            break;
        default:
            nones.push_back(line);
            break;
        }
    }

    //TODO: Sort each group by strength (ascending). Start at 1s and add
    //      product of value and bid.

    for(int i = 0; i < nones.size(); i++){
        cout << nones[i] << endl; //testing - process input here
    }

    return 0;
}
