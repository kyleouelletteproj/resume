/* Kyle Ouellette
CSC 2710
10/7/19
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#define INFINITY 2000
using namespace std;
void floyd(int **D, int **P, int v);
void storeA(int **matrix,ifstream &inFile);
void output(int **matrix, int v, ofstream& x);
void storeB(int **matrix, int v);
void initializeArray(int **matrix, int v);
void outputAll(int **a, int **b, int vertices, ofstream& outFile);
int main() {
	ifstream inFile;
	ofstream outFile;
	outFile.open("output.txt");
	inFile.open("gfw1.dat");
	int vertices,edges;
	inFile >> vertices >> edges;
	int **a;
	int **b;
	a = new int*[vertices];
	b = new int*[vertices];
	initializeArray(a,vertices);
	initializeArray(b, vertices);
	storeA(a,inFile);
	storeB(b, vertices);
	outputAll(a,b,vertices,outFile);
	return 0;
}

void floyd(int **D, int **P,int v) {
	for(int k = 0; k < v; k++) {
		for(int i = 0; i < v; i++) {
			for(int j = 0; j < v; j++) {
				if(D[i][k]+D[k][j] < D[i][j]){
					P[i][j] = k;
					D[i][j] = D[i][k]+D[k][j];
				}
			}
		}
	}
}

void storeA(int **matrix, ifstream& inFile) {
	int v1, v2, weight;
	while(!inFile.eof()) {
		inFile >> v1;
		inFile >> v2;
		inFile >> weight;
		matrix[v1-1][v2-1] = weight;
	}
	inFile.close();
}
void storeB(int **matrix, int v) {
	for(int i = 0; i < v; i++) {
		for(int j=0; j < v; j++) {
	matrix[i][j] = 0;
	}
	}
}
void initializeArray(int **matrix, int v) {
	for(int i = 0; i < v; i++) {
	matrix[i] = new int[v];
	}
	for(int i = 0; i < v; i++) {
		for(int j=0; j < v; j++) {
		if(i==j) {
			matrix[i][j] = 0;
		} else {
		matrix[i][j] = INFINITY;	
		}
	}
	}
	
}
void output(int **matrix,int v, ofstream& x) {
	for(int i = 0; i < v; i++) {
	for(int j = 0; j < v; j++) {
		x << setw(6) <<matrix[i][j] << " ";
	}
		x << endl;
	}
}
void outputAll(int **a, int **b,int vertices, ofstream& outFile) {
	outFile << setw(26) <<"Original A" << endl;
	output(a,vertices,outFile);
	outFile << endl;
	outFile << setw(26) <<"Original B" << endl;
	output(b,vertices,outFile);
	outFile << endl;
	floyd(a,b,vertices);
	outFile << setw(26) <<"Final A" << endl;
	output(a,vertices, outFile);
	outFile << endl;
	outFile << setw(26) <<"Final B" << endl;
	output(b,vertices,outFile);
	
}