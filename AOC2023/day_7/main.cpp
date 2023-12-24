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
        frequency[card]++; // counting card frequency
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
        }
        else if (pair.second == 5)
        {
            return 5; // five of a kind
        }
    }

    if (isThreeOfAKind && isPair)
    {
        return 6; // full house
    }
    if (isThreeOfAKind)
    {
        return 3; // three of a kind
    }
    if (isPair && secondMaxCount == 2)
    {
        return 2; // two pairs
    }
    if (isPair)
    {
        return 1; // one pair
    }
    return 0; // no pair or other hand
}

int isFirstCharGreater(const char digitOne, const char digitTwo)
{
    const char cardValues[] = {'A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2'};
    map<char, int> cardValueMap;
    for (int i = 0; i < 13; i++)
    {
        cardValueMap[cardValues[i]] = i;
    }

    if (digitOne == digitTwo)
    {
        return -1; // equal
    }

    return cardValueMap[digitOne] < cardValueMap[digitTwo] ? 1 : 0;
}

bool compareHands(const string handOne, const string handTwo)
{
    for (int i = 0; i < min(handOne.length(), handTwo.length()); i++)
    {
        int comparisonResult = isFirstCharGreater(handOne[i], handTwo[i]);
        if (comparisonResult != -1)
        {
            return comparisonResult == 1;
        }
    }
    return false; // base case; cards are equal.
}

void sort(vector<string> &cards)
{
    for (int i = 0; i < cards.size(); i++)
    {
        for (int j = i; j < cards.size(); j++)
        {
            string hand1 = cards[i].substr(0, cards[i].find(" "));
            string hand2 = cards[j].substr(0, cards[j].find(" "));
            if (i != j && compareHands(hand1, hand2))
            {
                swap(cards[i], cards[j]);
            }
        }
    }
}

int main()
{
    vector<string> fives, fours, fullhouses, threes, twos, ones, nones;

    string line;
    while (getline(cin, line))
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
    
    sort(nones);

    for (int i = 0; i < nones.size(); i++)
    {
        cout << nones[i] << endl; // testing - process input here
    }

    return 0;
}
