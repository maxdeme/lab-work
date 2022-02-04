#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdio.h>
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

// создание квадратной матрицы
double** creating_matrix(int n)
{
	double** matrix = new double* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new double[n];
	return matrix;
}

/*// заполнение матрицы
void fill_matrix(double **matrix, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = min(i + 1, j + 1);
}*/

// вывод матрицы
void print_matrix(double **matrix, string announce, int n)
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
void cleaning_memory(double **matrix, int n)
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
void renumber_matrix(double **matrix, double **new_matrix, int i, int j, int n)
{
	int i_renum = 0, j_renum = 0;

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

/*// рекурсивное вычисление определителя
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
		for (int i = 0; i < n; i++)
		{
			renumber_matrix(matrix, new_matrix, i, 0, n);
			det = det + k * matrix[i][0] * determinant(new_matrix, n - 1);
			k = -k;
		}

	cleaning_memory(new_matrix, n);

	return det;
}*/

// вычисление определителя матрицы
double determinant(double** matrix, int n)
{
	if (n == 1)
		return matrix[0][0];
	else if (n == 2)
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	double det = 0;
	for (int k = 0; k < n; k++)
	{
		double** minor = creating_matrix(n - 1);
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j == k)
					continue;
				else if (j < k)
					minor[i - 1][j] = matrix[i][j];
				else
					minor[i - 1][j - 1] = matrix[i][j];
			}
		}
		det += pow(-1, k + 2) * matrix[0][k] * determinant(minor, n - 1);
	}
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
void print(double **matrix, int n, string announce);

// заполнение матрицы
void reading_elements_matrix(double **matrix, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
			matrix[i][j] = read_and_check(matrix[i][j]);
		}
}

// перемножение 2х матриц и занесение полученной в третью
double **multiplication_matrix(double **matrix_1, double **matrix_2, double **matrix_3, int n)
{
	int m = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				matrix_3[i][j] = matrix_3[i][j] + matrix_1[i][k] * matrix_2[k][j];
	return matrix_3;
}

// умножение матрицы на число
double **multiplication_matrix_on_number(double **matrix, int n, int number)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = number * matrix[i][j];
	return matrix;
}

// сложение 2х матриц
void addition_matrix(double **matrix_1, double **matrix_2, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix_1[i][j] = matrix_1[i][j] + matrix_2[i][j];
}

// обнуление матрицы
void zeroing(double **matrix, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = 0;
}

// добавление единичной матрицы, умноженной на константу
void addition_with_singular_matrix(double **matrix, int n, int number)
{
	for (int i = 0; i < n; i++)
		matrix[i][i] = matrix[i][i] + number;
}

// перемножене 2х матриц и сохранение результата в третью
void announcement_and_multiplication_matrix(double **matrix_1, double **matrix_2, double **matrix_3, int n, string announce)
{
	matrix_3 = multiplication_matrix(matrix_1, matrix_2, matrix_3, n);
	print(matrix_3, n, announce);
	cout << endl;
}

// сложение и вывод матриц на экран
void addition_and_showing(double **matrix_1, double **matrix_2, int n, string announce)
{
	addition_matrix(matrix_1, matrix_2, n);
	print(matrix_1, n, announce);
	cout << endl;
}

// умножение матрицы на константу и вывод на экран
void announcement_and_multiplication_matrix_on_number(double **matrix, double n, string announce, int number)
{
	matrix = multiplication_matrix_on_number(matrix, n, number);
	print(matrix, n, announce);
	cout << endl;
}

// вывод шагов решения на экран
void print(double **matrix, int n, string announce)
{
	cout << announce;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}

// функция g(matrix) = matrix^3 + 5 * matrix
double **g(double **matrix_1, int n)
{
	// двумерный динамический массив для вспомагательной матрицы
	double **matrix_2 = creating_matrix(n);
	// двумерный динамический массив для второй вспомагательной матрицы
	double **matrix_3 = creating_matrix(n);

	announcement_and_multiplication_matrix(matrix_1, matrix_1, matrix_2, n, "Возводим матрицу во 2 степень\n");
	announcement_and_multiplication_matrix(matrix_1, matrix_2, matrix_3, n, "Возводим матрицу в 3 степень\n");

	announcement_and_multiplication_matrix_on_number(matrix_1, n, "Умножаем исходную матрицу на 5\n", 5);

	addition_matrix(matrix_1, matrix_3, n);
	print(matrix_1, n, "Выводим на экран f(g)\n");

	clearning_memory(matrix_2, n);
	clearning_memory(matrix_3, n);

	return matrix_1;
}

// функция f(matrixx) = matrix^3 + 2 * matrix^2 + 5 * matrix + 10
double **f(double **matrix_1, int n)
{
	// двумерный динамический массив для вспомагательной матрицы
	double **matrix_2 = creating_matrix(n);
	// двумерный динамический массив для второй вспомагательной матрицы
	double **matrix_3 = creating_matrix(n);

	announcement_and_multiplication_matrix(matrix_1, matrix_1, matrix_2, n, "Возводим матрицу f(g) во 2 степень\n");
	announcement_and_multiplication_matrix(matrix_1, matrix_2, matrix_3, n, "Возводим матрицу f(g) в 3 степень\n");

	announcement_and_multiplication_matrix_on_number(matrix_2, n, "Умножаем матрицу f(g)^2 на 2\n", 2);
	announcement_and_multiplication_matrix_on_number(matrix_1, n, "Умножаем матрицу f(g) на 5\n", 5);

	addition_and_showing(matrix_3, matrix_2, n, "Складываем f(g)^3 и 2 * f(g)^2\n");
	addition_and_showing(matrix_3, matrix_1, n, "Складываем f(g)^3, 2 * f(g)^2 и 5 * f(g)\n");

	addition_with_singular_matrix(matrix_3, n, 10);
	print(matrix_3, n, "Складываем f(g)^3, 2 * f(g)^2, 5 * f(g) и единичную матрицу, умноженную на 10\n");

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix_1[i][j] = matrix_3[i][j];

	clearning_memory(matrix_2, n);
	clearning_memory(matrix_3, n);

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

// заполнение матрицы, ввод с клавиатуры
void fill_matrix(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
}

// получение матрицы без i-й строки и j-го столбца (т. е. перенумеровывание элементов)
double** create_minor(double** matrix, int n, int row_idx, int column_idx)
{
	double** minor;
	if (n == 1)
	{
		cout << "Минор матрицы размера 1 не существует" << endl;
		return 0;
	}
	else
	{
		minor = creating_matrix(n - 1);
		int minor_i = 0;
		for (int i = 0; i < n; i++)
			if (i != row_idx)
			{
				for (int j = 0, minor_j = 0; j < n; j++)
					if (j != column_idx)
					{
						minor[minor_i][minor_j] = matrix[i][j];
						minor_j++;
					}
				minor_i++;
			}
	}
	return minor;
}

// сложение матрицы с единичной
double** matrix_plus_single_matrix(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
		matrix[i][i]++;

	return matrix;
}

// создание обратной матрицы
double** create_inverse_matrix(double** matrix, int n)
{
	if (n == 1)
	{
		double t = matrix[0][0];
		matrix = creating_matrix(1);
		matrix[0][0] = 1 / t;
		return matrix;
	}
	else
	{
		double det_minor = 1;
		double det_matrix = determinant(matrix, n);

		// проверка неравенства нулю определителя исходной матрицы
		if (det_matrix == 0)
		{
			cout << "\nОпределитель матрицы равен нулю, обратной не существует.";
			return 0;
		}

		double** minor;
		double** inverse_matrix = create_zero_matrix(n);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (n == 1)
					det_minor = 1 / det_matrix;
				minor = create_minor(matrix, n, j, i);
				if (minor == 0 && n != 1)
				{
					cout << "Обратной матрицы не существует! \n";
					return 0;
				}
				else
					det_minor = determinant(minor, n - 1);
				inverse_matrix[i][j] = 1 / det_matrix * pow(-1, i + j) * det_minor;
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
double** decide_matrix_equation(double** matrix_1, double** matrix_2, int n)
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

	matrix_1 = create_inverse_matrix(matrix_1, n);
	if (matrix_1 == 0)
		return 0;
	announce_and_print_matrix(matrix_1, "\nНаходим обратную матрицу для 1й: \n", n);

	double** matrix_3 = multiplication_matrix(matrix_2, matrix_1, n);
	announce_and_print_matrix(matrix_3, "\nУмножаем полученную обратную матрицу на вторую: \n", n);

	cleaning_memory(matrix_3, n);
	return matrix_3;
}

