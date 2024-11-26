#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <filesystem>

using namespace std;

namespace fs = std::filesystem;

struct GameElements {
    string exeFile;
    string Name;
    string Description;
};

int main()
{
    fs::path directory = fs::current_path() / "games" / "EXE_Files";
    vector<GameElements> Games = {
        {(directory / "basic_atm_simulator.exe").string(), "ATM Game", "Deposit, withdraw, like an ATM!"},
        {(directory / "temperature_converter.exe").string(), "Temperature Converter", "Convert Fahrenheit and Celsius."},
        {(directory / "word_counter.exe").string(), "Word Counter", "Counts words in a sentence."},
        {(directory / "multiplication_table_generator.exe").string(), "Multiplication Table", "Generate multiplication tables."},
        {(directory / "odd_or_even.exe").string(), "Odd or Even Checker", "Check if a number is odd or even."},
        {(directory / "SimpleCalculator.exe").string(), "Simple Calculator", "Calculate with simple arithmetic operators!"},

    };

    cout << "Welcome! Please select a game, to play it!" << endl;

    for (int i = 0; i < Games.size(); i++){
        cout << i + 1 << " : " << Games[i].Name << " | " << Games[i].Description << endl;
    }

    int input;
    cin >> input;

    if (cin.fail() || input < 1 || input > Games.size()) terminate();

    for (int i = 0; i < Games.size(); i++){
        if (input == i + 1){
            cout << "Launching game " << Games[i].Name << "..." << endl;
            this_thread::sleep_for(chrono::seconds(3));
            system(("\"" + Games[input - 1].exeFile + "\"").c_str());
            system("pause");
        }
    }

    return 0;
}
