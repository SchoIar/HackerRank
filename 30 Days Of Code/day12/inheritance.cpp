// Day 12 of Hackerank's 30 days of code

#include <iostream>
#include <vector>

using namespace std;

class Person
{
protected:
    string firstName;
    string lastName;
    int id;

public:
    Person(string firstName, string lastName, int identification)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->id = identification;
    }
    void printPerson()
    {
        cout << "Name: " << lastName << ", " << firstName << "\nID: " << id << "\n";
    }
};

class Student : public Person
{
private:
    vector<int> testScores;

public:
    Student(string firstName, string lastName, int id, vector<int> scores) : Person(firstName, lastName, id)
    {
        for (int i = 0; i < scores.size(); i++)
        {
            testScores.push_back(scores[i]);
        }
    }
    char calculate() const
    {
        int grade = 0;
        int numOfScores = testScores.size();
        for (int i = 0; i < numOfScores; i++)
        {
            grade = grade + testScores[i];
        }
        grade = grade / numOfScores;

        // note: not checking for invalid grades

        if (grade >= 90 && grade <= 100)
            return 'O';
        else if (grade >= 80 && grade < 90)
            return 'E';
        else if (grade >= 70 && grade < 80)
            return 'A';
        else if (grade >= 55 && grade < 70)
            return 'P';
        else if (grade >= 40 && grade < 55)
            return 'D';
        else
            return 'T';
    }
    /*
     *   Class Constructor
     *
     *   Parameters:
     *   firstName - A string denoting the Person's first name.
     *   lastName - A string denoting the Person's last name.
     *   id - An integer denoting the Person's ID number.
     *   scores - An array of integers denoting the Person's test scores.
     */
    // Write your constructor here

    /*
     *   Function Name: calculate
     *   Return: A character denoting the grade.
     */
    // Write your function here
};

int main()
{
    string firstName;
    string lastName;
    int id;
    int numScores;
    cin >> firstName >> lastName >> id >> numScores;
    vector<int> scores;
    for (int i = 0; i < numScores; i++)
    {
        int tmpScore;
        cin >> tmpScore;
        scores.push_back(tmpScore);
    }
    Student *s = new Student(firstName, lastName, id, scores);
    s->printPerson();
    cout << "Grade: " << s->calculate() << "\n";
    return 0;
}