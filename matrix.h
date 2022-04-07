#ifndef _MATRIX_
#define _MATRIX_

#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;

// �������� ������������ �����
template <class T>
T read_and_check(T a);

// ���������� �������
void reading_elements_matrix(double** matrix, int n);

// ������������ 2� ������ � ��������� ���������� � ������
double** multiplication_matrix(double** matrix_1, double** matrix_2, double** matrix_3, int n);

// ��������� ������� �� �����
double** multiplication_matrix_on_number(double** matrix, int n, int number);

// �������� 2� ������
void addition_matrix(double** matrix_1, double** matrix_2, int n);

// ��������� �������
void zeroing(double** matrix, int n);

// ���������� ��������� �������, ���������� �� ���������
void addition_with_singular_matrix(double** matrix, int n, int number);

// ����� ����� ������� �� �����
void print(double** matrix, int n, string announce);

// ������� g(matrix) = matrix^3 + 5 * matrix
double** g(double** matrix_1, int n);

// ������� f(matrixx) = matrix^3 + 2 * matrix^2 + 5 * matrix + 10
double** f(double** matrix_1, int n);

// �������� ������������ �����
int read_and_check(int a);

// ���������� �������
void fill_matrix(double** matrix, int n);

// ����� �������
void print_matrix(double** matrix, string announce, int n);

// ������� ������
void cleaning_memory(double** matrix, int n);

// ��������� ������� ��� i-� ������ � j-�� ������� (�. �. ����������������� ���������)
void renumber_matrix(double** matrix, double** new_matrix, int i, int j, int n);

// �������� ������������ �����
int read_and_check(int a);

// ����� �������
void announce_and_print_matrix(double** matrix, string announce, int n);

// �������� ������� �������
double** create_zero_matrix(int n);

// �������� ���������� �������
double** creating_matrix(int n);

// ���������� ������������ �������
double determinant(double** matrix, int n);

// �������� ������� � ���������
double** matrix_plus_single_matrix(double** matrix, int n);

/* �������� �������� �������
���� �������� ������� �� ����������, ������� ����� 0 */
double** create_inverse_matrix(double** matrix, int n);

// ������������ 2� ������ � ��������� ���������� � ������
double** multiplication_matrix(double** matrix_1, double** matrix_2, int n);

// ������� ���������� ���������
double** solve_matrix_equation(double** matrix_1, double** matrix_2, int n);

//��������� ������������ ������� ������� n,
//�������� �������� ������ ��������(a)ij = min(i, j) * /
void counting_determinant();

//��� ��������� f(x) = x^3 + 2 * x^2 + 5 * x + 10, g(x) = x^3 + 5 * x.
//������� f(g(A))
void count_value_polynomial(double** matrix_a_new, int n);

#endif // !_MATRIX_#pragma once
