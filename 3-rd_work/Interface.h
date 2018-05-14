#pragma once
#include <iostream>
#include <fstream>
#include "Matrix.h"
#include <cstring>
#include "Algorithm.h"

using namespace std;

enum  main_menu_enum{custom_input =1, file_input, random_input,exit_programm};

void input_from_file(string filename = "");
void main_menu();
void unit_tests();
int correct_user_input(int min=0, int max=0);
char correct_char_input();
bool accept_deny();
void save_to_file(Matrix initial_matrix, Matrix final_Matrix,  Sorts sorts);
void keyboard_input();
void random_filling();