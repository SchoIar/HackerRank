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
    int pairCount = 0;
    for (auto i : frequency)
    {
        if (i.second == 2)
            pairCount = pairCount + 1;
        if (i.second == 5)
            return 5; // 5 of a kind
        if (i.second == 4)
            return 4; // 5 of a kind
        if (i.second == 3)
            isThreeOfAKind = true;
    }

    if (pairCount == 1 && isThreeOfAKind)
    {
        return 6; // full house
    }
    else if (isThreeOfAKind)
    {
        return 3; // three of a kind.
    }
    return pairCount; // no pair or only pairs
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

int findKey(const std::string &line)
{
    size_t spacePos = line.find(" ");
    return stoi(line.substr(spacePos + 1));
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
    sort(ones);
    sort(twos);
    sort(threes);
    sort(fullhouses);
    sort(fours);
    sort(fives);

    int i = 1;
    int keyProductSum = 0; // Start from 0 to ensure accurate summation

    for (int j = 0; j < nones.size(); j++, i++)
    {
        keyProductSum = keyProductSum + i * findKey(nones[j]);
    }

    for (int j = 0; j < ones.size(); j++, i++)
    {
        keyProductSum = keyProductSum + i * findKey(ones[j]);
    }

    for (int j = 0; j < twos.size(); j++, i++)
    {
        keyProductSum = keyProductSum + i * findKey(twos[j]);
    }

    for (int j = 0; j < threes.size(); j++, i++)
    {
        keyProductSum = keyProductSum + i * findKey(threes[j]);
    }

    for (int j = 0; j < fullhouses.size(); j++, i++)
    {
        keyProductSum = keyProductSum + i * findKey(fullhouses[j]);
    }

    for (int j = 0; j < fours.size(); j++, i++)
    {
        keyProductSum = keyProductSum + i * findKey(fours[j]);
    }
    for (int j = 0; j < fives.size(); j++, i++)
    {
        keyProductSum = keyProductSum + i * findKey(fives[j]);
    }

    cout << "SUM: " << keyProductSum << endl;

    return 0;
}
