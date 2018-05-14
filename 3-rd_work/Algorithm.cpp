#include <iostream>
#include <fstream>
#include "Matrix.h"
#include <cstring>
#include "Algorithm.h"
#include "Interface.h"
#include <iomanip>


Matrix Sorts::bubble_sort(Matrix matrix) {	
	number_of_comparisons = 0;
	number_of_swaps = 0;
	for (int row = 0; row < matrix.getRows(); row+=2) {
		for (int i = 0; i < matrix.getColumns(); i++) {
			for (int j = 0; j < matrix.getColumns()-1; j++) {
				number_of_comparisons++;
				if (abs(matrix[row][j]) > abs(matrix[row][j + 1])) {
					number_of_swaps++;
					swap(matrix[row][j], matrix[row][j + 1]);
				}
			}
		}
	}
	
	for (int column = 1; column < matrix.getColumns(); column += 2) {
		for (int i = 0; i < matrix.getRows(); i++) {
			for (int j = 0; j < matrix.getRows() - 1; j++) {
				number_of_comparisons++;
				if (matrix[j][column] > matrix[j+1][column]) {
					number_of_swaps++;
					swap(matrix[j][column], matrix[j + 1][column]);
				}
			}
		}
	}
	table.setSortResult(number_of_comparisons, number_of_swaps);
	return matrix;
}

Matrix Sorts::selection_sort(Matrix matrix) {
	number_of_comparisons = 0;
	number_of_swaps = 0;
	for (int row = 0; row < matrix.getRows(); row += 2) {
		for (int i = 0; i < matrix.getColumns(); i++) {
			int minimal_element_index = i;
			for (int j = i+1; j < matrix.getColumns(); j++) {
				number_of_comparisons++;
				if (abs(matrix[row][j]) <abs(matrix[row][minimal_element_index])) {
					minimal_element_index = j;
				}
			}
			number_of_swaps++;
			swap(matrix[row][minimal_element_index], matrix[row][i]);
		}
	}
	
	for (int column = 1; column < matrix.getColumns(); column += 2) {
		for (int i = 0; i < matrix.getRows(); i++) {
			int minimal_element_index = i;
			for (int j = i; j < matrix.getRows(); j++) {
				number_of_comparisons++;
				if (matrix[j][column] < matrix[minimal_element_index][column]) {
					minimal_element_index = j;
				}
			}
			number_of_swaps++;
			swap(matrix[minimal_element_index][column], matrix[i][column]);
		}
	}
	table.setSortResult(number_of_comparisons, number_of_swaps);
	return matrix;
}

Matrix Sorts::insertion_sort(Matrix matrix) {
	number_of_comparisons = 0;
	number_of_swaps = 0;
	for (int row = 0; row < matrix.getRows(); row += 2) {
		for (int i = 1; i < matrix.getColumns(); i++) {
			int temp = matrix[row][i];
			int j;
			number_of_comparisons++;
			for (j = i; j >= 1 && abs(matrix[row][j - 1]) > abs(temp); j --) {
				number_of_swaps++;
				number_of_comparisons++;
				matrix[row][j] = matrix[row][j - 1];
			}
			number_of_swaps++;
			matrix[row][j] = temp;
		}
	}
	
	for (int column = 1; column < matrix.getColumns(); column += 2) {
		for (int i = 1; i < matrix.getRows(); i++) {		
			int key = matrix[i][column];
			int j;
			number_of_comparisons++;
			for (j = i; j >= 1 && matrix[j - 1][column] > key; j --) {
				number_of_swaps++;
				number_of_comparisons++;
				matrix[j][column] = matrix[j - 1][column];
			}
			number_of_swaps++;
			matrix[j][column] = key;
		}
	}
	table.setSortResult(number_of_comparisons, number_of_swaps);
	return matrix;
}

Matrix Sorts::shell_sort(Matrix matrix) {
	number_of_comparisons = 0;
	number_of_swaps = 0;
	for (int row = 0; row < matrix.getRows(); row += 2) {
		for (int gap = matrix.getColumns() / 2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < matrix.getColumns(); i ++ )
			{
				int temp = matrix[row][i];
				int j;
				number_of_comparisons++;
				for (j = i; j >= gap && abs(matrix[row][j - gap]) > abs(temp); j -= gap) {
					number_of_swaps++;
					number_of_comparisons++;
					matrix[row][j] = matrix[row][j - gap];
				}
				number_of_swaps++;
				matrix[row][j] = temp;
			}
		}
	}
	for (int column = 1	; column < matrix.getColumns(); column += 2) {
		for (int gap = matrix.getRows() / 2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < matrix.getRows(); i ++ )
			{
				int key = matrix[i][column];
				int j;
				number_of_comparisons++;
				for (j = i; j >= gap && matrix[j-gap][column] > key; j -= gap) {
					number_of_swaps++;
					number_of_comparisons++;
					matrix[j][column] = matrix[j-gap][column];
				}
				number_of_swaps++;
				matrix[j][column] = key;
			}
		}
	}
	table.setSortResult(number_of_comparisons, number_of_swaps);
	return matrix;
}

Matrix Sorts::quick_sort(Matrix matrix) {
	number_of_comparisons = 0;
	number_of_swaps = 0;
	for (int row = 0; row < matrix.getRows(); row += 2) {
		actual_qsort_rows(matrix,row, 0, matrix.getColumns()-1);
	}
	for (int column = 1; column < matrix.getColumns(); column += 2) {
		actual_qsort_columns(matrix, column, 0, matrix.getRows()-1);
	}
	table.setSortResult(number_of_comparisons, number_of_swaps);
	return matrix;
}

void Sorts::actual_qsort_rows(Matrix &matrix, int row, int begin, int end) {
	int i = begin;
	int j = end;
	int pivot = abs(matrix[row][(begin + end) / 2]);
	while (i <= j) {
		
		while (abs(matrix[row][i]) < pivot) {
			number_of_comparisons++;
			i++;
		}

		while (abs(matrix[row][j]) > pivot) {
			number_of_comparisons++;
			j--;
		}
		number_of_comparisons += 2;
		if (i <= j) {
			number_of_swaps++;
			swap(matrix[row][i], matrix[row][j]);
			i++;
			j--;
		}
	}

	if (begin < j)
		actual_qsort_rows(matrix,row, begin, j);
	if (i < end)
		actual_qsort_rows(matrix,row, i, end);
}

void Sorts::actual_qsort_columns(Matrix &matrix,int column,int begin, int end) {
	int i = begin;
	int j = end;
	int pivot = matrix[(begin + end) / 2][column];
	while (i <= j) {
		while (matrix[i][column] < pivot) {
			number_of_comparisons++;
			i++;
		}


		while (matrix[j][column] > pivot) {
			number_of_comparisons++;
			j--;
		}
		number_of_comparisons += 2;
		if (i <= j) {
			number_of_swaps++;
			swap(matrix[i][column], matrix[j][column]);
			i++;
			j--;
		}
	}
	if (begin < j)
		actual_qsort_columns(matrix,column, begin, j);
	if (i < end)
		actual_qsort_columns(matrix,column, i, end);

}

void Sorts::showTable() {
	table.show();
}

void Sorts::saveTableToFile(ofstream &out) {
	table.save(out);
}

void Table::show() {
	int longest_string = sort_names[0].length();
	cout << "Метод сортировки" << setw(25) << "Кол-во сравнений" << setw(25) << "Кол-во перестановок" << endl;
	for (int i = 0; i < 5; i++) { 
		cout << sort_names[i] << setw(21 + longest_string-sort_names[i].length()) << comparasions[i] << 
			setw(25) << swaps[i] << endl;
	}

}

void Table::setSortResult(int swap, int comparasion) {
	static int index = 0;
	this->comparasions[index] = comparasion;
	this->swaps[index] = swap;
	index++;
}

void Table::save(ofstream &out) {
	int longest_string = sort_names[0].length();
	out << "Метод сортировки" << setw(25) << "Кол-во сравнений" << setw(25) << "Кол-во перестановок" << endl;
	for (int i = 0; i < 5; i++) {
		out << sort_names[i] << setw(21 + longest_string - sort_names[i].length()) << comparasions[i] <<
			setw(25) << swaps[i] << endl;
	}
	out.close();
}