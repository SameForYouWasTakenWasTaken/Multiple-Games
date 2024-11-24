#include <iostream>
#include <bits/stdc++.h>

using namespace std;

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

int main()
{
        while (true){
            cout << "Enter in a sentence : \n";
            string input;
            getline(cin, input);
            if (cin.fail()) terminate();
            cout << "This sentence has " << split(input, " ").size() << " words!\n";
        }

    return 0;
}
