// лаба 6.2
/*Необходимо вычислить поределитель матрицы порядка n, 
элементы которого заданы условием (a)ij = min(i, j)*/
#include <iostream>
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

	double **matrix = creating_matrix(n);


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
}