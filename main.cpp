#include "matrix.h"

int main() {
	vector<vector<double>> data1 = {
	{5.6}
	}; // expected output 5.6

	vector <vector<double>> data2 = {
		{3, 7},
		{1, -4}
	}; // expected output -19

	vector <vector<double>> data3 = {
		{2, 4, 6},
		{2, 3, 4},
		{3, 4, 5}
	}; // expected output 0

	vector<vector<double>> data4 = {
		{-3, -1, -3, 4, -3},
		{-7, -1, -10, 5, -2},
		{4, 0, 6, -4, -1},
		{5, 1, 10, -4, 5},
		{5, 3, 4, -4, 3}
	}; // expected output 270

	Matrix* m1 = new Matrix(data1);
	m1->Report();	
	cout << "\nDeterminant of matrix M1: " << m1->Determinant() << endl;
	cout << "-------------------------------------------------------" << endl;

	Matrix* m2 = new Matrix(data2);
	m2->Report();
	cout << "\nDeterminant of matrix M2: " << m2->Determinant() << endl;
	cout << "-------------------------------------------------------" << endl;

	Matrix* m3 = new Matrix(data3);
	m3->Report();
	cout << "\nDeterminant of matrix M3: " << m3->Determinant() << endl;
	cout << "-------------------------------------------------------" << endl;

	Matrix* m4 = new Matrix(data4);
	m4->Report();
	cout << "\nDeterminant of matrix M4: " << m4->Determinant() << endl;
}