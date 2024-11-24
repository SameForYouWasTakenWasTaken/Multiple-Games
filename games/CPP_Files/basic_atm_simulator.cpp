#include <iostream>
#include <stdlib.h>
#include <vector>
#include <thread>
#include <chrono>

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

int main()
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
    return 0;
}
}