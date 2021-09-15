// 2.2. Вывод каждого четвертого элемента массива

// Напишите функцию с названием printer. Функция принимает два указателя на целое число. Первый указатель указывает на начало массива, а второй на элемент, следующий за последним элементом массива.
// Напишите код, который выводит каждый четвертый элемент массива, если он делится на 4 нацело.

// Примените для вывода функцию printf("%ld\n", num), где num - это очередное число для вывода.

#include <stdio.h>

void printer(long long int* begin, long long int* end);

void printer(long long int* begin, long long int* end) // Указатели на элементы массива с 64-байтовыми числами (long long int)
{
    if (begin < end) // В условии 'end' - указатель на следующий байт после конца массива
    {
        for (long long int* i = begin + 3; i < end; i+=4)
        {
            if (*i % 4 == 0) // *i эквивалентно *(arr+i)
                printf("%I64d ", *i);
        }
    }
    printf("\n");
}

int main()
{
	long long int a[] = {1,2,3,4,5,6,7,8};
	int a_size = 8;
	long long int b[] = {120,50,60,92,16,20,796,53,14,679,5000,2000,497,123,15,78};
	int b_size = 16;
	long long int c[] = {-1,-2,-3,-4,-100,-120,200,600};
	int c_size = 8;
	long long int d[] = {1,4,8,-5000000000,600,800,1000,5000000000};
	int d_size = 8;
	long long int x[] = {1,2,3,8000000000,5,6,7,99,9,10,11,16,13};
	int x_size = 13;
	long long int* a_begin = a;
	long long int* a_end = a + a_size;
	long long int* b_begin = b;
	long long int* b_end = b + b_size;
	long long int* c_begin = c;
	long long int* c_end = c + c_size;
	long long int* d_begin = d;
	long long int* d_end = d + d_size;
	long long int* x_begin = x;
	long long int* x_end = x + x_size;
	printer(a_begin, a_end);
	printer(b_begin, b_end);
	printer(c_begin, c_end);
	printer(d_begin, d_end);
	printer(x_begin, x_end);
	return 0;
}
