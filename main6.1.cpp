/*�� ���� ��������� �������. 
��� ��������� f(x) = x^3 + 2 * x^2 + 5 * x + 10, g(x) = x^3 + 5 * x.
����� ����� f(g(A)) */
#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include "matrix.h"
using namespace std;

// �������� ������������ �����
template <class T>
T read_and_check(T a)
{
	while (cin.fail() || a < 1)
	{
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "������� ���������� ������: " << endl;
		cin >> a;
	}
	return a;
}

int main()
{
	setlocale(LC_ALL, "rus");
	int n = 0;

	cout << "������� ������ ������� � ���� �������: " << endl;
	cin >> n;
	n = read_and_check(n);

	// ��������� ������������ ������ ��� �������� �������
	double **matrix_1 = creating_matrix(n);

	reading_elements_matrix(matrix_1, n);
	print(matrix_1, n, "\n�������� �������\n");

	// ������� g(matrix) = matrix^3 + 5 * matrix
	matrix_1 = g(matrix_1, n);

	// ������� f(matrixx) = matrix^3 + 2 * matrix^2 + 5 * matrix + 10
	matrix_1 = f(matrix_1, n);

	// ������� ������
	clearning_memory(matrix_1, n);

	system("pause");
	return 0;
}

/*
3
1 1 1  1 1 1  1 1 1
*/

/*
2
1 1  1 1
*/

/*
2
1 2 1 2
*/

