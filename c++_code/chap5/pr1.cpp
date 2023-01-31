#include <iostream>
#include <string>

int main()
{
    using namespace std;
    int min;
    int max;
    int sum = 0;

    cout << "enter the min number: ";
    cin >> min;
    cout << "enter the max number: ";
    cin >> max;

    for (min; min <= max; min++)
        sum += min;
    cout << "The sum is: " << sum << endl;

    return 0;
}