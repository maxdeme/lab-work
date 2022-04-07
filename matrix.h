#ifndef _MATRIX_
#define _MATRIX_

#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;

// проверка корректности ввода
template <class T>
T read_and_check(T a);

// заполнение матрицы
void reading_elements_matrix(double** matrix, int n);

// перемножение 2х матриц и занесение полученной в третью
double** multiplication_matrix(double** matrix_1, double** matrix_2, double** matrix_3, int n);

// умножение матрицы на число
double** multiplication_matrix_on_number(double** matrix, int n, int number);

// сложение 2х матриц
void addition_matrix(double** matrix_1, double** matrix_2, int n);

// обнуление матрицы
void zeroing(double** matrix, int n);

// добавление единисной матрицы, умноженной на константу
void addition_with_singular_matrix(double** matrix, int n, int number);

// вывод шагов решения на экран
void print(double** matrix, int n, string announce);

// функция g(matrix) = matrix^3 + 5 * matrix
double** g(double** matrix_1, int n);

// функция f(matrixx) = matrix^3 + 2 * matrix^2 + 5 * matrix + 10
double** f(double** matrix_1, int n);

// проверка корректности ввода
int read_and_check(int a);

// заполнение матрицы
void fill_matrix(double** matrix, int n);

// вывод матрицы
void print_matrix(double** matrix, string announce, int n);

// очистка памяти
void cleaning_memory(double** matrix, int n);

// получение матрицы без i-й строки и j-го столбца (т. е. перенумеровывание элементов)
void renumber_matrix(double** matrix, double** new_matrix, int i, int j, int n);

// проверка корректности ввода
int read_and_check(int a);

// вывод матрицы
void announce_and_print_matrix(double** matrix, string announce, int n);

// создание нулевой матрицы
double** create_zero_matrix(int n);

// создание квадратной матрицы
double** creating_matrix(int n);

// вычисление определителя матрицы
double determinant(double** matrix, int n);

// сложение матрицы с единичной
double** matrix_plus_single_matrix(double** matrix, int n);

/* создание обратной матрицы
если обратной матрицы не существует, функция вернёт 0 */
double** create_inverse_matrix(double** matrix, int n);

// перемножение 2х матриц и занесение полученной в третью
double** multiplication_matrix(double** matrix_1, double** matrix_2, int n);

// решение матричного уравнения
double** solve_matrix_equation(double** matrix_1, double** matrix_2, int n);

//Вычисляет определитель матрицы порядка n,
//элементы которого заданы условием(a)ij = min(i, j) * /
void counting_determinant();

//Дан многочлен f(x) = x^3 + 2 * x^2 + 5 * x + 10, g(x) = x^3 + 5 * x.
//Находит f(g(A))
void count_value_polynomial(double** matrix_a_new, int n);

#endif // !_MATRIX_#pragma once
