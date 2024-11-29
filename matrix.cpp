#include "matrix.h"

Matrix::Matrix(const int Order) {
	// we create a vector of vectors with order number of elements and elements vector of double values 0
	M = vector<vector<double>>(Order, vector<double>(Order, 0));

	for (int i = 0; i < Order; i++) {
		M[i][i] = 1; // matrix of ones
	}
}

Matrix::Matrix(const Matrix& Other) {
	this->M = Other.M; // copying vectors
}

Matrix::Matrix(vector<vector<double>> Data) {
	M = Data; // vectors copy themselves
}

double Matrix::Determinant() const {
	double d = 0;

	switch (Order()) {
		case 1:
			d = M[0][0];
			break;
		case 2:
			d = Det2();
			break;
		case 3:
			d = Det3();
			break;
		default:
			d = Det4(); // all methods Detx() must be const because the Determinant() method itself is const
			break;
	}
	return d;
}

int Matrix::Order() const {
	return M.size();
}

double Matrix::GetAt(const int Row, const int Column) const {
	return M[Row][Column];
}

void Matrix::SetAt(const int Row, const int Column, const double NewWalue) {
	M[Row][Column] = NewWalue;
}

void Matrix::Report() const {
	cout << "Matrix M:\n";
	for (int i = 0; i < Order(); i++) {
		cout << "\t|\t";
		for (int j = 0; j < Order(); j++) {
			cout << M[i][j] << "\t";		
		}
		cout << "|\t" << endl;
	}
	// or other way....
	/*for (const vector<double>& row : M) { // constant reference - temorary copy wont be made
	// but the reference will be used...data wont change and we can work with it as variable
		for (double element : row) {
			cout << element << "\t";
		}
		cout << endl;
	}*/
}

double Matrix::Det2() const {
	return (M[0][0] * M[1][1]) - (M[1][0] * M[0][1]);
}

double Matrix::Det3() const {
	return (M[0][0] * M[1][1] * M[2][2]) + (M[0][2] * M[1][0] * M[2][1]) 
		+ (M[0][1] * M[1][2] * M[2][0]) - (M[0][2] * M[1][1] * M[2][0]) 
		- (M[0][0] * M[1][2] * M[2][1]) - (M[0][1] * M[1][0] * M[2][2]);
}

double Matrix::Det4() const {

	Matrix local = *this;
	double det = 1.0;
	bool rowSwapped = false;

	for (int i = 0; i < Order(); i++) {
		// If the pivot element is zero, swap rows with a non-zero element in the same column
		if (local.GetAt(i, i) == 0) {
			
			for (int j = i + 1; j < Order(); j++) {
				if (local.GetAt(j, i) != 0) {

					swap(local.M[i], local.M[j]);

					det = det * -1; // Row swap changes sign of determinant
					rowSwapped = true;
					break;
				}
			}
		}

		// Perform row reduction to eliminate elements below the pivot
		for (int j = i + 1; j < Order(); j++) {
			double factor = local.GetAt(j, i) / local.GetAt(i, i);
			for (int k = i; k < Order(); k++) {

				double temp = local.GetAt(j, k);
				temp -= factor * local.GetAt(i, k);
				local.SetAt(j, k, temp);
			}
		}
	}

	// After reduction, the determinant is the product of diagonal elements
	for (int i = 0; i < Order(); i++) {
		det = det * local.GetAt(i, i);
	}

	return det;
}

