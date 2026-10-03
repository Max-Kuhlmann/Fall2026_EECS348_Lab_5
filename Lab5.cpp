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

vector<vector<int>> multiply(vector<vector<int>> matrix1, vector<vector<int>> matrix2) {
	vector<vector<int>> finalMatrix;
	for(int i = 0; i < matrix1.size(); i++) {
		vector<int> tempRow;
		for(int j = 0; j < matrix1[i].size(); j++) {
			int tempVal = 0;
			for(int k = 0; k < matrix1[i].size(); k++) {
				tempVal += matrix1[i][k] * matrix2[k][j];
			}
			tempRow.push_back(tempVal);
		}
		finalMatrix.push_back(tempRow);
	}
	return finalMatrix;
}

void diag(vector<vector<int>> matrix) {
	int count = 0;
	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix.size(); j++) {
			if(i == j) {
				count += matrix[i][j];
			}
		}
	}
	cout << "Main diagonal sum: " << count << endl;
	count = 0;
	for(int i = 0; i < matrix.size(); i++) {
		for(int j = 0; j < matrix.size(); j++) {
			if(j == (matrix.size() - (i + 1))) {
				count += matrix[i][j];
			}
		}
	}
	cout << "Secondary diagonal sum: " << count << endl;
}

void rowSwap(vector<vector<int>> matrix, int row1, int row2) {
	vector<int> temp = matrix[row1];
	matrix[row1] = matrix[row2];
	matrix[row2] = temp;
	printMatrix(matrix);
}

void colSwap(vector<vector<int>> matrix, int col1, int col2) {
	for(int i = 0; i < matrix.size(); i++) {
		int temp = matrix[i][col1];
		matrix[i][col1] = matrix [i][col2];
		matrix[i][col2] = temp;
	}
	printMatrix(matrix);
}

vector<vector<int>> updateMatrix(vector<vector<int>> matrix, int newVal, int row, int col) {
	matrix[row][col] = newVal;
	return matrix;
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
		} else if(action == 2) {
			cout << "A * B:" << endl;
			printMatrix(multiply(matrix1, matrix2));
		} else if(action == 3) {
			char whichMatrix;
			cout << "(A) or (B): ";
			cin >> whichMatrix;
			if(whichMatrix == 'A') {
				cout << "Diagonal sums for Matrix A:" << endl;
				diag(matrix1);
			} else {
				cout << "Diagonal sums for Matrix B:" << endl;
				diag(matrix2);
			}
		} else if(action == 4) {
			char whichMatrix;
			int row1, row2;
			cout << "(A) or (B): ";
			cin >> whichMatrix;
			cout << "Input rows: ";
			cin >> row1 >> row2;
			cout << "Rows " << row1 << " and " << row2 << " swapped:" << endl;
			if(whichMatrix == 'A') {
				rowSwap(matrix1, row1, row2);
			} else {
				rowSwap(matrix2, row1, row2);
			}
		} else if(action == 5) {
			char whichMatrix;
			int col1, col2;
			cout << "(A) or (B): ";
			cin >> whichMatrix;
			cout << "Input rows: ";
			cin >> col1 >> col2;
			cout << "Columns " << col1 << " and " << col2 << " swapped:" << endl;
			if(whichMatrix == 'A') {
				colSwap(matrix1, col1, col2);
			} else {
				colSwap(matrix2, col1, col2);
			}
		} else if(action == 6) {
			char whichMatrix;
			int newVal, row, col;
			cout << "(A) or (B): ";
			cin >> whichMatrix;
			cout << "Input new value: ";
			cin >> newVal;
			cout << "Input row and column: ";
			cin >> row >> col;
			cout << "Updated matrix: " << endl;
			if(whichMatrix == 'A') {
				matrix1 = updateMatrix(matrix1, newVal, row, col);
				printMatrix(matrix1);
			} else {
				matrix2 = updateMatrix(matrix2, newVal, row, col);
				printMatrix(matrix2);
			}
		} else {
			looping = false;
		}
	}
	return 0;
}
