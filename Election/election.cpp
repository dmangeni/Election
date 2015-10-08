#include<iostream>
#include <string>
#include <vector>
#include "candidate.h"
#include "Election.h"

using namespace std;
Election::Election()
{
	filler();
	setCandidates(electionCandidates.size());
}
Election::Election(int n)
{
	setCandidates(n);
}
void Election::setCandidates(int n)
{
	if (n > 0 || n <= electionCandidates.size())
		candidates = n;
	else
		candidates = 5;
}
void Election::filler()
{
	Candidate c1("Barack","Obama","Democratic");
	Candidate c2("Mark", "Mahoney", "Liberitarian");
	Candidate c3("Mitt", "Romney", "Independent");
	Candidate c4("Mwai", "Kibaki", "Alliance");
	Candidate c5("Zara", "Ngozi", "Republican");

	electionCandidates.push_back(c1);
	electionCandidates.push_back(c2);
	electionCandidates.push_back(c3);
	electionCandidates.push_back(c4);
	electionCandidates.push_back(c5);

	ballot = 10;

	for (int i = 0; i < electionCandidates.size(); i++)
	{
		BallotBoxes.push_back(0);
	}
}
void Election::display()
{
	cout << "The following are your candidates nominees:\n\n";
	
	//This ensures only the specified number of candidates beginning from the last one is shown
	for (int i = 0; i < electionCandidates.size(); i++)
	{
		 cout << i+1 << ".";
		 electionCandidates[i].printCandidate();
	}
}
void Election::addCandidate(string fname, string lname, string addparty)
{
	Candidate add(fname,lname,addparty);
	electionCandidates.push_back(add);
}
void Election::toVote()
{
	display();
	int choice;
	cout << "Enter the integer for the candidate you would like to vote for:";
	cin >> choice;
	int p = choice - 1; //subtracting one to specificy the position in the vector
	BallotBoxes[p]++;
	//reset the vote for each candidate after each vote
	electionCandidates[p].setvote(BallotBoxes[p]);
	ballot--;
}
void Election::startVoting()
{
	while (ballot > 0)
	{
		toVote();
	}
}
void Election::sort()
{
	for (int i = 0; i < BallotBoxes.size(); i++)
	{
		for (int j = i + 1; j < BallotBoxes.size(); j++)
		{
			if (BallotBoxes[i] < BallotBoxes[j])
			{
				swap(BallotBoxes[i], BallotBoxes[j]);
				swap(electionCandidates[i], electionCandidates[j]);
			}
		}
	}
}
bool Election::runoff()
{
	sort();
	bool isRunOff = false;
	int search = BallotBoxes[0]; //To track the number of ties for the winning candidates
	CandidatesTied = 1;
	for (int i = 1; i < BallotBoxes.size() - 1; i++)
	{
		if (BallotBoxes[i] == search)
		{
			isRunOff = true;
			CandidatesTied++;
		}
	}
	return isRunOff;
}
void Election::getWinner()
{
	while(runoff() == true)
	{
		vector<Candidate>tiedCandidates;
		for (int i = 0; i < CandidatesTied; i++)
		{
			tiedCandidates.push_back(electionCandidates[i]);
		}
		
		electionCandidates = tiedCandidates;
		BallotBoxes.clear();
		electionCandidates.clear();
		
		for (int i = 0; i < CandidatesTied; i++)
		{
			BallotBoxes.push_back(0);
		}
		ballot = 10;
		Election e2(CandidatesTied);
		CandidatesTied = 0;
		e2.startVoting();
	}
	//president is in the first position
	cout << "Your president is:" << "\n";
	
	string pf = electionCandidates[0].getfirstname();
	string pl = electionCandidates[0].getlastname();
	string pparty = electionCandidates[0].getparty();
	int vote = electionCandidates[0].getvote();
	
	Candidate president(pf, pl, pparty);
	president.setvote(vote);
	president.printCandidate();
}
