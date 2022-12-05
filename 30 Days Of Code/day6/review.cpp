#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int numOfTestCases;
    string testCase1;
    cin >> numOfTestCases;
    for (int j = 0; j < numOfTestCases; j++)
    {
        cin >> testCase1;

        // read data from two strings here
        for (int i = 0; i < testCase1.length(); i += 2)
        {
            cout << testCase1[i]; // priting odd
        }
        cout << " ";
        for (int i = 1; i < testCase1.length(); i += 2)
        {
            cout << testCase1[i]; // priting odd
        }
        // output data from both strings here, in [EVEN indicies] [ODD indicies]\n

        cout << '\n';
    }

    return 0;
}
