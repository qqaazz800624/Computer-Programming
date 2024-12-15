#include <iostream>

using namespace std;

int main(){
    int score, grade;
    cin >> grade;

    if (grade != 1 && grade != 2){
        cout << "role error" << endl;
        return 0;
    }

    cin >> score;

    if (score < 0 || score > 100){
        cout << "score error" << endl;
        return 0;
    }

    if (score < 60 && grade == 1){
        cout << "fail" << endl;
    }
    else if (score < 70 && grade == 2){
        cout << "fail" << endl;
    }
    else{
        cout << "pass" << endl;
    }

    return 0;
}