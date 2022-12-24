#include <cmath>
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
using namespace std;



int main()
{
    string S;
    getline(cin, S);
    try {
        int stringsInt = stoi(S);
        cout << stringsInt;
    } catch (...) {
        cout << "Bad String";
    }
    return 0;
}