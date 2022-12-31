#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int numberOfTestCases;
    cin >> numberOfTestCases;
    for(int j = 0; j < numberOfTestCases; j++){
        int n;
        cin >> n;
        /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        bool isPrime = true;
        //in O(1), starts at 2 since 
        for(int i = 2; i < n; i++){
            if(n % i == 0){
                isPrime = false;
                break;
            }
        }
        
        if(isPrime || n == 1){
            cout << "Prime" << endl;
        }else{
            cout << "Not prime" << endl;
        }
    }
    
    
    return 0;
}