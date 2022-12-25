/*
Author: Anton Ilic
Solution for: https://www.hackerrank.com/challenges/30-conditional-statements/problem
Dec. 3rd, 2022

*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int main()
{
    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));
    //checking odd
    if(N%2 != 0){
        cout << "Weird" << endl;
    }else{
        if(N > 20){
            cout << "Not Weird" << endl;
            return 0;
        }
        if(N > 6){
            cout << "Weird" << endl;
            return 0;
        } 
        // for range of 2-5
        if(N > 2) {
            cout << "Not Weird" << endl;
            return 0;
        }
    }
    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}