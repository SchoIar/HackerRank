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
        if (card != ' ' && !isdigit(card))
            frequency[card]++;
    }

    int maxCount = 0, secondMaxCount = 0;
    for (auto pair : frequency)
    {
        if (pair.second > maxCount)
        {
            secondMaxCount = maxCount;
            maxCount = pair.second;
        }
        else if (pair.second > secondMaxCount)
        {
            secondMaxCount = pair.second;
        }
    }

    if (maxCount == 4)
        return 4;
    if (maxCount == 3 && secondMaxCount == 2)
        return 6;
    if (maxCount == 3)
        return 3;
    if (maxCount == 2 && secondMaxCount == 2)
        return 2;
    if (maxCount == 2)
        return 1;
    return 0;
}

int main()
{
    vector<string> fives, fours, fullhouses, threes, twos, ones, nones;
    int sum = 0;

    string line;
    while (getline(cin, line))
    {
        string hand = line.substr(0, line.find(" "));
        int type = whatType(hand);

        switch (type)
        {
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


    return 0;
}
