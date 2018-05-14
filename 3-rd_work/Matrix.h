#pragma once
#include <iostream>
#include <string>

using namespace std;

class Matrix
{
private:
	int** matrix;
	int columns;
	int rows;

public:
	Matrix(ifstream &file_input);
	Matrix(int rows, int columns);
	int getColumns();
	int getRows();
	void setMatrixElement(int row, int column, int element);
	void print_matrix(string sort_name);
	void print_matrix_to_file(ofstream &out);
	int* operator[](int i) {
		return matrix[i];
	}
	Matrix(const Matrix &matrix);
	Matrix Matrix::operator=(Matrix &matrix);
};