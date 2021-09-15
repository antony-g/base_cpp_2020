// 3.1. Возврат определителя квадратной матрицы

// Напишите функцию с названием det, которая принимает квадратную матрицу, размерностью n, и возвращает её определитель. Указатель на матрицу и целочисленный параметр n передаются в функцию аргументом.

#include <stdio.h>
#include <stdlib.h>

long int* sub_matrix(long int** a, int n, int pos);
long int det(long int** a, size_t n);

long int* sub_matrix(long int** a, int n, int pos){
	// Возвращает указатель матрицы более низкого порядка для вычисления определителя исходной матрицы (работает с квадратными матрицами). n - размерность матрицы, pos - позиция элемента в первой строке старшей матрицы (в пределах [0, n-1]).
	long int* ptr2 = malloc((n-1)*(n-1)*sizeof(long int));
	if(ptr2 == NULL) 
	{
	  printf("Ошибка выделения памяти");
	  return 0;
	}
	int t = 0;
	long int* ptr1 = a[0];
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			{
				if(j == pos)
					continue;
				else
					ptr2[t] = ptr1[i*n + j];
					t++;
			}
	}
	return ptr2;
}

long int det(long int** a, size_t n){
	// Возвращает определитель исходной матрицы (работает с квадратными матрицами). n - размерность матрицы
	long int res = 0;
	long int* x = *a;
	int degree = 1;
	if(n == 1)
		res = x[0];
	if(n == 2)
	{
		res = x[0]*x[3]-x[1]*x[2];
	}
	else
		for(int i = 0; i < n; i++)
		{
			long int* b = malloc((n-1)*(n-1)*sizeof(long int));
			b = sub_matrix(a, n, i);
			long int** c = &b;
			res += degree*a[0][i]*det(c, n-1);
			degree = -degree;
			free(b);
		}
	return res;
}

int main()
{
	long int x[] = {8, 5, 10, 3,
					3, 1, 7, 1,
					8, 7, 10, 2,
					10, 6, 10, 5};
	long int* y = &x[0];
	long int** z = &y;
	long int res = det(z, 4);
	printf("%ld\n", res);

	return 0;
}
