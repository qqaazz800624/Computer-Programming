#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Employee {
    private:
        int level;
        int attack;
        int defense;

    public:
        Employee(){
            level = 0;
            attack = 0;
            defense = 0;
        }

        Employee(int level, int attack, int defense) {
            this->level = level;
            this->attack = attack;
            this->defense = defense;
        }

        int getLevel() {
            return level;
        }

        int getAttack() {
            return attack;
        }

        int getDefense() {
            return defense;
        }

};

int countCritics(int n, vector<Employee> &employees, int starter) {
    queue<int> q;
    set<int> criticized; 
    q.push(starter - 1); 
    criticized.insert(starter - 1);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        Employee& currentEmp = employees[curr];

        for (int i = 0; i < n; ++i) {
            if (criticized.find(i) == criticized.end()) { 
                Employee& targetEmp = employees[i];
                if (currentEmp.getLevel() > targetEmp.getLevel() && 
                    currentEmp.getAttack() > targetEmp.getDefense()) {
                    q.push(i);
                    criticized.insert(i);
                }
            }
        }
    }

    return criticized.size(); 
}

int main() {
    int n;
    cin >> n;
    vector<Employee> employees(n);

    for (int i = 0; i < n; ++i) {
        int level, attack, defense;
        cin >> level >> attack >> defense;
        employees[i] = Employee(level, attack, defense);
    }

    int starter;
    cin >> starter;

    int result = countCritics(n, employees, starter);
    cout << result << endl;

    return 0;
}