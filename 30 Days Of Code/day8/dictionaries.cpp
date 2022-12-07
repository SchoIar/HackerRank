#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
/*
Solution to day 8 of Hackerrank's 30 days of code, note: does not have optimal runtime. 
Will try and improve performance.

*/

int main()
{

    int numOfNamesAndNumbers;
    cin >> numOfNamesAndNumbers;
    string input;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<string, string> phoneBook;
    cin.ignore(); // Don't forget this
    for (int i = 0; i < numOfNamesAndNumbers; i++)
    {
        getline(cin, input);
        size_t space = input.find(" ");
        string s1 = input.substr(0, space);
        string s2 = input.substr(space + 1); // Until the end
        phoneBook.insert(pair<string, string>(s1, s2));
    }

    // TODO: read input, check if it doesn't pass.
    string name;
    while (getline(cin, name))
    {
        bool isNotFound = 1;
        for (auto element : phoneBook)
        {
            if (element.first == name){
                cout << element.first << "=" << element.second << endl;
                isNotFound = 0;
            }
               
        }
        if(isNotFound){
            cout << "Not found" << endl;
        }
    }

    return 0;
}