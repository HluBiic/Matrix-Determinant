#pragma once

#include <vector>
#include <iostream>
using namespace std;

class Matrix {
public:
	// constructor - creates matrix of ones with given order
	Matrix(const int Order);
	// copy constructor
	Matrix(const Matrix& Other);
	// copy constructor
	Matrix(vector<vector<double>> Data);

	// calls functions for determinant calculation for matrixes of various order
	double Determinant() const;
	// return the order of the matrix
	int Order() const;
	// returns the element at given position
	double GetAt(const int Row, const int Column) const;
	// changes element at given position for a new element
	void SetAt(const int Row, const int Column, const double NewWalue);
	// prints matrix to the console
	void Report() const;

private:
	// calculation of determinant of matrix with order 2 via rule of sarrus
	double Det2() const;
	// calculation of determinant of matrix with order 3 via rule of sarrus
	double Det3() const;
	// calculation of determinant of matrix with order 4 via gauss elimination method and upper triangual form of matrix
	double Det4() const;
	// matrix M
	vector<vector<double>> M;
};