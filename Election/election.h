#pragma once
#include<iostream>
#include <string>
#include <vector>
#include "candidate.h"

using namespace std;

class Election
{
public:
	Election();
	Election(int n);
	void setCandidates(int n);
	void filler();
	void display();
	void toVote();
	void startVoting();
	void addCandidate(string fname, string lname, string addparty);
	void sort();
	bool runoff();
	void setElection();
	void getWinner();
	
private:
	vector<Candidate>electionCandidates; //stores the participating candidates details
	vector<int>BallotBoxes;
	int ballot;
	int candidates;
	int CandidatesTied;
};