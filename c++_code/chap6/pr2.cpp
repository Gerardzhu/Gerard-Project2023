#include<iostream>

int main()
{
    using namespace std;
    double num[10];
    double sum = 0;
    int count = 0;
    int set = 0;

    for (int i = 0; i < 10; i++)
    {
        if (!(cin >> num[i])) 
        {
            cout << "Your enter not number: " << endl;;
            break;
        }
        sum += num[i];
        count++;
    }
    cout << "average is: " << sum/count << endl;
    for (int j = 0; j < count; j++)
    {
        if (num[j] > sum/count)
            set++;
    }
    cout << "Over average count is: " << set << endl; 
    return 0;
}