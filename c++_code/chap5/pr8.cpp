#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    char words[32];
    int count = 0;

    cout << "Enter words (to stop, type the word done): " << endl;
    do 
    {
        cin >> words;
        if (strcmp(words, "done") != 0) 
        {
            count++;
        }
    } while(strcmp(words, "done") != 0);
    cout << "You entered a total of "<< count << " words.";
    return 0;
}