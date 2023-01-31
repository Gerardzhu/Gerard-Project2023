#include <iostream>
#include <string>

int main()
{
    using namespace std;
    char fname[20];               // create an empty array to store first name
    string lname;                 // create an string type to store last name
    char grade[2];
    string age;

    cout << "What is your first name?";
    cin.getline(fname, 20);
    cout << "What is your last name?";
    getline(cin, lname);          
    cout << "What letter grade do you deserve?";
    cin.getline(grade, 2);
    cout << "What is your age?";
    getline(cin, age); 
    cout << "name: " << lname << "," << fname << endl;
    cout << "Grade: " << char(grade[0]+1) << endl;
    cout << "Age: " << age << endl;
    return 0;
}