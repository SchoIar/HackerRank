#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference
{
private:
    vector<int> elements;

public:
    int maximumDifference;
    Difference(vector<int> listOfStuff)
    {
        this->elements = listOfStuff;
    }

    void computeDifference()
    {
        int numberOfElements = elements.size();
        // comparing ABS of both numbers
        maximumDifference = 0;
        for (int i = 0; i < numberOfElements; i++)
        {
            for (int j = 0; j < numberOfElements; j++)
            {
                if (abs(elements[i] - elements[j]) > maximumDifference)
                {
                    maximumDifference = abs(elements[i] - elements[j]);
                }
            }
        }
    }
    // Add your code here

}; // End of Difference class

int main()
{
    int N;
    cin >> N;

    vector<int> a;

    for (int i = 0; i < N; i++)
    {
        int e;
        cin >> e;

        a.push_back(e);
    }

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference;

    return 0;
}