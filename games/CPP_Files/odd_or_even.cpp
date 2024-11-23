#include <iostream>

using namespace std;

int main()
{
    while(true){
        cout << "Input a number!\n";
        long long int input;
        cin >> input;

        if (cin.fail()) terminate();

        if (input%2 == 0){
            cout << "The number is even!\n";
        }else{
            cout << "The number is odd!\n";
        }
    }
    return 0;
}
