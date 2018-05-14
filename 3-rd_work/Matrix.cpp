#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>


using namespace std;

Matrix::Matrix(ifstream &file_input)
{
	int count_space = 0;
	int lines = 0;
	char symbol = ' ';
	while (symbol != '|' && !file_input.eof()) {
		file_input.get(symbol);
		if (symbol == '\n') lines++;
	}

	file_input.seekg(0, ios::beg);
	file_input.clear();

	while (!file_input.eof())
	{
		file_input.get(symbol);
		if (symbol == ' ') count_space++;
		if (symbol == '\n') break;
	}
	count_space++;

	this->columns = count_space;
	this->rows = lines;

	file_input.seekg(0, ios::beg);
	file_input.clear();

	matrix = new int*[rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[columns];
		for (int j = 0; j < columns; j++) {
			file_input >> matrix[i][j];
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

void Matrix::print_matrix(string sort_name)
{
	cout << sort_name << ':' <<  endl;
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			cout << this->matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
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
	out << '|' << endl;
	out.close();
}

Matrix::Matrix(const Matrix &m) {
	this->rows = m.rows;
	this->columns = m.columns;
	this->matrix = new int*[this->rows];
	for (int i = 0; i < this->rows; i++) {
		this->matrix[i] = new int[this->columns];
		for (int j = 0; j < this->columns; j++) {
			matrix[i][j] = m.matrix[i][j];
		}
	}
}

Matrix Matrix::operator=(Matrix &m) {
	rows = m.rows;
	columns = m.columns;
	matrix = new int*[rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[columns];
		for (int j = 0; j < columns; j++) {
			matrix[i][j] = m.matrix[i][j];
		}
	}
	return *this;
}