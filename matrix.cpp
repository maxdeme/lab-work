#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <stdio.h>
#include "matrix.h"
using namespace std;

// �������� ������������ �����
int read_and_check(int a)
{
	while (std::cin.fail() || a < 1)
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		cout << "������� ���������� ������: ";
		cin >> a;
	}
	return a;
}

// �������� ���������� �������
double** creating_matrix(int n)
{
	double** matrix = new double* [n];
	for (int i = 0; i < n; i++)
		matrix[i] = new double[n];
	return matrix;
}

/*// ���������� �������
void fill_matrix(double **matrix, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = min(i + 1, j + 1);
}*/

// ����� �������
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

// ������� ������
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

// ��������� ������� ��� i-� ������ � j-�� ������� (�. �. ����������������� ���������)
void renumber_matrix(double **matrix, double **new_matrix, int i, int j, int n)
{
	int i_renum = 0, j_renum = 0;

	for (int new_i = 0; new_i < n - 1; new_i++)
	{
		// �������� ������� ������
		if (new_i == i)
			i_renum = 1;

		j_renum = 0;
		for (int new_j = 0; new_j < n; new_j++)
		{
			// �������� ������� �������
			if (new_j == j)
				j_renum = 1;

			new_matrix[new_i][new_j] = matrix[new_i + i_renum][new_j + j_renum];
		}
	}
}

/*// ����������� ���������� ������������
double determinant(double **matrix, int n)
{
	// k �����, ����� ���������� ��������������� ����� ���������� ������������ (-1)^(i + j) 
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

// ���������� ������������ �������
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
		cout << "������� ���������� ������: " << endl;
		cin >> a;
	}
	return a;
}

// �������� ������� ������
void print(double **matrix, int n, string announce);

// ���������� �������
void reading_elements_matrix(double **matrix, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
			matrix[i][j] = read_and_check(matrix[i][j]);
		}
}

// ������������ 2� ������ � ��������� ���������� � ������
double **multiplication_matrix(double **matrix_1, double **matrix_2, double **matrix_3, int n)
{
	int m = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				matrix_3[i][j] = matrix_3[i][j] + matrix_1[i][k] * matrix_2[k][j];
	return matrix_3;
}

// ��������� ������� �� �����
double **multiplication_matrix_on_number(double **matrix, int n, int number)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = number * matrix[i][j];
	return matrix;
}

// �������� 2� ������
void addition_matrix(double **matrix_1, double **matrix_2, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix_1[i][j] = matrix_1[i][j] + matrix_2[i][j];
}

// ��������� �������
void zeroing(double **matrix, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = 0;
}

// ���������� ��������� �������, ���������� �� ���������
void addition_with_singular_matrix(double **matrix, int n, int number)
{
	for (int i = 0; i < n; i++)
		matrix[i][i] = matrix[i][i] + number;
}

// ����������� 2� ������ � ���������� ���������� � ������
void announcement_and_multiplication_matrix(double **matrix_1, double **matrix_2, double **matrix_3, int n, string announce)
{
	matrix_3 = multiplication_matrix(matrix_1, matrix_2, matrix_3, n);
	print(matrix_3, n, announce);
	cout << endl;
}

// �������� � ����� ������ �� �����
void addition_and_showing(double **matrix_1, double **matrix_2, int n, string announce)
{
	addition_matrix(matrix_1, matrix_2, n);
	print(matrix_1, n, announce);
	cout << endl;
}

// ��������� ������� �� ��������� � ����� �� �����
void announcement_and_multiplication_matrix_on_number(double **matrix, double n, string announce, int number)
{
	matrix = multiplication_matrix_on_number(matrix, n, number);
	print(matrix, n, announce);
	cout << endl;
}

// ����� ����� ������� �� �����
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

// ������� g(matrix) = matrix^3 + 5 * matrix
double **g(double **matrix_1, int n)
{
	// ��������� ������������ ������ ��� ��������������� �������
	double **matrix_2 = creating_matrix(n);
	// ��������� ������������ ������ ��� ������ ��������������� �������
	double **matrix_3 = creating_matrix(n);

	announcement_and_multiplication_matrix(matrix_1, matrix_1, matrix_2, n, "�������� ������� �� 2 �������\n");
	announcement_and_multiplication_matrix(matrix_1, matrix_2, matrix_3, n, "�������� ������� � 3 �������\n");

	announcement_and_multiplication_matrix_on_number(matrix_1, n, "�������� �������� ������� �� 5\n", 5);

	addition_matrix(matrix_1, matrix_3, n);
	print(matrix_1, n, "������� �� ����� f(g)\n");

	clearning_memory(matrix_2, n);
	clearning_memory(matrix_3, n);

	return matrix_1;
}

// ������� f(matrixx) = matrix^3 + 2 * matrix^2 + 5 * matrix + 10
double **f(double **matrix_1, int n)
{
	// ��������� ������������ ������ ��� ��������������� �������
	double **matrix_2 = creating_matrix(n);
	// ��������� ������������ ������ ��� ������ ��������������� �������
	double **matrix_3 = creating_matrix(n);

	announcement_and_multiplication_matrix(matrix_1, matrix_1, matrix_2, n, "�������� ������� f(g) �� 2 �������\n");
	announcement_and_multiplication_matrix(matrix_1, matrix_2, matrix_3, n, "�������� ������� f(g) � 3 �������\n");

	announcement_and_multiplication_matrix_on_number(matrix_2, n, "�������� ������� f(g)^2 �� 2\n", 2);
	announcement_and_multiplication_matrix_on_number(matrix_1, n, "�������� ������� f(g) �� 5\n", 5);

	addition_and_showing(matrix_3, matrix_2, n, "���������� f(g)^3 � 2 * f(g)^2\n");
	addition_and_showing(matrix_3, matrix_1, n, "���������� f(g)^3, 2 * f(g)^2 � 5 * f(g)\n");

	addition_with_singular_matrix(matrix_3, n, 10);
	print(matrix_3, n, "���������� f(g)^3, 2 * f(g)^2, 5 * f(g) � ��������� �������, ���������� �� 10\n");

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix_1[i][j] = matrix_3[i][j];

	clearning_memory(matrix_2, n);
	clearning_memory(matrix_3, n);

	return matrix_1;
}

// ����� �������
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

// �������� ������� �������
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

// ���������� �������, ���� � ����������
void fill_matrix(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];
}

// ��������� ������� ��� i-� ������ � j-�� ������� (�. �. ����������������� ���������)
double** create_minor(double** matrix, int n, int row_idx, int column_idx)
{
	double** minor;
	if (n == 1)
	{
		cout << "����� ������� ������� 1 �� ����������" << endl;
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

// �������� ������� � ���������
double** matrix_plus_single_matrix(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
		matrix[i][i]++;

	return matrix;
}

// �������� �������� �������
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

		// �������� ����������� ���� ������������ �������� �������
		if (det_matrix == 0)
		{
			cout << "\n������������ ������� ����� ����, �������� �� ����������.";
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
					cout << "�������� ������� �� ����������! \n";
					return 0;
				}
				else
					det_minor = determinant(minor, n - 1);
				inverse_matrix[i][j] = 1 / det_matrix * pow(-1, i + j) * det_minor;
			}
		return inverse_matrix;
	}
}

// ������������ 2� ������ � ��������� ���������� � ������
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

// ������� ���������� ���������
double** decide_matrix_equation(double** matrix_1, double** matrix_2, int n)
{
	double det = determinant(matrix_1, n);

	matrix_1 = matrix_plus_single_matrix(matrix_1, n);
	announce_and_print_matrix(matrix_1, "\n���������� 1� ������� � ���������: \n", n);
	// �������� ����������� ���� ������������ �������� �������
	if (create_inverse_matrix(matrix_1, n) == 0)
	{
		cout << "\n������� ���! ";
		return 0;
	}

	matrix_1 = create_inverse_matrix(matrix_1, n);
	if (matrix_1 == 0)
		return 0;
	announce_and_print_matrix(matrix_1, "\n������� �������� ������� ��� 1�: \n", n);

	double** matrix_3 = multiplication_matrix(matrix_2, matrix_1, n);
	announce_and_print_matrix(matrix_3, "\n�������� ���������� �������� ������� �� ������: \n", n);

	cleaning_memory(matrix_3, n);
	return matrix_3;
}

