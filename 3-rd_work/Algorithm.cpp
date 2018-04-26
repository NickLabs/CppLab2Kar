#include <iostream>
#include <fstream>
#include "Matrix.h"
#include <cstring>
#include "Algorithm.h"
#include "Interface.h"

void bubble_sort(Matrix matrix) {
	for (int row = 0; row < matrix.getRows; row+=2) {
		for (int i = 0; i < matrix.getColumns; i++) {
			for (int j = 0; j < matrix.getColumns-1; j++) {
				if (matrix[row][j] > matrix[row][j + 1]) {
					int tmp = matrix[row][j];
					matrix[row][j] = matrix[row][j + 1];
					matrix[row][j + 1] = tmp;
				}
			}
		}
	}
}

void selection_sort(Matrix matrix) {
	for (int row = 0; row < matrix.getRows; row + 2) {
		for (int i = 0; i < matrix.getColumns; i++) {
			int minimal_element_index = i;
			for (int j = i; j < matrix.getColumns; j++) {
				if (matrix[row][j] < matrix[row][minimal_element_index]) {
					minimal_element_index = j;
				}
			}
			int tmp = matrix[row][i];
			matrix[row][i] = matrix[row][minimal_element_index];
			matrix[row][minimal_element_index] = tmp;
		}
	}
}