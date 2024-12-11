#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstring>

using namespace std;

string decipher(string &str);

int main(){
    vector<string> input_list;
    size_t i;

    while (1){
        string input;
        getline(cin, input);

        if (input.empty()){
            cerr << "Error reading input." << endl;
            return 1;
        }

        if (input == "-1"){
            break;
        }

        input_list.push_back(input);
    }

    for (i = 0; i < input_list.size(); ++i){
        string deciphered_message = decipher(input_list[i]);
        if (deciphered_message.empty()){
            cerr << "Error deciphering message." << endl;
            return 1;
        }
        if (i > 0){
            cout << " ";
        }
        cout << deciphered_message;
    }
    cout << endl;

    return 0;
}

string decipher(string &str){
    string result;
    size_t i;

    for (i = 0; i < str.size(); ++i){
        if (isalpha(str[i])){
            char ch = tolower(str[i]);
            if (ch >= 'a' && ch <= 'c'){
                ch = ch + 26 - 3;
            } else {
                ch = ch - 3;
            }
            result.push_back(ch);
        } else {
            result.push_back(str[i]);
        }
    }
    return result;
}