//輸入今日出席人數&候選法案數
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "3556_votesystem.h"
using namespace std;
 
int main(){
    string str_in;
 
    string member;
    string candidate;
    cin >> member >> candidate;
    cin.ignore();
    int members = atoi(member.c_str());
    int candidates = atoi(candidate.c_str());
 
    Vote_sys vs(members, candidates);
    while(getline(cin, str_in)){
        if(str_in == "q"){
            break;
        }
        // cout << str_in << endl;    
        string ID = str_in.substr(0, str_in.find(' '));
        string choice = str_in.substr(str_in.find(' ')+1, str_in.length());
        // cout << ID << " " << choice << endl;
 
        Ballot b(ID, choice);
        vs.add_ballot(b);
    }
    vs.display();
    vs.show_result();
 
}