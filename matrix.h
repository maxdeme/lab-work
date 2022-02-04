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
void reading_elements_matrix(double **matrix, int n);

// перемножение 2х матриц и занесение полученной в третью
double **multiplication_matrix(double **matrix_1, double **matrix_2, double **matrix_3, int n);

// умножение матрицы на число
double **multiplication_matrix_on_number(double **matrix, int n, int number);

// сложение 2х матриц
void addition_matrix(double **matrix_1, double **matrix_2, int n);

// обнуление матрицы
void zeroing(double **matrix, int n);

// добавление единисной матрицы, умноженной на константу
void addition_with_singular_matrix(double **matrix, int n, int number);

// перемножене 2х матриц и сохранение результата в третью
void announcement_and_multiplication_matrix(double **matrix_1, double **matrix_2, double **matrix_3, int n, string announce);

// сложение и вывод матриц на экран
void addition_and_showing(double **matrix_1, double **matrix_2, int n, string announce);

// умножение матрицы на константу и вывод на экран
void announcement_and_multiplication_matrix_on_number(double **matrix, double n, string announce, int number);

// вывод шагов решения на экран
void print(double **matrix, int n, string announce);

// функция g(matrix) = matrix^3 + 5 * matrix
double **g(double **matrix_1, int n);

// функция f(matrixx) = matrix^3 + 2 * matrix^2 + 5 * matrix + 10
double **f(double **matrix_1, int n);

// проверка корректности ввода
int read_and_check(int a);

// заполнение матрицы
void fill_matrix(double **matrix, int n);

// вывод матрицы
void print_matrix(double **matrix, string announce, int n);

// очистка памяти
void cleaning_memory(double **matrix, int n);

// получение матрицы без i-й строки и j-го столбца (т. е. перенумеровывание элементов)
void renumber_matrix(double **matrix, double **new_matrix, int i, int j, int n);

// проверка корректности ввода
int read_and_check(int a);

// вывод матрицы
void announce_and_print_matrix(double** matrix, string announce, int n);

// создание нулевой матрицы
double** create_zero_matrix(int n);

// создание квадратной матрицы
double** creating_matrix(int n);

/*проверка существования и получение матрицы без i - й строки и j - го столбца(т.е.перенумеровывание элементов)
 если минора не существует, функция вернёт 0*/ 
double** create_minor(double** matrix, int n, int row_idx, int column_idx);

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
double** decide_matrix_equation(double** matrix_1, double** matrix_2, int n);

#endif // !_MATRIX_


