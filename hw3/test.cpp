#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    
    string filename;
    cin >> filename;

    string output_filename = filename;
    output_filename[0] = 'w';

    ifstream input_file(filename.c_str());
    if (!input_file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    vector<int> numbers;

    int sum = 0;
    int num, i;

    while (input_file >> num) {
        numbers.push_back(num);
        sum += num;
    }
    input_file.close();

    double average = 0.0;
    if (!numbers.empty()) {
        average = (double)sum / numbers.size();
    }

    cout << sum << endl;
    cout << fixed << setprecision(2);
    cout << average << endl;

    ofstream output_file(output_filename.c_str());
    if (!output_file.is_open()) {
        cerr << "Error: Could not open file " << output_filename << " for writing" << endl;
        return 1;
    }

    for (size_t i = 0; i < numbers.size(); i++){
        output_file << numbers[i] << " ";
    }
    output_file << endl;
    output_file << sum << endl;
    output_file << fixed << setprecision(2);
    output_file << average << endl;
    output_file.close();

    return 0;
}
