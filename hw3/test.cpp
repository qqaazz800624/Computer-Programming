#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#define INITIAL_LINE_LENGTH 50

struct UnitCount {
    int unit_code;
    int count;
};

int find_or_add_unit(std::vector<UnitCount> &units, int unit_code);
bool compare_units(const UnitCount &a, const UnitCount &b);
int stringToInt(const std::string &str);


int main() {
    std::string filename;
    std::cin >> filename;

    std::ifstream file(filename.c_str());  
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    int coupon_counts[4] = {0};  
    std::vector<UnitCount> units;  

    std::string line;
    while (std::getline(file, line)) {
        if (line.length() < 9) continue;

        char type = line[0];
        int type_index;
        if (type == 'A') type_index = 0;
        else if (type == 'B') type_index = 1;
        else if (type == 'C') type_index = 2;
        else if (type == 'D') type_index = 3;
        else continue;  

        coupon_counts[type_index]++;
        
        int unit_code = stringToInt(line.substr(line.size() - 2));

        int index = find_or_add_unit(units, unit_code);
        units[index].count++;
    }

    file.close();

    std::sort(units.begin(), units.end(), compare_units);

    std::cout << "優惠券A: " << coupon_counts[0] << "張\n";
    std::cout << "優惠券B: " << coupon_counts[1] << "張\n";
    std::cout << "優惠券C: " << coupon_counts[2] << "張\n";
    std::cout << "優惠券D: " << coupon_counts[3] << "張\n";

    std::cout << "\n";

    for (size_t i = 0; i < units.size(); i++) {
        std::cout << "單位" << units[i].unit_code << ": " << units[i].count << "張\n";
    }

    return 0;
}

int find_or_add_unit(std::vector<UnitCount> &units, int unit_code) {
    for (size_t i = 0; i < units.size(); i++) {
        if (units[i].unit_code == unit_code) {
            return i;  
        }
    }
    UnitCount newUnit;
    newUnit.unit_code = unit_code;
    newUnit.count = 0;
    units.push_back(newUnit);
    return units.size() - 1;
}

bool compare_units(const UnitCount &a, const UnitCount &b) {
    return a.unit_code < b.unit_code;
}

int stringToInt(const std::string &str) {
    std::stringstream ss(str);
    int num;
    ss >> num;
    return num;
}