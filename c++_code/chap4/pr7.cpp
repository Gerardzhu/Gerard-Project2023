// delete.cpp -- using the delete operator
#include <iostream>
#include <string>        // or string.h
using namespace std;

struct Pizza 
{
    string company;
    float diam;
    float weight;
};

int main()
{
    Pizza upipe;

    cout << "enter the company: ";
    getline(cin, upipe.company);
    
    cout << "enter the diam: ";
    cin >> upipe.diam;

    cout << "enter the weight: ";
    cin >> upipe.weight;

    cout << "customer need Pizza is: " <<
        " company form: " << upipe.company <<
        " diam: " << upipe.diam <<
        " weight: " << upipe.weight << endl;
    return  0;
}