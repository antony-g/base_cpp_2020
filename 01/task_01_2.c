// 1.2. Возведение в степень с помощью функции pow

// Напишите функцию с названием pow. Функция принимает на вход два целых числа: число и степень, в которую нужно возвести это число.

// Функция возвращает целое число, которое получилось в результате возведения в степень. Если вычисление невозможно произвести, верните 0. Используйте рекурсию.

#include <stdio.h>

double pow(double x, int a);

double pow(double x, int a)
{
	if ((long long int) x % 2 == 0)
		if (a == 1)
			return x;
	    else if (a == 0)
	    	return 1;
		else if (a > 1)
			return pow((long long int) x << 1, a - 1);
	    else
	    	return 0;
    else if (a == 1)
    	return x;
    else if (a == 0)
    	return 1;
	else if (a > 1)
    	return x * pow(x, a - 1);
    else
    	return 0;
}

int main()
{
	printf("%f\n", pow(2, 5));
	printf("%f\n", pow(3, 8));
	printf("%f\n", pow(2, 62));
	printf("%f\n", pow(4, 1));
	printf("%f\n\n", pow(8, 0));
	return 0;
}
