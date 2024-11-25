#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct Question {
    int id;
    string language;
    bool answered;
};

class Disques {
    private:
        Question questions[50];
        int questionCount;

    public:
        Disques() : questionCount(0) {}

        void ask(int id, const string &language) {
            if (questionCount >= 50) {
                cout << "Cannot add more questions." << endl;
                return;
            }
            
            questions[questionCount].id = id;
            questions[questionCount].language = language;
            questions[questionCount].answered = false;
            questionCount++;

            cout << "Ask " << id << " in " << language << endl;
        }

        void ans(int id) {
            bool found = false;
            for (int i = 0; i < questionCount; i++) {
                if (questions[i].id == id) {
                    questions[i].answered = true;
                    found = true;
                }
            }
            
            if (found) {
                cout << "Answer " << id << endl;
            }
        }

        void wait(const string &language) {
            bool hasUnanswered = false;
            cout << "Search: " << language << endl;
            
            for (int i = 0; i < questionCount; i++) {
                if (questions[i].language == language && !questions[i].answered) {
                    cout << questions[i].id << " " << questions[i].language << endl;
                    hasUnanswered = true;
                }
            }
            
            if (!hasUnanswered) {
                cout << "No more questions" << endl;
            }
        }



        void finish() {
            bool hasAnswered = false;
            cout << "Finished: " << endl;
            
            for (int i = 0; i < questionCount; i++) {
                if (questions[i].answered) {
                    cout << questions[i].id << " " << questions[i].language << endl;
                    hasAnswered = true;
                }
            }
            
            if (!hasAnswered) {
                cout << "No more questions" << endl;
            }
        }
};

int main() {
    Disques system;
    string input;

    while (getline(cin, input)) {
        if (input.empty()) continue;

        char command = input[0];
        if (command == 'Q') {
            int id;
            string language;
            char comma;
            istringstream ss(input);
            ss >> command >> comma >> id >> comma >> language;
            system.ask(id, language);
        } else if (command == 'A') {
            int id;
            char comma;
            istringstream ss(input);
            ss >> command >> comma >> id;
            system.ans(id);
        } else if (command == 'W') {
            string language = input.substr(2);  
            system.wait(language);
        } else if (command == 'F') {
            system.finish();
        } else if (command == 'E') {
            cout << "Exit" << endl;
            break;
        }
    }

    return 0;
}
