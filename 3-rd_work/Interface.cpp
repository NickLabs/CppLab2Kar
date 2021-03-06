#include <iostream>
#include <fstream>
#include "Matrix.h"
#include <cstring>
#include "Algorithm.h"
#include "Interface.h"
#include <ctime>
#include <filesystem>

using namespace std;

void save_to_file(Matrix initial_matrix, Matrix final_Matrix, Sorts sorts)
{
	
	cout << endl << "������ �� �� ��������� ������� � ��������� ����? Y/N" << endl;;
	if (accept_deny() == true)
	{
		bool is_saved;
		do
		{
			is_saved = true;
			bool correct_filename;
			string filename;
			cout << "������� �������� �����, ���� �� ������ ��������� �������� �������: ";
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
					cout << "������������ ����������������� �������� ��� �����" << endl;
					cout << "��������� ����: ";
					correct_filename = false;
				}
				/*experimental::filesystem::path p(filename);
				if (!experimental::filesystem::is_regular_file(p)) {
					cout << "������������ ����������������� �������� ��� �����" << endl;
					cout << "��������� ����: ";
					correct_filename = false;
				}*/
			} while (correct_filename == false);
			ifstream check_opening(filename);
			if (check_opening)
			{
				cout << "������ �� �� ������������ ����? Y/N" << endl;
				if (accept_deny())
				{
					check_opening.close();
					ofstream user_output(filename);
					initial_matrix.print_matrix_to_file(user_output);
				}
				else
				{
					is_saved = false;
				}
			}
			else
			{
				ofstream user_output(filename, ios_base::app);
				initial_matrix.print_matrix_to_file(user_output);
			}
			cout << "������ �� �� �������� �������� ������� � ����? Y/N" << endl;
			if (accept_deny() == true)
			{
				ofstream user_output(filename, ios_base::app);
				final_Matrix.print_matrix_to_file(user_output);
				user_output << endl;
			}
			cout << "������ �� �� �������� ������� � ������������ � ����? Y/N" << endl;
			if (accept_deny() == true)
			{
				ofstream user_output(filename, ios_base::app);
				sorts.saveTableToFile(user_output);
				user_output << endl;
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
			cout << "������������ ���� ������" << endl;
			cout << "��������� ���� ������: ";
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
			cout << "������������ ����" << endl;
			cout << "����������, ���������: ";
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
			cout << "������������ ����" << endl;
			cout << "����������, ���������: ";
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
		cout << "Unit-����� ��������� �������" << endl;
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
			cout << "1.���� ������� �������" << endl;
			cout << "2.���� ������� �� �����" << endl;
			cout << "3.���������� ������� ���������� �������" << endl;
			cout << "4.����������  ������ � �����������" << endl;
			cout << "������� ����� ������������� ��� ������: ";

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
				cout << "������ �������� ������ ���" << endl;
				cout << "����������,��������� ����: ";
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
		cout << "������������ ����" << endl;
		cout << "����������, ���������: ";
		cin >> ch;
	}
	cin.ignore(INT_MAX, '\n');
	return ch;
}

void keyboard_input()
{
	int rows, columns;
	cout << "������� ���-�� �����: ";
	rows = correct_user_input(2, INT_MAX);
	cout << "������� ���-�� ��������: ";
	columns = correct_user_input(2, INT_MAX);
	Matrix bm(rows,columns);
	
	for (int i = 0; i < bm.getRows(); i++) {
		for (int j = 0; j < bm.getColumns(); j++) {
			cout << "������� �������� �������: ";
			bm[i][j] = correct_user_input();
		}
	}
	bm.print_matrix("�������� �������");

	Sorts sorts;
	Matrix initial(bm);
	Matrix bm2 = sorts.selection_sort(bm);
	Matrix bm3 = sorts.insertion_sort(bm);
	Matrix bm4 = sorts.shell_sort(bm);
	Matrix bm5 = sorts.quick_sort(bm);
	bm = sorts.bubble_sort(bm);

	bm.print_matrix("���������� ���������");
	bm2.print_matrix("���������� �������");
	bm3.print_matrix("���������� ���������");
	bm4.print_matrix("���������� �����");
	bm5.print_matrix("������� ����������");

	sorts.showTable();

	cout << endl;
	save_to_file(initial, bm, sorts);
}

void random_filling() {
	int rows, columns;
	cout << "������� ���-�� �����: ";
	rows = correct_user_input(2, INT_MAX);
	cout << "������� ���-�� ��������: ";
	columns = correct_user_input(2, INT_MAX);
	Matrix bm(rows, columns);
	srand(time(0));

	for (int i = 0; i < bm.getRows(); i++) {
		for (int j = 0; j < bm.getColumns(); j++) {
			int element = rand() % 100 - 50;
			bm[i][j] = element;
		}
	}
	bm.print_matrix("�������� �������");

	Sorts sorts;
	Matrix initial(bm);
	Matrix bm2 = sorts.selection_sort(bm);
	Matrix bm3 = sorts.insertion_sort(bm);
	Matrix bm4 = sorts.shell_sort(bm);
	Matrix bm5 = sorts.quick_sort(bm);
	bm = sorts.bubble_sort(bm);
	
	bm.print_matrix("���������� ���������");
	bm2.print_matrix("���������� �������");
	bm3.print_matrix("���������� ���������");
	bm4.print_matrix("���������� �����");
	bm5.print_matrix("������� ����������");
	
	sorts.showTable();
	
	cout << endl;
	save_to_file(initial, bm, sorts);
}

void input_from_file(string filename)
{
	ifstream file_input;
	if (filename == "")
	{
		cout << "������� �������� ���������� �����: ";
		cin >> filename;
		bool is_correct_content = false;
		while (!is_correct_content) {
			ifstream test_file(filename);
			while (!test_file)
			{
				cout << "����� � ����� ������ �� �������, ����������, ��������� ����: ";
				test_file.close();
				cin >> filename;
				test_file.open(filename);
			}
			test_file.close();
			file_input.open(filename);
			is_correct_content = true;
		}
	}
	else
	{
		file_input.open(filename);
	}

	Matrix bm(file_input);
	bm.print_matrix("�������� �������");
	
	Sorts sorts;
	Matrix initial(bm);
	Matrix bm2 = sorts.selection_sort(bm);
	Matrix bm3 = sorts.insertion_sort(bm);
	Matrix bm4 = sorts.shell_sort(bm);
	Matrix bm5 = sorts.quick_sort(bm);
	bm = sorts.bubble_sort(bm);

	bm.print_matrix("���������� ���������");
	bm2.print_matrix("���������� �������");
	bm3.print_matrix("���������� ���������");
	bm4.print_matrix("���������� �����");
	bm5.print_matrix("������� ����������");

	sorts.showTable();

	cout << endl;
	save_to_file(initial, bm, sorts);
}
