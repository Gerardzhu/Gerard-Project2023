#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string words;
    int count = 0;

    cout << "Enter words (to stop, type the word done): " << endl;
    do 
    {
        cin >> words;
        if (words != "done") 
        {
            count++;
        }
    } while(words != "done");
    cout << "You entered a total of "<< count << " words.";
    return 0;
}