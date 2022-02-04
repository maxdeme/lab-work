/*
Программа решает матричное уравнение № 13:
X * (A) + X = (B), X - искомая матрица
X * (A + E) = B
X = B * (A + E)^-1
*/

#include <iostream>
#include <string>
#include "equation.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int n = 0;

	cout << "Введите размер матриц: \n";
	
	cin >> n;

	read_and_check(n);

	double** matrix_1 = creating_matrix(n);
	double** matrix_2 = creating_matrix(n);

	cout << "Введите 1ю матрицу: \n";  // { 2, -2, 2, 7, 0, 6, 10, 12, 10 };

	fill_matrix(matrix_1, n);

	cout << "\nВведите 2ю матрицу: \n";  // { 1, 7, 1, 0, 1, 0, -1, 3, 0 };

	fill_matrix(matrix_2, n);

	decide_matrix_equation(matrix_1, matrix_2, n);

	cleaning_memory(matrix_1, n);
	cleaning_memory(matrix_2, n);

	system("pause");
	return 0;
}