#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main() {
	//Declare a struct of each person
	struct data {
		int age;
		string firstName;
		string lastName;
	};
	//Open the infile and outfile and declare ofstream and ifstream
	int lineCount = 0;
	string line;
	ifstream inFile;
	ofstream outFile;
	inFile.open("data.txt");
	outFile.open("output.txt");
	
	//Get amount of lines, assuming a line is a person
	ifstream file("data.txt");
	while(getline(file,line)) {
		lineCount++;
	}
	//Declare an array for the amount of people are in the data file
	data personData[lineCount];
	//Store all data in the array of data structs
	for(int i = 0; i < lineCount; i ++) {
		inFile >> personData[i].firstName >> personData[i].lastName >> personData[i].age;
	}
	
	//Sort the struct by exchange sort
	data temp;
	for(int inc = 0; inc < lineCount; inc++) {
		for( int x = 0; x < lineCount; x++) {
			if(personData[inc].lastName < personData[x].lastName) {
				temp = personData[inc];
				personData[inc] = personData[x];
				personData[x] = temp;
			}
			if(personData[inc].lastName == personData[x].lastName) {
				if(personData[inc].firstName < personData[x].firstName) {
					temp = personData[inc];
					personData[inc] = personData[x];
					personData[x] = temp;
				}
			}
		}
	}
	
	//Output the organized array to the outfile
	for(int i = 0; i < lineCount; i++) {
		outFile << personData[i].lastName << ", " << personData[i].firstName << " - " << personData[i].age << endl;
	}
	return 0;
}