
#include <iostream>
#include <string>        
using namespace std;

struct Pizza 
{
    string company;
    float diam;
    float weight;
};

int main()
{
    Pizza * upipe = new Pizza;

    cout << "enter the diam: ";
    cin >> upipe->diam;

    cout << "enter the weight: ";
    cin >> upipe->weight;

    // 注意上语句输入完 weight 后，回车键留在输入流中，以下的 getline 
    // 碰到输入流中的回车就以为结束了，所以如果没有这个 cin.get() 先读
    // 取回车，那么用户永远获得 company 的值。
    cin.get(); 

    cout << "enter the company: ";
    getline(cin, upipe->company);

    cout << "customer need Pizza is: " <<
        " company form: " << upipe->company <<
        " diam: " << upipe->diam <<
        " weight: " << upipe->weight << endl;
    delete upipe;
    return  0;
}