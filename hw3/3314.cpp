#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Soldier {
    int health;
    int attack;
};

bool loadArmy(const string &filename, vector<Soldier> &soldiers);
void battle(int dragonHealth, int dragonAttack, const vector<Soldier> &soldiers, const string &historyFilename);


int main() {
    int dragonHealth, dragonAttack;
    string armyName;
    
    cin >> dragonHealth >> dragonAttack >> armyName;
    vector<Soldier> soldiers;
    string armyFilename = "./" + armyName + ".txt";
    if (!loadArmy(armyFilename, soldiers)) {
        ofstream historyFile("./history.txt");
        historyFile << "failed:(";
        return 0;
    }
    battle(dragonHealth, dragonAttack, soldiers, "./history.txt");
    
    return 0;
}

bool loadArmy(const string &filename, vector<Soldier> &soldiers) {
    ifstream armyFile(filename.c_str());
    if (!armyFile.is_open()) {
        return false;  
    }
    
    int numSoldiers;
    armyFile >> numSoldiers;
    soldiers.resize(numSoldiers);
    
    for (int i = 0; i < numSoldiers; ++i) {
        armyFile >> soldiers[i].health >> soldiers[i].attack;
    }
    return true;
}

void battle(int dragonHealth, int dragonAttack, const vector<Soldier> &soldiers, const string &historyFilename) {
    ofstream historyFile(historyFilename.c_str());
    
    if (dragonHealth <= 0) {
        historyFile << "success!";
        return;
    }

    bool dragonDefeated = false;
    for (size_t i = 0; i < soldiers.size(); ++i) {
        int soldierHealth = soldiers[i].health;
        int soldierAttack = soldiers[i].attack;

        if (soldierHealth <= 0) {
            continue;
        }

        while (soldierHealth > 0 && dragonHealth > 0) {
            dragonHealth -= soldierAttack;
            if (dragonHealth <= 0) {
                dragonDefeated = true;
                historyFile << i << " " << soldierHealth << " " << dragonHealth << endl;
                break;
            }
            soldierHealth -= dragonAttack;
            historyFile << i << " " << soldierHealth << " " << dragonHealth << endl;
        }

        if (dragonDefeated) {
            break;
        }
    }

    if (dragonDefeated) {
        historyFile << "success!";
    } else {
        historyFile << "failed:(";
    }
}