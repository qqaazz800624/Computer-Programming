#ifndef VOTESYSTEM_H
#define VOTESYSTEM_H
#include <iostream>

using namespace std;

class Ballot{
    private:
        string ID;
        string Choice;
        bool checked;

    public:
        Ballot();
        Ballot(string ID, string Choice);
        
        bool Verify();
        string getElected();
};

class Vote_sys{
    private:
        Ballot *ballots; 
        int vote_members; 
        int candidates; 
        int *count;
    
    public:
        Vote_sys(int members, int candidates);
        ~Vote_sys();
        
        void add_ballot(Ballot ballot);
        void display();
        void count_vote(string choice);
        void show_result();
};

#endif // VOTESYSTEM_H