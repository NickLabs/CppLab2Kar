#include <iostream>
#include <fstream>
#include "Matrix.h"
#include <cstring>
#include "Algorithm.h"
#include "Interface.h"
#include <ctime>
#include <filesystem>

using namespace std;

void save_to_file(Matrix bm, AllCordinates ac)
{
	
	cout << endl << "Хотите ли вы сохранить матрицу в отдельный файл? Y/N" << endl;;
	if (accept_deny() == true)
	{
		bool is_saved;
		do
		{
			is_saved = true;
			bool correct_filename;
			string filename;
			cout << "Введите название файла, куда вы хотите сохранить исходную матрицу: ";
			do
			{
				correct_filename = true;
				cin >> filename;
				if (filename.substr(0, 3) == "con" || filename.substr(0, 3) == "nul" || filename.substr(0, 3) == "prn" || filename.substr(0, 3) == \
					"aux" || filename.substr(0, 4) == "com1" || filename.substr(0, 4) == "com2" || filename.substr(0, 4) == "com3" || \
					filename.substr(0, 4) == "com4" || filename.substr(0, 4) == "com5" || filename.substr(0, 4) == "com6" || \
					filename.substr(0, 4) == "com7" || filename.substr(0, 4) == "com8" || filename.substr(0, 4) == "com9" || \
					filename.substr(0, 4) == "lpt1" || filename.substr(0, 4) == "lpt2" || filename.substr(0, 4) == "lpt3" || \
					filename.substr(0, 4) == "lpt4" || filename.substr(0, 4) == "lpt5" || filename.substr(0, 4) == "lpt6" || \
					filename.substr(0, 4) == "lpt7" || filename.substr(0, 4) == "lpt8" || filename.substr(0, 4) == "lpt9")
				{ 
					cout << "Использовано зарезервированное системой имя файла" << endl;
					cout << "Повторите ввод: ";
					correct_filename = false;
				}
				/*experimental::filesystem::path p(filename);
				if (!experimental::filesystem::is_regular_file(p)) {
					cout << "Использовано зарезервированное системой имя файла" << endl;
					cout << "Повторите ввод: ";
					correct_filename = false;
				}*/
			} while (correct_filename == false);
			ifstream check_opening(filename);
			if (check_opening)
			{
				cout << "Хотите ли вы перезаписать файл? Y/N" << endl;
				if (accept_deny())
				{
					check_opening.close();
					ofstream user_output(filename);
					bm.print_matrix_to_file(user_output);
				}
				else
				{
					is_saved = false;
				}
			}
			else
			{
				ofstream user_output(filename, ios_base::app);
				bm.print_matrix_to_file(user_output);
			}
			cout << "Хотите ли вы записать координаты найденных квадратов? Y/N" << endl;
			if (accept_deny() == true)
			{
				ofstream user_output(filename, ios_base::app);
				for (int i = 0; i < ac.size; i++) {
					user_output << '[' << ac.cordinates[i].row << ',' << ac.cordinates[i].column << ']' << ' ';
				}
				user_output << endl;
				user_output.close();
			}

		} while (is_saved == false);
	}
}

bool accept_deny()
{
	char answer;
	bool is_correct;
	do
	{
		is_correct = true;
		answer = correct_char_input();
		switch (toupper(answer))
		{
		case 'Y':
			return true;
		case 'N':
			return false;
		default:
			cout << "Некорректный ввод ответа" << endl;
			cout << "Повторите ввод ответа: ";
			is_correct = false;
		}
	} while (is_correct == false);
}

int correct_user_input(int min, int max)
{
	int number;

	cin >> number;
	if (min == max) {
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Неккоректный ввод" << endl;
			cout << "Пожалуйста, повторите: ";
			cin >> number;
		}
		cin.ignore(INT_MAX, '\n');
		return number;
	}
	else {
		while (cin.fail() || number < min || number > max)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Неккоректный ввод" << endl;
			cout << "Пожалуйста, повторите: ";
			cin >> number;
		}
		cin.ignore(INT_MAX, '\n');
		return number;
	}
}

void unit_tests()
{
	ifstream fin1, fin2, fin3, fin4, fin5;
	fin1.open("C:\\My Documents\\Visual Studio 2017\\Projects\\3-rd_work\\3-rd_work\\Unit_tests\\Unit_Test1.txt");
	fin2.open("C:\\My Documents\\Visual Studio 2017\\Projects\\3-rd_work\\3-rd_work\\Unit_tests\\Unit_Test2.txt");
	fin3.open("C:\\My Documents\\Visual Studio 2017\\Projects\\3-rd_work\\3-rd_work\\Unit_tests\\Unit_Test3.txt");
	fin4.open("C:\\My Documents\\Visual Studio 2017\\Projects\\3-rd_work\\3-rd_work\\Unit_tests\\Unit_Test4.txt");
	fin5.open("C:\\My Documents\\Visual Studio 2017\\Projects\\3-rd_work\\3-rd_work\\Unit_tests\\Unit_Test5.txt");

	string correct_test_answer1 = "d{a,3}mn s{o,3}n";
	string correct_test_answer2 = "{d,11}{a,13}{m,8}{n,14} son";
	string correct_test_answer3 = "damn s{o,3}n where d{i,3}d you find th{i,2}s";
	string correct_test_answer4 = "d{a,2}mn{ ,2}s{o,2}n";
	string correct_test_answer5 = "D{A,30}MN SON";

	{
		cout << "Unit-тесты пройденны успешно" << endl;
	}
}

void main_menu()
{
	int choise;
	bool correct_choise;
	bool continue_using_app = true;
	do
	{
		do
		{
			cout << endl;
			cout << "1.Ввод матрицы вручную" << endl;
			cout << "2.Ввод матрицы из файла" << endl;
			cout << "3.Заполнение матрицы рандомными числами" << endl;
			cout << "4.Завершение  работы с приложением" << endl;
			cout << "Введите номер интересующего вас пункта: ";

			correct_choise = true;
			choise = correct_user_input();
			switch (choise)
			{
			case(custom_input):
			{
				keyboard_input();
				break;

			}
			case(file_input):
			{
				input_from_file();
				break;
			}
			case(random_input):
			{
				random_filling();
				break;
			}
			case(exit_programm):
			{
				correct_choise = true;
				continue_using_app = false;
				break;
			}
			default:
				cout << "Такого варианта ответа нет" << endl;
				cout << "Пожалуйста,повторите ввод: ";
				correct_choise = false;
			}
		} while (correct_choise == false);
	} while (continue_using_app == true);
}

char correct_char_input()
{
	char ch;

	cin >> ch;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Неккоректный ввод" << endl;
		cout << "Пожалуйста, повторите: ";
		cin >> ch;
	}
	cin.ignore(INT_MAX, '\n');
	return ch;
}

void keyboard_input()
{
	int size;
	cout << "Введите размер: ";
	size = correct_user_input(2, INT_MAX);
	Matrix bm(size);
	
	for (int i = 0; i < bm.getSize(); i++) {
		for (int j = 0; j < bm.getSize(); j++) {
			cout << "Введите элементы матрицы: ";
			int element = correct_user_input(0, 1);
			bm.setMatrixElement(i, j, element);
		}
	}
	bm.print_matrix();
	AllCordinates cords = solution(bm);
	if (cords.size != 0) {
		for (int i = 0; i < cords.size; i++) {
			cout << '[' << cords.cordinates[i].row << ',' << cords.cordinates[i].column << ']' << ' ';
		}
	}
	else {
		cout << "Квадратов с заданным размером найдено не было" << endl;
	}
	cout << endl;
	save_to_file(bm, cords);
}

void random_filling() {
	int size;
	cout << "Введите размер: ";
	size = correct_user_input(2, INT_MAX);
	Matrix bm(size);
	cout << "Введите элементы матрицы" << endl;
	for (int i = 0; i < bm.getSize(); i++) {
		for (int j = 0; j < bm.getSize(); j++) {
			int element = rand() % 2;
			bm.setMatrixElement(i, j, element);
		}
	}
	bm.print_matrix();

	AllCordinates cords = solution(bm);
	if (cords.size != 0) {
		for (int i = 0; i < cords.size; i++) {
			cout << '[' << cords.cordinates[i].row << ',' << cords.cordinates[i].column << ']' << ' ';
		}
	}
	else {
		cout << "Квадратов с заданным размером найдено не было" << endl;
	}
	cout << endl;
	save_to_file(bm, cords);
}

void input_from_file(string filename)
{
	ifstream file_input;
	if (filename == "")
	{
		cout << "Введите название текстового файла: ";
		cin >> filename;
		bool is_correct_content = false;
		while (!is_correct_content) {
			ifstream test_file(filename);
			while (!test_file)
			{
				cout << "Файла с таким именем не найдено, пожалуйста, повторите ввод: ";
				test_file.close();
				cin >> filename;
				test_file.open(filename);
			}
			test_file.close();
			file_input.open(filename);
			int tmp;
			is_correct_content = true;
			while (!file_input.eof()) {
				file_input >> tmp;
				if (tmp < 0 && tmp > 1) {
					cout << "Неккоректные числа в файле, измените файл или выберите другой" << endl;
					is_correct_content = false;
					break;
				}
			}
		}
	}
	else
	{
		file_input.open(filename);
	}

	Matrix bm(file_input);
	bm.print_matrix();

	AllCordinates cords = solution(bm);
	if (cords.size != 0) {
		for (int i = 0; i < cords.size; i++) {
			cout << '[' << cords.cordinates[i].row << ',' << cords.cordinates[i].column << ']' << ' ';
		}
	}
	else {
		cout << "Квадратов с заданным размером найдено не было" << endl;
	}
	cout << endl;
	save_to_file(bm, cords);
}
