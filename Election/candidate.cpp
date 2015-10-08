#include <iostream>
#include <vector>
#include <string>
#include "candidate.h"

using namespace std;

Candidate::Candidate(string n,string l,string p)
{
	setvote(0);
	firstname =  n;
	lastname = l;
	party = p;
}

void Candidate::setvote(int n)
{
	if (n > 0)
		vote = n;
	else
		vote = 0;
}
void Candidate::switcher(string& word)
{
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] >= 'A' && word[i] <= 'Z')
			word[i] = word[i] + 32;
		else
			word[i] = word[i];
	}
}
void Candidate::printCandidate()
{
	switcher(party); //Switch to lowercase first then convert the first letter to uppercase
	switcher(firstname);
	switcher(lastname);
	
	firstname[0] = firstname[0] - 32;
	lastname[0] = lastname[0] - 32;
	party[0] = party[0] - 32;
	
	cout << getfirstname() << " " << getlastname() << " :" << getparty() <<" " << "Party" << ":" <<" " << getvote() <<endl;
}
string Candidate::getfirstname()
{
	return firstname;
}
string Candidate::getlastname()
{
	return lastname;
}
string Candidate::getparty()
{
	return party;
}
int Candidate::getvote()
{
	return vote;
}
