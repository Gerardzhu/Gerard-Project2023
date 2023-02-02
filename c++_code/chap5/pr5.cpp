#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string month;
    int volume[12];
    int sum = 0;

    for (int i = 0; i < 12; i++)
    {
        switch(i)
        {
            case 0:
                month = "January";
                break;
            case 1:
                month = "February";
                break;
            case 2:
                month = "March";
                break;
            case 3:
                month = "April";
                break;
            case 4:
                month = "May";
                break;
            case 5:
                month = "June";
                break;
            case 6:
                month = "July";
                break;
            case 7:
                month = "August";
                break;
            case 8:
                month = "September";
                break;
            case 9:
                month = "October";
                break;
            case 10:
                month = "November";
                break;
            case 11:
                month = "December";
                break;
            default:
                month = "unknown";
                break;
        }
        cout << month << " sales volume: ";
        while (!(cin >> volume[i])) {
            cin.clear();  // reset input
            while (cin.get() != '\n')
                continue; // get rid of bad input
            cout << "Please enter a number: ";
        }
        sum += volume[i];
    }
    cout  << "This year sales amount is: " << sum << endl;

    return 0;
}