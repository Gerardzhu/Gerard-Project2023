#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    char fname[20];               // create an empty array to store first name
    char lname[20];                // create an string type to store last name

    cout << "Enter your first name:";
    cin.getline(fname, 20);
    cout << "Enter your last name:";
    cin.getline(lname, 20);

    cout << "Here's the information in a single string: " 
        << strcat(strcat(lname , ", "), fname) << endl;
    return 0;
}