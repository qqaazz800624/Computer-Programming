#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cstdlib>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    map<int, string> references;
    for (int i = 0; i < n; ++i) {
        string reference;
        getline(cin, reference);

        size_t start = reference.find('[');
        size_t end = reference.find(']');
        if (start != string::npos && end != string::npos && end > start) {
            int refNumber = atoi(reference.substr(start + 1, end - start - 1).c_str());
            references[refNumber] = reference;
        }
    }

    string query;
    getline(cin, query);

    vector<int> queryNumbers;
    size_t pos = 0;
    while ((pos = query.find('[')) != string::npos) {
        size_t end = query.find(']', pos);
        if (end != string::npos) {
            int refNumber = atoi(query.substr(pos + 1, end - pos - 1).c_str());
            queryNumbers.push_back(refNumber);
            query = query.substr(end + 1); 
        } else {
            break;
        }
    }

    for (size_t i = 0; i < queryNumbers.size(); ++i) {
        int refNumber = queryNumbers[i];
        if (references.find(refNumber) != references.end()) {
            cout << references[refNumber] << endl;
        }
    }

    return 0;
}
