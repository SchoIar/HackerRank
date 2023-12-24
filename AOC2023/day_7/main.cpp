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
        return 6; // full house
    if (isThreeOfAKind)
        return 3; // three of a kind
    if (isPair && secondMaxCount == 2)
        return 2; // two pairs
    if (isPair)
        return 1; // one pair
    return 0;     // no pair or other hand
}

// Description: Sorts cards in ascending order
void sort(vector<string>& cards){
    for(int i = 0; i < cards.size(); i++){
        for(int j = i; j < cards.size(); j++){
            string hand1 = cards[i].substr(0, hand1.find(" "));
            string hand2 = cards[j].substr(0, hand2.find(" "));
            if(i != j && compareHands(hand1, hand2)){ //hand1 > hand2
                string temp = cards[j];
                cards[j] = cards[i];
                cards[i] = temp;
            }
        }
    }
}

// Description: Compares card hand values. A hand is larger
//              if the first character is larger then another hand.
//              If characters are equal, the 2nd character is compared..
//              Returns true if the first hand is greater.
//              Otherwise returns false.
bool compareHands(const string handOne, const string handTwo)
{
    for (int i = 0; i < handOne.length(); i++)
    {
        if(isFirstCharGreater(handOne[i], handTwo[i]) != -1){
            return isFirstCharGreater(handOne[i], handTwo[i]);
        }
    }
    return false; //base case; cards are equal.
}

// Description: Compares character values.
//      Returns 1 if first digit is larger, 0 if 2nd digit is larger,
//      -1 if they are equal.
int isFirstCharGreater(const char digitOne, const char digitTwo)
{
    if (digitOne == digitTwo)
        return -1; // equal

    if (isdigit(digitOne) && isdigit(digitTwo))
        return isdigit(digitOne) > isdigit(digitTwo);
    else if (isdigit(digitTwo))
    {
        return 1;
    }
    else if (isdigit(digitOne))
    {
        return 0;
    }
    //else both number cards; A K Q J
    char cardValues[4] = {'A', 'K', 'Q', 'J'};

    for(int i = 0; i < 3; i ++){
        if(digitOne == cardValues[i]){
            return 1;
        } else if(digitTwo == cardValues[i]){
            return 0;
        }
    }
    
}

int main()
{
    vector<string> fives, fours, fullhouses, threes, twos, ones, nones;

    string line;
    while (getline(cin, line)) // reading input; placing it into proper bins
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

    // TODO: Sort each group by strength (ascending). Start at 1s and add
    //       product of value and bid.

    for (int i = 0; i < nones.size(); i++)
    {
        cout << nones[i] << endl; // testing - process input here
    }

    return 0;
}
