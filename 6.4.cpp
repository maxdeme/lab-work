/*На вход поступает матрица.
Дан многочлен f(x) = x^3 + 2 * x^2 + 5 * x + 10, g(x) = x^3 + 5 * x.
Нужно найти f(g(A)) */
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include "matrix.h"
using namespace std;

// проверка корректности ввода
template <class T>
T read_and_check(T a)
{
	while (cin.fail() || a < 1)
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Введите корректные данные: " << endl;
		cin >> a;
	}
	return a;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n, m;

	cout << "Введите размер матрицы A:" << endl;
	cin >> n;
	n = read_and_check(n);

	cout << "Введите саму матрицу А : " << endl;

	// двумерный динамический массив для исходной матрицы
	double** matrix_a = creating_matrix(n);
	reading_elements_matrix(matrix_a, n);
	
	cout << "Введите размер матрицы B:" << endl;
	cin >> m;
	m = read_and_check(m);

	cout << "Введите саму матрицу B: " << endl;

	// двумерный динамический массив для исходной матрицы
	double** matrix_b = creating_matrix(m);
	reading_elements_matrix(matrix_b, m);

	//проверка на одинаковую размерность матриц А и В
	while (n != m) {
		cout << "Размеры матриц А и В должны совпадать! Введите размеры матрицы В еще раз:";
		cin >> m;
		m = read_and_check(m);
		cout << "Введите саму матрицу B: " << endl;
		// двумерный динамический массив для исходной матрицы
		double** matrix_b = creating_matrix(n);
		reading_elements_matrix(matrix_b, n);
	}
	/*
	double** matrix_ba = creating_matrix(n);
	multiplication_matrix(matrix_b, matrix_a, matrix_ba, n);

	double** matrix_a_sum_3 = matrix_a;
	addition_with_singular_matrix(matrix_a_sum_3, n, 3);

	// новая матрица для высчитывания A'
	double** matrix_a_new = creating_matrix(n);
	matrix_a_new = f(matrix_a_sum_3, n);
	print(matrix_a_new, n, "\nМатрица A'\n");
	
	// новая матрица для высчитывания B'
	double** matrix_b_new = creating_matrix(n);
	matrix_b_new = f(matrix_ba, n);
	print(matrix_b_new, n, "\nМатрица B'\n");

	count_value_polynomial(matrix_a_new, n);
	counting_determinant();
	*/
	cout << "Лабораторная 6.3\nПрограмма решает матричное уравнение № 13: \nX* (A)+X = (B), X - искомая матрица \nX * (A + E) = B \nX = B * (A + E) ^ -1 \n";
	solve_matrix_equation(matrix_a, matrix_b, n);
	
	// очистка памяти
	cleaning_memory(matrix_a, n);

	system("pause");
	return 0;
}



/*// лаба 6.2
/*Необходимо вычислить поределитель матрицы порядка n,
элементы которого заданы условием (a)ij = min(i, j)*/
/*#include <iostream>
#include <algorithm>
#include <string>
#include "matrix.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите размер матрицы: " << endl;

	int n = 0;
	cin >> n;
	n = read_and_check(n);

	double** matrix = creating_matrix(n);


	cout << "\nВведите матрицу" << endl;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];

	//fill_matrix(matrix, n);
	print_matrix(matrix, "\nИсходная матрица:\n", n);

	double det = determinant(matrix, n);
	cout << "\nОпределитель исходной матрицы = " << det << endl << endl;

	cleaning_memory(matrix, n);

	system("pause");
	return 0;
}*/



//6.3
/*
Программа решает матричное уравнение № 13:
X * (A) + X = (B), X - искомая матрица
X * (A + E) = B
X = B * (A + E)^-1
*/
/*
#include <iostream>
#include <string>
#include "matrix.h"
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

	cout << "Введите 1ю матрицу: \n"; // { 2, -2, 2, 7, 0, 6, 10, 12, 10 };

	fill_matrix(matrix_1, n);

	cout << "\nВведите 2ю матрицу: \n"; // { 1, 7, 1, 0, 1, 0, -1, 3, 0 };

	fill_matrix(matrix_2, n);

	decide_matrix_equation(matrix_1, matrix_2, n);

	cleaning_memory(matrix_1, n);
	cleaning_memory(matrix_2, n);

	system("pause");
	return 0;
}*/
