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
    CandyBar snack[3] =
    {
        {"Mocha Munch", 2.3, 350},
        {"Dove", 1.6, 20},
        {"Coco", 3.2, 50}
    };

    cout << "Structure snack 1 brand: " << snack[0].brand << " weight: " << snack[0].weight
         << " calorie: " << snack[0].calorie << endl;
    cout << "Structure snack 2 brand: " << snack[1].brand << " weight: " << snack[1].weight
         << " calorie: " << snack[1].calorie << endl;
    cout << "Structure snack 3 brand: " << snack[2].brand << " weight: " << snack[2].weight
         << " calorie: " << snack[2].calorie << endl;
    return 0;
}