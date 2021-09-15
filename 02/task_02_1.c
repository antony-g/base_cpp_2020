// 2.1. Возврат максимального элемента в массиве

// Напишите функцию с названием max, которая принимает на вход массив целых чисел и количество элементов в массиве. Функция должна возвращать значение максимального элемента в массиве. Если вычисление произвести невозможно, верните 0.

#include <stdio.h>

long long int max(long long int arr[], int size);

long long int max(long long int arr[], int size)
{
    if (size > 0)
    {
        long long int res = arr[0];
        for (int i = 1; i < size; i++)
        	res = arr[i] > res ? arr[i]: res;
        return res;
    }
    else
        return 0;
}

int main()
{
	long long int a[] = {1,2,3,4,5};
	int a_size = 5;
	long long int b[] = {-3000000000,500,200,100,-500,9000000000};
	int b_size = 6;
	printf("%I64d\n", max(a, a_size));
	printf("%I64d\n", max(b, b_size));
	return 0;
}
