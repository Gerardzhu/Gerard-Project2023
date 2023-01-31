#include <iostream>

int main()
{
    using namespace std;
    int count = 0;
    double Da = 100;
    double Cl = 100;

    for (int i = 1; Cl <= Da; i++)
    {
        Da = Da + 10;
        Cl = Cl + 0.05*Cl;
        count = i;
    }
    cout << "year is: " << count <<
        " Daphnel get: " << Da <<
        " Cleo get: " << Cl << endl;

    return 0;
}