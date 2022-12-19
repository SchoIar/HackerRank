//Day 10 of 30 days of code.
#include <iostream>

using namespace std;

int main() {
    int n;
    int sum = 0;

    int maximum = 0;
    cin >> n;


    while (n > 0) {
        
        if (n % 2 == 1) {
            sum++;
            if(sum > maximum){
                maximum = sum;
            }
            n = (n-1)/2;
        }else{//in this case, has no remainder thus hits a 0
            n = n/2;
            sum = 0;
            
        }

    }

    cout << maximum;

    return 0;
}