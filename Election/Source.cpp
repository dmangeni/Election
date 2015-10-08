#include<iostream>
#include <string>
#include <vector>
#include "candidate.h"
#include "Election.h"

using namespace std;
int main()
{
	Election e1;
	e1.startVoting();
	e1.getWinner();
	
	system("pause");
	return 0;
}