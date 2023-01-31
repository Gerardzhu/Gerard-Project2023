#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string fname;              // create an empty array to store first name
    string lname;              // create an string type to store last name

    cout << "Enter your first name:";
    getline(cin, fname);
    cout << "Enter your last name:";
    getline(cin, lname);
    lname = lname + ", ";
    lname = lname + fname;
    cout << "Here's the information in a single string: " 
        << lname  << endl;
    return 0;
}