#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

void YEAR(int n, const vector<string> &lst);

int main(){
    string input;
    vector<string> years;

    while (1){
        cin >> input;

        if (input == "q"){
            break;
        }

        years.push_back(input);
    }

    YEAR(years.size(), years);

    return 0;
}

void YEAR(int n, const vector<string> &lst){
    const char *heavenly_stems[] = {"甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"};
    const char *earthly_branches[] = {"子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥"};
    int i;

    for (i=0; i<n; i++){
        int year = atoi(lst[i].c_str());

        int heavenly_position = (year - 3) % 10;
        heavenly_position = heavenly_position - 1;
        if (heavenly_position < 0){
            heavenly_position += 10;
        }

        int earthly_position = (year - 3) % 12;
        earthly_position = earthly_position - 1;
        if (earthly_position < 0){
            earthly_position += 12;
        }
        cout << year << " = " << heavenly_stems[heavenly_position] << earthly_branches[earthly_position] << "年" << endl;
    }
}