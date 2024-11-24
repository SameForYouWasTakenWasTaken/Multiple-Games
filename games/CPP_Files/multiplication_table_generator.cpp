#include <iostream>

using namespace std;

int main()
{
    while (true){
        cout << "Enter in 2 *WHOLE* numbers to generate a multiplication table : \n";
        int num1;
        cin >> num1;

        if (cin.fail()) terminate();

        int num2;
        cin >> num2;
        cout << "\n" << endl;
        if (cin.fail()) terminate();
        for (int i = 0; i < num2; i++){
            cout << num1;
            for (int x = 0; x <= (num1 - 6); ++x){
                cout << num1;
            }
            cout << "\n";
        }
    }
    return 0;
}
