// arrstruc.cpp -- an array of structures
#include <iostream>

struct CandyBar
{
    std::string brand;
    float weight;
    int calorie;
};

int main()
{
    using namespace std;
    CandyBar snack =
    {
        "Mocha Munch",
        2.3,
        350
    };

    cout << "The snack brand: " << snack.brand << " weight: " << snack.weight
         << " calorie: " << snack.calorie << endl;
    return 0;
}