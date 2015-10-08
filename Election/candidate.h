#pragma once
#include<iostream>
#include <string>
#include <vector>

using namespace std;

class Candidate
{
public:
	Candidate(string n,string l, string p);
	void setvote(int n);
	void switcher(string& word);
	void printCandidate();
	string getfirstname();
	string getlastname();
	string getparty();
	int getvote();
private:
	string firstname;
	string lastname;
	string party;
	int vote;
};