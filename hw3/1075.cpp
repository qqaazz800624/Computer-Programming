#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#define MAX_AGES 10000

void merge(const vector<int> &ages1, const vector<int> &ages2, vector<int> &merged);

int main() {
    string file1, file2;
    string path1 = "../app/";
    string path2 = "../app/";

    cin >> file1;
    cin >> file2;

    path1 += file1;
    path2 += file2;

    ifstream fp1(path1.c_str());
    ifstream fp2(path2.c_str());

    if (!fp1 || !fp2) {
        cerr << "Error opening files." << endl;
        return 1;
    }

    vector<int> ages1, ages2;

    int age;
    while (fp1 >> age) {
        ages1.push_back(age);
    }
    fp1.close();

    while (fp2 >> age) {
        ages2.push_back(age);
    }
    fp2.close();

    vector<int> merged;
    merge(ages1, ages2, merged);
    size_t i;

    for (i = 0; i < merged.size(); i++) {
        cout << merged[i] << " ";
    }
    cout << endl;
    
    return 0;
}

void merge(const vector<int> &ages1, const vector<int> &ages2, vector<int> &merged){
    size_t i = 0, j = 0;
    while (i < ages1.size() && j < ages2.size()){
        if (ages1[i] < ages2[j]){
            merged.push_back(ages1[i]);
            i++;
        } else {
            merged.push_back(ages2[j]);
            j++;
        }
    }

    while (i < ages1.size()){
        merged.push_back(ages1[i]);
        i++;
    }

    while (j < ages2.size()){
        merged.push_back(ages2[j]);
        j++;
    }
}
