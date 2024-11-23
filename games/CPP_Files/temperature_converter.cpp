#include <iostream>

using namespace std;

int main()
{
    while (true){
        cout << "Type in C to convert to Celsius, F to convert to fahrenheit\n";
        char input;

        cin >> input;

        if (cin.fail()) terminate();

        if (_tolower(input) == 'c'){
            cout << "Enter in your amount in Celsius : \n";
            double input;
            cin >> input;
            
            if (cin.fail()) terminate();
            cout << "Amount in Fahrenheit : ";
            cout << (input * (9/5)) + 32 << "\n";
        }else if (_tolower(input) == 'f')
        {
            cout << "Enter in your amount in Fahrenheit : \n";
            double input;
            cin >> input;

            if (cin.fail()) terminate();

            cout << "Amount in Celsius : ";
            cout << (input - 32) * 5/9 << "\n";
        }else{
            break;
        }
        
    }
    return 0;
}
