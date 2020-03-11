/*
Kyle Ouellette
Project 1
CSC 1720-02
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
	
bool running = true;
int response;
struct footballPlayer {
string name;
string position;
int touchdowns;
int catches;
int passingYards;
int receivingYards;
int rushingYards;
};
footballPlayer players[10];
ifstream inFile;
ofstream outFile;
inFile.open("data.txt");
outFile.open("outData.txt");

for(int i = 0; i < 10; i++) {
inFile >> players[i].name >> players[i].position >> players[i].touchdowns >> players[i].catches
>> players[i].passingYards >> players[i].receivingYards >> players[i].rushingYards;
}
while(running == true) {
	cout << "Name"<< "\t"<< "Position" << "\t" << "Touchdowns"<< "\t" << "Catches" << "\t\t" << "Pass Yards"
	<< "\t" << "Rec Yards" << "\t" << "Rush Yards" << endl;
	for(int i = 0; i < 10; i++) {
	cout << players[i].name << "\t" <<players[i].position << "\t" << players[i].touchdowns << "\t\t" << players[i].catches
	<< "\t\t" << players[i].passingYards << "\t\t" << players[i].receivingYards << "\t\t" << players[i].rushingYards << endl;
	}
	cout << "1. Edit Player Data" << endl;
	cout << "2. Save Data" << endl;
	cout << "3. Exit" << endl;
	cin >> response;
if(response != 1 && response != 2 && response != 3) {
	cout << "Invalid Input. Please try again." << endl;
	cin >> response;
	continue;
	}
	if(response == 1) {
	cout << "Who would you like to edit?" << endl;
	for(int i = 0; i < 10; i++) {
	cout << i+1 <<". " <<players[i].name << endl;
	}
	cin >> response;
	cout << "What would you like to edit?" << endl;
	cout << "1. Name" << endl << "2. Position" << endl <<"3. Touchdowns" << endl << "4. Catches" << endl << "5. Passing Yards" << endl << "6. Rec Yards" << endl << "7. Rush Yards"
	<< endl;
	int responseTwo;
	cin >> responseTwo;
	cout << "Enter New Data" << endl;
	string dataString;
	int dataInt;
	if(responseTwo == 1) {
	cin >> dataString;
	players[response-1].name = dataString;
	continue;
	}
	if(responseTwo == 2) {
	cin >> dataString;
	players[response-1].position = dataString;
	continue;
	}
	if(responseTwo == 3) {
	cin >> dataInt;
	players[response-1].touchdowns = dataInt;
	continue;
	}
	if(responseTwo == 4) {
	cin >> dataInt;
	players[response-1].catches = dataInt;
	continue;
	}
	if(responseTwo == 5) {
	cin >> dataInt;
	players[response-1].passingYards = dataInt;
	continue;
	}
	if(responseTwo == 6) {
	cin >> dataInt;
	players[response-1].receivingYards = dataInt;
	continue;
	}
	if(responseTwo == 7) {
	cin >> dataInt;
	players[response-1].rushingYards = dataInt;
	continue;
	}
	}
	if(response == 2) {
		outFile << "Name"<< "\t"<< "Position" << "\t" << "Touchdowns"<< "\t" << "Catches" << "\t\t" << "Pass Yards"
		 << "\t" << "Rec Yards" << "\t" << "Rush Yards" << endl;
		for(int i = 0; i < 10; i++) {
	outFile << players[i].name << "\t" <<players[i].position << "\t" << players[i].touchdowns << "\t\t" << players[i].catches
	<< "\t\t" << players[i].passingYards << "\t\t" << players[i].receivingYards << "\t\t" << players[i].rushingYards << endl;
}
		running = false;
	}
	if(response == 3) {
		running = false;
	}
}
return 0;
inFile.close();
outFile.close();

}