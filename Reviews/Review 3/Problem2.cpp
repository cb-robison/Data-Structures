#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<string>> GeneratePossibleCommittees(const vector<string>& candidates, int committee_size);
void GeneratePossibleCommittees(const vector<string>& candidates, int committee_size, vector<string> new_committee, vector<vector<string>>& possible_committees, int i);
int main() {
	vector<string> candidates = { "Bob", "Bill", "Stan", "Ken"};
	int size = 3;

	vector<vector<string>> possible_committees = GeneratePossibleCommittees(candidates, size);

	cout << "Possible Committees: " << endl;
	for (int i = 0; i < possible_committees.size(); i++) {
		for (int j = 0; j < possible_committees[i].size(); j++) {
			cout << possible_committees[i][j];
			
			if (j != possible_committees[i].size() - 1)
				cout << ", ";
		}
		cout << endl;
	}
};

vector<vector<string>> GeneratePossibleCommittees(const vector<string>& candidates, int committee_size) {
	vector<vector<string>> committee_list;

	for (int i = 0; i <= candidates.size() - committee_size; i++) {
		vector<string> new_committee;

		GeneratePossibleCommittees(candidates, committee_size, new_committee, committee_list, i);
	}

	return committee_list;

}

void GeneratePossibleCommittees(const vector<string>& candidates, int committee_size, vector<string> new_committee, vector<vector<string>>& possible_committees, int i) {
	new_committee.push_back(candidates[i]);

	if (new_committee.size() == committee_size) {
		possible_committees.push_back(new_committee);
		return;
	}
	else {
		for (int j = i + 1; j < candidates.size(); j++) {
			GeneratePossibleCommittees(candidates, committee_size, new_committee, possible_committees, j);
		}
	}
}