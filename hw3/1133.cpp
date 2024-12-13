#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    
    string filename;
    cin >> filename;
    ifstream input_file(filename.c_str());
    if (!input_file) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    int pistol_count = 0, smg_count = 0, shotgun_count = 0, ar_count = 0, sniper_count = 0;
    string gun_name;

    while (input_file >> gun_name){
        if (gun_name.find("PISTOL") != string::npos) {
            pistol_count++;
        } else if (gun_name.find("SMG") != string::npos) {
            smg_count++;
        } else if (gun_name.find("SHOTGUN") != string::npos) {
            shotgun_count++;
        } else if (gun_name.find("AR") != string::npos) {
            ar_count++;
        } else if (gun_name.find("SNIPER") != string::npos) {
            sniper_count++;
        }
    }
    input_file.close();

    cout << pistol_count << " " << smg_count << " " << shotgun_count << " " << ar_count << " " << sniper_count << endl;
    
    return 0;
}
