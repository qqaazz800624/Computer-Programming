#include "3556_votesystem.h"
#include <sstream>
#include <iostream>
#include <string>

Ballot::Ballot(){
    ID = "";
    Choice = "";
    checked = false; 
}

Ballot::Ballot(string ParamID, string ParamChoice){
    ID = ParamID;
    Choice = ParamChoice;
    checked = false;
}

bool Ballot::Verify(){
    cout << "Ballot ID: " << ID << " "  << Choice << endl;

    if (ID == "N" || Choice == "N"){
        cout << "Invalid ballot." << endl;
        checked = false;
        return false;
    }

    cout << "Ballot ID: " << ID << " has been checked." << endl;
    checked = true;
    return true;
}

string Ballot::getElected(){
    return Choice;
}

Vote_sys::Vote_sys(int ParamMembers, int ParamCandidates){
    vote_members = 0;
    candidates = ParamCandidates;
    ballots = new Ballot[ParamMembers];
    count = new int[ParamCandidates]();
}

Vote_sys::~Vote_sys(){
    delete [] ballots;
    delete [] count;
}

void Vote_sys::add_ballot(Ballot ballot){
    ballots[vote_members++] = ballot;
}

void Vote_sys::count_vote(string Choice){
    stringstream ss(Choice);
    int choiceIndex;
    ss >> choiceIndex;
    choiceIndex -= 1;
    if (choiceIndex >= 0 && choiceIndex < candidates){
        count[choiceIndex]++;
    }
}

void Vote_sys::display(){
    int i;
    for (i=0; i<vote_members; i++){
        if (ballots[i].Verify()){
            count_vote(ballots[i].getElected());
        }
    }
}

void Vote_sys::show_result(){
    cout << "Vote Members: " << vote_members << endl;
    cout << "Candidates: " << candidates << endl;

    int i;
    int maxVotes = 0;
    int electedCandidate = 0;
    for (i=0; i<candidates; i++){
        cout << count[i] << " ";
        if (count[i] > maxVotes){
            maxVotes = count[i];
            electedCandidate = i + 1;
        }
    }
    cout << endl;
    cout << "The elected candidate is: " << electedCandidate << endl;
}