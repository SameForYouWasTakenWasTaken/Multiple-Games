#include <iostream>
#include <vector>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct MathElements {
    char Symbol;
    string description;
};

struct endResult {
    long double Number1;
    char Symbol;
    long double Number2;
};

class math{
    private:
    enum Constants {
        sign_plus = '+',
        sign_minus = '-',
        sign_multiply = '*',
        sign_divide = '/',
    };

    public:

    vector<MathElements> returnSigns(){
        return {
            {sign_plus, "Does addition"}, 
            {sign_minus, "Does subtraction"}, 
            {sign_multiply, "Does multiplication"}, 
            {sign_plus, "Does division"}
            };
    }

    double Calculate(vector<endResult> list){
        double result;
        for (const auto&item : list){
            switch (item.Symbol){
            case sign_plus:
                result = item.Number1 + item.Number2;
                break;
            case sign_minus:
                result = item.Number1 - item.Number2;
                break;
            case sign_multiply:
                result = item.Number1 * item.Number2;
                break;
            case sign_divide:
                result = item.Number1 / item.Number2;
                break;
            }
            cout << "\n";
        }

        return result;
    }
};

int main()
{
    math Math;
    cout << "\n";
    while(true){
        cout << "Type in a number following one of these symbols along with a second number after it (Type in any character to exit)\n" << endl;

        // describes every symbol
        for (const auto&item : Math.returnSigns()){
            cout << item.Symbol << " : " << item.description << endl;
        }

        cout << "____" << " _ " << "____\n" << endl;
        
        long double num;
        cin >> num;

        if (cin.fail()) terminate();
        

        cout << num << " _ " << "____\n" << endl;

        char sym;
        cin >> sym;

        if (cin.fail()) terminate();

        cout << num << " " << sym << " " << "____\n" << endl;

        long double num2;
        cin >> num2;

        if (cin.fail()) terminate();

        cout << num << " " << sym << " " << num2 << "\n" <<endl;

        vector<endResult> ResultList = {{num,sym,num2}};
        system("cls");
        cout << Math.Calculate(ResultList) << "\n";
    }

    return 0;
}
