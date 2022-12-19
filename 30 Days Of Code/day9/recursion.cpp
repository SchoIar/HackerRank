#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

/*
Solution to day 9 of Hackerrank's 30 days of code.
Anton Ilic.
Dec 18 2022

*/
using namespace std;


int factorial(int n) {
    if(n != 1){
        n = n * factorial(n-1);
    }
    return n;

}

int main()
{
    int n;
    cin >> n;
    int r = factorial(n);
    cout << r << endl;
    return 0;
}

