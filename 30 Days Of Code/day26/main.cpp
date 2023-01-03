#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */     int dateReturned, monthReturned, yearReturned, dueDate, dueMonth, dueYear, fine;

    //Dates returned: DD MM YY
    cin >> dateReturned;
    cin >> monthReturned;
    cin >> yearReturned;
    //Dates due
    cin >> dueDate;
    cin >> dueMonth;
    cin >> dueYear;
    
    //checking when date ISNT valid
    if(dueYear < yearReturned){
        //different year (Year(s) late)
        fine = 10000;
    }else if(dueYear == yearReturned){
        if(dueMonth < monthReturned){
            //months late 
            fine = 500 * (monthReturned - dueMonth);
        }else if(dueDate < dateReturned && monthReturned == dueMonth){
            //days late
            fine = 15 * (dateReturned - dueDate);
        }
    }
    
    cout << fine << endl;
    return 0;
}