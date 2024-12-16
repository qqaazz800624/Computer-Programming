#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

vector<string> loadReferences(const string &filename) {
    vector<string> references;
    ifstream file(filename.c_str());
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return references;
    }

    string line;
    while (getline(file, line)) {
        references.push_back(line);
    }
    file.close();
    return references;
}

bool isMonthName(const string &word) {
    const string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    for (int i = 0; i < 12; ++i) {
        if (word == months[i]) {
            return true;
        }
    }
    return false;
}

string extractSource(const string &reference) {
    size_t start = reference.find(",\""); // Start after ,"
    if (start != string::npos) {
        start += 2; // Skip ,"

        // Case 1: Before ", vol."
        size_t end = reference.find(", vol.", start);
        if (end == string::npos) {
            // Case 2: Before ", [Year]"
            end = reference.find(", 20", start);
        }
        if (end == string::npos) {
            // Case 3: Before ", [Date]"
            size_t dateStart = string::npos;
            stringstream ss(reference.substr(start));
            string word;
            while (ss >> word) {
                if (isMonthName(word)) {
                    dateStart = reference.find(word, start);
                    break;
                }
            }
            if (dateStart != string::npos) {
                end = reference.rfind(',', dateStart); // Find last ',' before date
            }
        }
        if (end != string::npos) {
            return reference.substr(start, end - start);
        }
    }
    return "Unknown Source"; // Default if no pattern matches
}

int main() {
    vector<string> references = loadReferences("reference.txt");

    if (references.empty()) {
        return 1;
    }

    string query;
    getline(cin, query); 

    for (size_t i = 0; i < query.size(); i++) {
        if (query[i] == '[') {
            size_t end = query.find(']', i);
            if (end != string::npos) {
                string refNumStr = query.substr(i + 1, end - i - 1);
                int refNum = atoi(refNumStr.c_str());
                i = end; 

                if (refNum > 0 && refNum <= references.size()) {
                    string source = extractSource(references[refNum - 1]);
                    cout << "[" << refNum << "] " << source << endl;
                } else {
                    cerr << "Reference number " << refNum << " is out of range." << endl;
                }
            }
        }
    }

    return 0;
}
