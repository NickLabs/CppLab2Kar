#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>


using namespace std;
//Переделать под row, column
Matrix::Matrix(ifstream &file_input)
{
	int count_space = 0;
	char symbol;

	file_input.seekg(0, ios::beg);
	file_input.clear();

	while (!file_input.eof())
	{
		file_input.get(symbol);
		if (symbol == ' ') count_space++;
		if (symbol == '\n') break;
	}
	this->size = count_space + 1;

	file_input.seekg(0, ios::beg);
	file_input.clear();

	this->matrix = new int*[rows];
	for (int i = 0; i < this->rows; i++) {
		matrix[i] = new int[columns];
		for (int j = 0; j < this->columns; j++) {
			file_input >> this->matrix[i][j];
		}
	}
}

Matrix::Matrix(int Y, int X)
{
	this->rows = Y;
	this->columns = X;
	this->matrix = new int*[Y];
	for (int i = 0; i < Y; i++) {
		this->matrix[i] = new int[X];
	}
}

void Matrix::print_matrix()
{
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			cout << this->matrix[i][j] << ' ';
		}
		cout << endl;
	}
}

int Matrix::getRows() {
	return this->rows;
}

int Matrix::getColumns() {
	return this->columns;
}

void Matrix::setMatrixElement(int row ,int column, int element) {
	this->matrix[row][column] = element;
}


void Matrix::print_matrix_to_file(ofstream &out) {
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			out << this->matrix[i][j] << ' ';
		}
		out << endl;
	}
	out << endl;
	out.close();
}