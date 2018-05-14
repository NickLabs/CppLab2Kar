#pragma once
#include <iostream>
#include <fstream>
#include "Matrix.h"
#include <cstring>

using namespace std;

class Table {
private:
	const string sort_names[5] = { "Сортировка пуызрьком", "Сортировка выбором","Сортировка вставками","Сортировка Шелла","Быстрая сортировка" };
	int comparasions[5];
	int swaps[5];
public:
	void show();
	void setSortResult(int swap, int comparasion);
	void save(ofstream &out);
};

class Sorts {
private:
	int number_of_swaps;
	int number_of_comparisons;
	Table table;
	void actual_qsort_rows(Matrix &matrix, int row, int begin, int end);
	void actual_qsort_columns(Matrix &matrix,int column, int begin, int end);
public:
	Matrix bubble_sort(Matrix matrix);

	Matrix insertion_sort(Matrix matrix);

	Matrix selection_sort(Matrix matrix);

	Matrix shell_sort(Matrix matrix);

	Matrix quick_sort(Matrix matrix);

	void showTable();

	void saveTableToFile(ofstream &out);
};
