#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <stack>
#include <cmath>
using namespace std;

int numberOfElementsFound(string inputLine)
{
    vector<int> myElements;
    int i = 0;
    int count = 0;

    while (inputLine[i] != ':')
    {
        i = i + 1; // getting to start of input
    }

    while (inputLine[i] != '|')
    {
        string input = "";
        while (inputLine[i] != ' ')
        {
            if (isdigit(inputLine[i]))
            {
                input = input + inputLine[i];
            }
            i++;
        }
        if(!input.empty())
            myElements.push_back(stoi(input));
        i = i + 1; // getting to start of input
    }

    while (i < inputLine.length())
    {
        string input = "";
        while (inputLine[i] != ' ' && i < inputLine.length())
        {
            if (isdigit(inputLine[i]))
            {
                input = input + inputLine[i];
            }
            i++;
        }
        // if stoi(input) is IN myElements, count ++
        if (!input.empty())
            for (int i = 0; i < myElements.size(); i++)
            {
                if (stoi(input) == myElements[i])
                {
                    count++;
                    break;
                }
            }

        i = i + 1; // getting to start of input
    }

    if (count == 0)
        return 0;
    return pow(2, (count - 1));

    // myElements.push_back()
}

int main()
{

    string inputLine;
    int sum = 0;

    while (getline(cin, inputLine))
    { // Reading each line of input
        sum = sum + numberOfElementsFound(inputLine);
    }

    cout << "Sum of entire input: " << sum << endl;
    return 0;
}
