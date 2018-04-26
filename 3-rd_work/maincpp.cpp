#include <iostream>
#include <fstream>
#include <string>
#include "Algorithm.h"
#include "Interface.h"

using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");

	
	cout << "Работу выполнил студент 475 группы" << endl;
	cout << "Андрианова Карина" << endl;
	cout << "Данная программа предназначена для поиска в бинарной матрице" << endl;
	cout << "квадратов, образованных единицами" << endl;
	
	main_menu();


	system("pause");
	return 0;
}