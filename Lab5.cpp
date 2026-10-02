#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

void printMatrix(vector<vector<int>> matrix) {
	for(auto& row : matrix) {
                for(int val : row) {
                        cout << val << "\t";
                }
                cout << endl;
        }
}

vector<vector<int>> add(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {
	vector<vector<int>> finalMatrix;
	for(int i = 0; i < matrix1.size(); i++) {
		vector<int> tempRow;
		for(int j = 0; j < matrix1[i].size(); j++) {
			tempRow.push_back(matrix1[i][j] + matrix2[i][j]);
		}
		finalMatrix.push_back(tempRow);
	}
	return finalMatrix;
}

int main() {
	string filename;
	string fileline;
	cout << "Enter input filename: ";
	cin >> filename;
	ifstream myFile(filename);
	int currRow = -1;
	int size;
	vector<vector<int>> matrix1;
	vector<vector<int>> matrix2;
	while(getline(myFile, fileline)) {
		if(currRow == -1) {
			size = stoi(fileline);
		} else {
			vector<int> tempRow;
			string member;
			stringstream filelineStream(fileline);
			while(getline(filelineStream, member, ' ')) {
			       tempRow.push_back(stoi(member));
			}
			if(currRow < size) {
				matrix1.push_back(tempRow);
			} else {
				matrix2.push_back(tempRow);
			}
		}
		currRow++;
	}
	myFile.close();
	cout << "Matrix A:" << endl;
	printMatrix(matrix1);
	cout << "Matrix B:" << endl;
	printMatrix(matrix2);
	for(auto& row : matrix2) {
		for(int val : row) {
			cout << val << "\t";
		}
		cout << endl;
	}
	
	bool looping = true;
	int action;
	while(looping) {
		cout << "Would you like to" << endl <<
			"(1) Add" << endl <<
			"(2) Multiply" << endl <<
			"(3) Diagonal Sum" << endl <<
			"(4) Swap Rows" << endl <<
			"(5) Swap Columns" << endl <<
			"(6) Update Matrix" << endl <<
			"(7) Quit" << endl <<
			">> ";
		cin >> action;
		if(action == 1) {
			cout << "A + B:" << endl;
			printMatrix(add(matrix1, matrix2));
		}
		else {
			looping = false;
		}
	}
	return 0;
}
