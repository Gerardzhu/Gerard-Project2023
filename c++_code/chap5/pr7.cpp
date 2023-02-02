#include <iostream>
#include <string>

struct Car 
{
    std::string company;
    int year;
};

int main()
{
    using namespace std;
    int num = 0;
    cout << "How many cars do you wish to catalog?";
    cin >> num;

    Car * car = new Car[num];
    for (int i = 0; i < num; i++)
    {
        cout << "Car #" << i+1 << ":" << endl;
        cout << "Please enter the make: ";
        cin.get(); 
        getline(cin, (car+i)->company);
        cout << "Please enter the year made: ";
        cin >> (car+i)->year;
    }

    cout << "\nHere is your collection: \n";
    for (int i = 0; i < num; ++i) {
        cout << car[i].year << " " << car[i].company << endl;
    }
    delete []car;
    return 0;

}