// ���� 6.2
/*���������� ��������� ������������ ������� ������� n, 
�������� �������� ������ �������� (a)ij = min(i, j)*/
#include <iostream>
#include <algorithm>
#include <string>
#include "matrix.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������� ������ �������: " << endl;

	int n = 0;
	cin >> n;
	n = read_and_check(n);

	double **matrix = creating_matrix(n);


	cout << "\n������� �������" << endl;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];

	//fill_matrix(matrix, n);
	print_matrix(matrix, "\n�������� �������:\n", n);

 	double det = determinant(matrix, n);
	cout << "\n������������ �������� ������� = " << det << endl << endl;

	cleaning_memory(matrix, n);

	system("pause");
	return 0;
}