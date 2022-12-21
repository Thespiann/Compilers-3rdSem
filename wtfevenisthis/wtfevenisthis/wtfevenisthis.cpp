// wtfevenisthis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
using namespace std;

string input,output;
int i=0,j=0;
random_device rd1,rd2;
mt19937 gen(rd1()), gen((rd2()));

int random(int low, int high)
{
    std::uniform_int_distribution<> dist(low, high);
    return dist(gen);
}
int main()
{
    cout <<"Input non terminal characters Z| K| G| M\n";
    cin >> input;
    if (input[i] =='Z') {
        output[j] = 'K';
    }
    if ()
    


}

int main() {
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
