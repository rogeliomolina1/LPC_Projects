//============================================================================
// Name        : VoteCount.cpp
// Author      : Rogelio Molina
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include<vector>
using namespace std;

int total = 0;
void ReportResult(map<string, int> election);
void GetCandidates(map<string, int> &election);

int main() {
	map<string, int> election;
	vector<string> candidates;
	GetCandidates(election);
	ReportResult(election);
	return 0;
}

void ReportResult(map<string, int> election) {
	vector<int> VoteCount;
	vector<string> candidates;
	map<string, int>::const_iterator iter;
	for (iter = election.begin(); iter != election.end(); iter++) {
		candidates.push_back(iter->first);
		VoteCount.push_back(iter->second);
	}
	for (unsigned int i = 0; i < candidates.size(); i++) {
		cout << endl << candidates[i] << " got " << VoteCount[i] << " votes.\n";
	}

//////////////////////////////////////////////////////////
	string PluralityWinner;
	string MajorityWinner;
	int largestNum = 0;
	bool tie = false;
	bool majority = false;

////////Check for majority winner/////////////////
	for (unsigned int j = 0; j < VoteCount.size(); j++) {
		if (VoteCount[j] > total / 2) {
			MajorityWinner = candidates[j];
			cout << "\nWinner!: " << MajorityWinner << endl;
			majority = true;
		}
	}
////////////Plurality winner/////////////////////
	if (MajorityWinner.size() == 0) {
		for (unsigned int k = 0; k < VoteCount.size(); k++) {
			if (largestNum <= VoteCount[k]) {
				largestNum = VoteCount[k];
				PluralityWinner = candidates[k];
			}
		}
		///////////////tie//////////////
		for (unsigned int l = 0; l < VoteCount.size(); l++) {
			if (largestNum == VoteCount[l]
					&& candidates[l] != PluralityWinner) {
				tie = true;
			}
		}
	}
////////////check for a tie////////////
	if (tie) {
		cout << "\nTie between: \n";
		for (unsigned int m = 0; m < VoteCount.size(); m++) {
			if (largestNum == VoteCount[m]
					&& candidates[m] != PluralityWinner) {
				cout << candidates[m] << endl;
			}
		}
		cout << PluralityWinner << endl;
	}
////////////check for majority and tie////////////
	if (!majority && !tie) {
		cout << endl << PluralityWinner << " received a plurality of votes\n";
	}

	cout << endl << "Total Votes: " << total << endl;
//////////////////////////////////////////////////////////

}
void GetCandidates(map<string, int> &election) {
	string candidate;
	cout << "Please enter your votes: \n";
	while (true) {
		getline(cin, candidate);
		if (candidate == "DONE" || candidate == "done" || candidate == "Done") {
			break;
		}
		if (election.find(candidate) == election.end()) {
			election[candidate] = 1;
			total++;
		} else {
			election[candidate] += 1;
			total++;
		}
	}
}
