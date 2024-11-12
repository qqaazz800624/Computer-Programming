#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct question{
    int id;
    string language;
    bool answer;
};

class Disques{

    public:
        void ask(int id, string language){
            question newQuestion = {id, language, false};
            q.push_back(newQuestion);
            cout << "Ask " << id << " in " << language << endl;
        }

        void ans(int id){
            bool found = false;
            for (vector<question>::iterator it = q.begin(); it != q.end(); ++it){
                if (it->id == id){
                    it->answer = true;
                    found = true;
                }
            }
            if (found){
                cout << "Answer " << id << endl;
            } 
        }

        void wait(string language){
            bool Unanswered = false;
            cout << "Search: " << language << endl;
            for (vector<question>::const_iterator it = q.begin(); it != q.end(); ++it){
                if (it->language == language && it->answer == false){
                    cout << it->id << " " << it->language << endl;
                    Unanswered = true;
                }
            }
            if (!Unanswered){
                cout << "No more questions" << endl;
            }
        }

        void finish(){
            bool Answered = false;
            cout << "Finished:" << endl;
            for (vector<question>::const_iterator it = q.begin(); it != q.end(); ++it){
                if (it->answer == true){
                    cout << it->id << " " << it->language << endl;
                    Answered = true;
                }
            }
        }

    private:
        vector<question> q;

};

int main() {
    Disques system;
    string line;

    while (true) {
        
        getline(cin, line);

        stringstream ss(line);
        string action, id_str, language;

        getline(ss, action, ',');
        getline(ss, id_str, ',');
        getline(ss, language, ',');


        if (action == "Q") {
            stringstream ss;
            int id;
            ss << id_str;
            ss >> id;
            system.ask(id, language);
        } else if (action == "A") {
            stringstream ss;
            int id;
            ss << id_str;
            ss >> id;
            system.ans(id);
        } else if (action == "W") {
            system.wait(id_str);
        } else if (action == "F") {
            system.finish();
        } else if (action == "E") {
            cout << "Exit" << endl;
            break;
        }
    }
    return 0;
}