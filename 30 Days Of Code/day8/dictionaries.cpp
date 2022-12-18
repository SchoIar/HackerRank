#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
/*
Solution to day 8 of Hackerrank's 30 days of code.

Now with optimal runtime. 

*/

int main()
{

    int N;
    string name;
    cin >> N;

    map<string, int> phone_book;

    for (int i = 0; i < N; i++)
    {
        cin >> name;

        if (!phone_book[name])
        {
            cin >> phone_book[name];
        }
    }

    while (cin >> name)
    {

        if (phone_book[name])
        {
            cout << name << "=" << phone_book[name] << endl;
        }
        else
        {
            cout << "Not found." << endl;
        }
    }

    return 0;
}