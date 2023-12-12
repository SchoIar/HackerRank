#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int whatType(const std::string &str)
{
    int maxDuplicates = 0;
    int secondMaxDuplicates = 0;

    for (int i = 0; i < str.length(); i++)
    {
        int count = 0;

        // Count duplicates of str[i]
        for (int y = 0; y < str.length(); y++)
        {
            if (str[i] == str[y])
            {
                count++;
            }
        }

        // Update max and second max
        if (count > maxDuplicates)
        {
            secondMaxDuplicates = maxDuplicates;
            maxDuplicates = count;
        }
        else if (count > secondMaxDuplicates && count < maxDuplicates)
        {
            secondMaxDuplicates = count;
        }
    }

    // Check for full house
    if (maxDuplicates == 3 && secondMaxDuplicates == 2)
    {
        return 6; // full house
    }

    return maxDuplicates;
}

int main()
{
    vector<string> vec;
    string inputLine;
    int sum = 0;

    int count = 0;
    while (getline(cin, inputLine))
    { // Reading each line of input
        vec.push_back(inputLine);
        count++;
    }

    vector<string> fives;      // TYPE 5
    vector<string> fours;      // TYPE 4
    vector<string> fullhouses; // TYPE 6
    vector<string> threes;     // 3
    vector<string> twos;       // 2
    vector<string> ones;       // 1
    vector<string> nones;      // 0

    for (int i = 0; i < vec.size(); i++)
    {
        bool spaceNotFound = true;
        string current = "";
        for (int j = 0; j < vec[i].length(); j++)
        {
            if (vec[i][j] == ' ')
            {
                spaceNotFound = false;
                int type = whatType(current);
                // add to that type
                switch (type)
                {
                case 0:
                    nones.push_back(vec[i]);
                    break;
                case 1:
                    ones.push_back(vec[i]);
                    break;
                case 2:

                    break;
                case 3:

                    break;
                case 4:

                    break;
                case 5:

                    break;
                case 6: // type 6; full house;

                    break;

                default:
                    // error; assume none.
                }

                break;
            }
            else if (spaceNotFound)
            { 
                current = current + vec[i][j];
            }
            
        }
    }

    cout << "The total winnings: " << sum << endl;
    return 0;
}
