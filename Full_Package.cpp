#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <thread>
#include <chrono>
#include <bits/stdc++.h>
// ! ATM

using namespace std;

const int MAX = 26; 

char alphabet[MAX] = { 
'a', 'b', 'c', 'd', 'e', 'f', 'g', 
'h', 'i', 'j', 'k', 'l', 'm', 'n',  
'o', 'p', 'q', 'r', 's', 't', 'u', 
'v', 'w', 'x', 'y', 'z' 
}; 

string randomCharacterGenerator(int length){
    string EndResult;
    for (int i = 0; i > length; i++){
        // generate one in uppercase one lowercase
        if (rand() % 2){
            EndResult = EndResult + alphabet[rand() % MAX];
            
        }else{
            EndResult = EndResult + to_string(toupper(alphabet[rand() % MAX]));
        }
    }

    return EndResult;
}

class ATM {
    private:
    long double bank_balance = 0;
    long double current_money = 0;

    public:
    double withdraw(long double amount){
        cout << bank_balance << endl;
        if (amount <= bank_balance && amount >= 0){
            bank_balance -= amount;
            current_money += amount;
            return bank_balance;
        }else{
            return -1;
        }
    }

    double deposit(long double amount){
        if (amount <= current_money && amount >= 0){
            bank_balance += amount;
            current_money -= amount;
            return bank_balance;
        }else{
            return 0;
        }
    }

    vector<long double> Balances(){
        return {bank_balance, current_money};
    }

    void setMoney(long double money){
        current_money = money;
        bank_balance = 0;
    }
};

void ATM_Game()
{
    ATM ATM_Manager;
    cout << "Welcome to the ATM SIMULATOR, USER!\n";
    cout << "Before we begin, please enter your current amount of money : ";
    long double money;
    cin >> money;
    cout << "\n" << endl;

    if (cin.fail()) terminate();

    ATM_Manager.setMoney(money);

    int waitTime = 100;
    for (int i = 0; i < 10; i++){
        system("CLS");
        cout << "Logging in ";

        this_thread::sleep_for(chrono::milliseconds(waitTime));
        system("CLS");
        cout << "Logging in . ";
        
        this_thread::sleep_for(chrono::milliseconds(waitTime));
        system("CLS");
        cout << "Logging in ..";
        
        this_thread::sleep_for(chrono::milliseconds(waitTime));
        system("CLS");
        cout << "Logging in ..";
        
        this_thread::sleep_for(chrono::milliseconds(waitTime));
        system("CLS");
        cout << "Logging in ...";
        this_thread::sleep_for(chrono::milliseconds(waitTime));
    }

    system("CLS");
    while(true){
        cout << "\n\nLogged in as USER!\n";
        cout << "\n";

        vector<string> descriptions = {"Depositing", "Withdrawing", "Checking balance"};
        for (int i = 0; i < descriptions.size(); i++){
            cout << "Enter " << i + 1 << " for : " << descriptions[i] << endl;
        }

        cout << "\n";

        int Input;
        cin >> Input;

        if (cin.fail()) terminate();

        vector<long double> balances = ATM_Manager.Balances();
        switch (Input){
        
        case 1: {
            system("CLS");
            cout << "Enter your amount to deposit into your bank\n";
            long double amount;
            cin >> amount;

            if (cin.fail()) terminate();
            long double deposit = ATM_Manager.deposit(amount);
            if (deposit < 0 || amount > balances[1] || amount < 0){
                system("CLS");
                cout << "Sorry, an error occurred!\n";
                cout << "\n";
            }else{
                system("CLS");
                cout << "Successfully deposited $" << amount << " to balance!" << endl;
                cout << "Current balance in bank : $" << deposit;
            }
        }continue;
        
        case 2: {
            system("CLS");
            cout << "Enter your amount to withdraw\n";
            long double amount;
            cin >> amount;

            if (cin.fail()) terminate();
            long double withdraw = ATM_Manager.withdraw(amount);
            if (withdraw < 0 || amount > balances[0] || amount < 0){
                system("CLS");
                cout << "Sorry, an error occurred!";
                cout << "\n";
            }else{
                system("CLS");
                cout << "Successfully withdrew $" << amount << "!" << endl;
                cout << "Current balance in bank : $" << withdraw;
        }continue;
        }
        case 3: {
            system("CLS");
            cout << "Your bank balance is : $" << balances[0] << "\n";
            cout << "Your current money is : $" << balances[1];
        }continue;
        
        default:{
            system("CLS");
        }continue;
    }
}
}

// ! Multiplication table
void Multiplication_Table_Game()
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
}

// ! Odd or even
void odd_or_even_game()
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
}

// ! Simple calculator
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

void SimpleCalculator()
{
    math Math;
    while(true){
        cout << "Type in a number following one of these symbols along with a second number after it (Type in any character to exit)\n" << endl;

        // describes every symbol
        for (const auto&item : Math.returnSigns()){
            cout << item.Symbol << " : " << item.description << endl;
        }

        cout << "\n";

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
}

void Temperature_Converter()
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
}

// ! For word counter

// for string delimiter
vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

void word_counter()
{
        while (true){
            cout << "Enter in a sentence : \n";
            string input;
            getline(cin, input);
            if (cin.fail()) terminate();
            cout << "This sentence has " << split(input, " ").size() << " words!\n";
        }
}

struct GameElements{
    void (*func)();
    string Name;
    string Description;
};

int main(){
    vector<GameElements> Games = 
    {
        {ATM_Game, "Basic ATM game", "Deposit, withdraw, etc, like an actual atm!"},
        {Temperature_Converter, "Temperature converter app", "Convert Fahrenheit into Celsius and vice versa"},
        {word_counter, "Word counter app", "Count words in a sentence!"},
        {Multiplication_Table_Game, "Multiplication table app", "Create a multiplication table!"},
        {odd_or_even_game, "Odd Or Even app", "Check if a number is odd or even!"}
    };
    cout << "Enter in the game you want to play!\n";
    int i = 0;
    for (const auto&item : Games){
        cout << ++i << " : " << item.Name << " | " << item.Description;
        cout << "\n";
    }

    int input;
    cin >> input;

    if (cin.fail()) terminate();
    system("CLS");
    
    for (int x = 0; x < Games.size(); x++){
        if (input == x){
            Games[x - 1].func();
        }
    }

    return 0;
}