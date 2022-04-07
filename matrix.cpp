#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdio.h>
#include <iomanip>
#include "matrix.h"
using namespace std;

// проверка корректности ввода
int read_and_check(int a)
{
	while (std::cin.fail() || a < 1)
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "Введите корректные данные: ";
		cin >> a;
	}
	return a;
}
// обнуление матрицы
void zeroing(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = 0;
}

// создание квадратной матрицы
double** creating_matrix(int n)
{
	double** matrix = new double* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new double[n];
	zeroing(matrix, n);
	return matrix;
}

// заполнение матрицы
void fill_matrix(double **matrix, int n)
{
for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		matrix[i][j] = min(i + 1, j + 1);
}

// вывод матрицы
void print_matrix(double** matrix, string announce, int n)
{
	cout << announce;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << "\t";
		cout << endl;
	}
}

// очистка памяти
void cleaning_memory(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] matrix[i];
		matrix[i] = nullptr;
	}

	delete[] matrix;
	matrix = nullptr;
}

// получение матрицы без i-й строки и j-го столбца (т. е. перенумеровывание элементов)
void renumber_matrix(double** matrix, double** new_matrix, int i, int j, int n)
{
	int i_renum = 0, j_renum = 0;
	if (n == 1)
		cout << "Минор матрицы размера 1 не существует" << endl;

	else {
		for (int new_i = 0; new_i < n - 1; new_i++)
		{
			// проверка индекса строки
			if (new_i == i)
				i_renum = 1;

			j_renum = 0;
			for (int new_j = 0; new_j < n; new_j++)
			{
				// проверка индекса столбца
				if (new_j == j)
					j_renum = 1;

				new_matrix[new_i][new_j] = matrix[new_i + i_renum][new_j + j_renum];
			}
		}
	}
}

// рекурсивное вычисление определителя
double determinant(double **matrix, int n)
{
// k нужно, чтобы обеспечить знакопеременную сумму вычисления определителя (-1)^(i + j)
	double k = 1, det = 0;
	double **new_matrix = creating_matrix(n);
	if (n == 1)
		return matrix[0][0];
	if (n == 2)
		return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
	if (n > 2)
		for (int j = 0; j < n; j++)
		{
			renumber_matrix(matrix, new_matrix, 0, j, n);
			det = det + k * matrix[0][j] * determinant(new_matrix, n - 1);
			k = -k;
		}
	cleaning_memory(new_matrix, n);
	return det;
}

template <class T>
T read_and_check(T a)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Введите корректные данные: " << endl;
		cin >> a;
	}
	return a;
}

// прототип функции вывода
void print(double** matrix, int n, string announce);

// заполнение матрицы
void reading_elements_matrix(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
			matrix[i][j] = read_and_check(matrix[i][j]);
		}
}

// перемножение 2х матриц и занесение полученной в третью
double** multiplication_matrix(double** matrix_1, double** matrix_2, double** matrix_3, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++) 
				matrix_3[i][j] += matrix_1[i][k] * matrix_2[k][j];
			
	return matrix_3;
}

// умножение матрицы на число
double** multiplication_matrix_on_number(double** matrix, int n, int number)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = number * matrix[i][j];
	return matrix;
}

// сложение 2х матриц
void addition_matrix(double** matrix_1, double** matrix_2, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix_1[i][j] = matrix_1[i][j] + matrix_2[i][j];
}


// добавление единичной матрицы, умноженной на константу
void addition_with_singular_matrix(double** matrix, int n, int number)
{
	for (int i = 0; i < n; i++)
		matrix[i][i] = matrix[i][i] + number;
}

// вывод шагов решения на экран
void print(double** matrix, int n, string announce)
{
	cout << announce;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout <<  setfill(' ') << setw(20) << matrix[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

// функция g(matrix) = matrix^3 + 5 * matrix
double** g(double** matrix_1, int n)
{
	// двумерный динамический массив для вспомагательной матрицы
	double** matrix_2 = creating_matrix(n);
	// двумерный динамический массив для второй вспомагательной матрицы
	double** matrix_3 = creating_matrix(n);
	
	multiplication_matrix(matrix_1, matrix_1, matrix_2, n);
	print(matrix_2, n, "Matrix: x^2 \n ");
	
	multiplication_matrix(matrix_1, matrix_2, matrix_3, n);
	print(matrix_3, n, "Matrix: x^3 \n ");

	multiplication_matrix_on_number(matrix_1, n, 5);
	print(matrix_1, n, "Matrix: 5x \n ");
	
	addition_matrix(matrix_1, matrix_3, n);
	print(matrix_1, n, "Result matrix g(x): x^3 + 5x \n");

	cleaning_memory(matrix_2, n);
	cleaning_memory(matrix_3, n);

	return matrix_1;
}

// функция f(matrixx) = matrix^3 + 2 * matrix^2 + 5 * matrix + 10
double** f(double** matrix_1, int n)
{
	// двумерный динамический массив для вспомагательной матрицы
	double** matrix_2 = creating_matrix(n);
	// двумерный динамический массив для второй вспомагательной матрицы
	double** matrix_3 = creating_matrix(n);

	multiplication_matrix(matrix_1, matrix_1, matrix_2, n);
	print(matrix_2, n, "Matrix: x^2 \n ");
	multiplication_matrix(matrix_1, matrix_2, matrix_3, n);
	print(matrix_3, n, "Matrix: x^3 \n");

	multiplication_matrix_on_number(matrix_2, n, 2);
	print(matrix_2, n, " Matrix: 2x^2 \n");
	multiplication_matrix_on_number(matrix_1, n, 5);
	print(matrix_1, n, "Matrix: 5x  \n");

	addition_matrix(matrix_3, matrix_2, n);
	print(matrix_3, n, "Matrix: x^3 + 2x^2 \n ");
	addition_matrix(matrix_3, matrix_1, n);
	print(matrix_3, n, "Matrix: x^3 + 2x^2 + 5x \n");

	addition_with_singular_matrix(matrix_3, n, 10);
	print(matrix_3, n, "Matrix: x^3 + 2x^2 + 5x + 10\n");
	print(matrix_3, n, "Result: \n");

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix_1[i][j] = matrix_3[i][j];

	cleaning_memory(matrix_2, n);
	cleaning_memory(matrix_3, n);

	return matrix_1;
}

// вывод матрицы
void announce_and_print_matrix(double** matrix, string announce, int n)
{
	cout << announce;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << "\t";
		cout << endl;
	}
}

// создание нулевой матрицы
double** create_zero_matrix(int n)
{
	double** zero_matrix = new double* [n];
	for (int i = 0; i < n; i++)
		zero_matrix[i] = new double[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			zero_matrix[i][j] = 0;
	return zero_matrix;
}

// сложение матрицы с единичной
double** matrix_plus_single_matrix(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
		matrix[i][i]++;

	return matrix;
}

//Построение обратной матрицы
double** create_inverse_matrix(double** matrix, int size) {
	double det_minor;
	double det_matrix = determinant(matrix, size);
	double** minor = create_zero_matrix(size - 1);
	double** inverse_matrix = create_zero_matrix(size);
	if (det_matrix == 0)
	{
		cout << "Обратной матрицы не существует! \n";
		return 0;
	}
	else
	{
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) {
				renumber_matrix(matrix, minor, j, i, size);
				if (size == 1)
					det_minor = det_matrix;
				else
					det_minor = determinant(minor, size - 1);
				inverse_matrix[i][j] = double((1 / det_matrix) * pow(-1, i + j) * det_minor);
			}
		return inverse_matrix;
	}
}

// перемножение 2х матриц и занесение полученной в третью
double** multiplication_matrix(double** matrix_1, double** matrix_2, int n)
{
	double** matrix_3 = creating_matrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			matrix_3[i][j] = 0;
			for (int k = 0; k < n; k++)
				matrix_3[i][j] += matrix_1[i][k] * matrix_2[k][j];
		}
	return matrix_3;
}

// решение матричного уравнения
double** solve_matrix_equation(double** matrix_1, double** matrix_2, int n)
{
	double det = determinant(matrix_1, n);

	matrix_1 = matrix_plus_single_matrix(matrix_1, n);
	announce_and_print_matrix(matrix_1, "\nСкладываем 1ю матрицу с единичной: \n", n);
	// проверка неравенства нулю определителя исходной матрицы
	if (create_inverse_matrix(matrix_1, n) == 0)
	{
		cout << "\nРешений нет! ";
		return 0;
	}
	else {
		matrix_1 = create_inverse_matrix(matrix_1, n);
		if (matrix_1 == 0)
			return 0;
		announce_and_print_matrix(matrix_1, "\nНаходим обратную матрицу для 1й: \n", n);

		double** matrix_3 = multiplication_matrix(matrix_2, matrix_1, n);
		announce_and_print_matrix(matrix_3, "\nУмножаем полученную обратную матрицу на вторую: \n", n);

		cleaning_memory(matrix_3, n);
		return matrix_3;
	}
}

/*На вход поступает матрица.
Дан многочлен f(x) = x^3 + 2 * x^2 + 5 * x + 10, g(x) = x^3 + 5 * x.
Нужно найти f(g(A)) */
void count_value_polynomial(double** matrix_a_new, int n)
{
	// функция g(A') = A'^3 + 5 * A'
	matrix_a_new = g(matrix_a_new, n);
	print(matrix_a_new, n, "\nМатрица g(A')\n");
	// функция f(A') = A'^3 + 2 * A'^2 + 5 * A' + 10
	matrix_a_new = f(matrix_a_new, n);
	print(matrix_a_new, n, "\nМатрица f(g(A'))\n");
}

/*Необходимо вычислить определитель матрицы порядка n,
элементы которого заданы условием (a)ij = min(i, j)*/
void counting_determinant()
{
	

	/*for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];*/
	
	int n;
	cout << "Лабораторная 6.2\nВведите размерность матрицы:\n";
	cin >> n;
	n = read_and_check(n);
	double** matrix = creating_matrix(n);
	fill_matrix(matrix, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
		

	/*double** matrix = creating_matrix(n);

	cout << "\nВведите матрицу" << endl;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];

	print_matrix(matrix, "\nИсходная матрица:\n", n);*/

	double det = determinant(matrix, n);
	cout << "\nОпределитель исходной матрицы = " << det << endl << endl;

	cleaning_memory(matrix, n);

}

/*6.3
Программа решает матричное уравнение № 13:
X * (A) + X = (B), X - искомая матрица
X * (A + E) = B
X = B * (A + E)^-1
*/
