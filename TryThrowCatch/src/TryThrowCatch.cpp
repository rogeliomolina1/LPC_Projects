#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class TeamMember {
private:
	string firstName;
	string lastName;
public:
	/// Construct a TeamMember object
	TeamMember(string line);
	void Describe() const;

	class NameException {
	private:
		string message;
	public:
		NameException(string message) {
			this->message = message;
		}
		string GetMessage() const {
			return message;
		}
	};

};

TeamMember::TeamMember(string line) {
	if (line == "")
		throw NameException("blank name");

	unsigned int position = line.find(" ");
	if (position > line.length())
		throw NameException("must have first AND last name");

	firstName = line.substr(0, position);
	lastName = line.substr(position + 1);

	if (lastName.find(" ") < lastName.length())
		throw NameException("must only have two names");
}

void TeamMember::Describe() const {
	cout << lastName << ", " << firstName << endl;
}

vector<TeamMember> GetTeamFromFile();

int main() {
	try {
		vector<TeamMember> team = GetTeamFromFile();
		cout << "Here is your superhero team!" << endl;
		for (unsigned int i = 0; i < team.size(); i++) {
			team[i].Describe();
		}
	} catch (string& message) {
		cout << "Error: " << message << endl;
	} catch (TeamMember::NameException& e) {
		cout << "Error: " << e.GetMessage() << endl;
	}
}

vector<TeamMember> GetTeamFromFile() {
	vector<TeamMember> result;

	string fileName;
	cout << "Give me the filename containing team data: ";
	getline(cin, fileName);

	/// 1) Create a stream
	ifstream fin;

	/// 2) Connect the stream using .open()
	fin.open(fileName.c_str());

	/// 2a) Check for failure
	if (fin.fail())
		throw string("Could not open file " + fileName);

	/// 3) Use the stream to get input
	int lineNumber = 1;
	do {
		string fileLine;
		getline(fin, fileLine);
		cout << "Reading line #" << lineNumber << endl;
		TeamMember temp(fileLine);
		result.push_back(temp);
		lineNumber++;
	} while (!fin.eof());

	/// 4) Close the file
	fin.close();

	return result;
}
