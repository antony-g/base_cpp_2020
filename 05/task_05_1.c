// 5.1. Перевод из десятичной формы записи в восьмеричную

// Напишите код, который считывает из стандартного ввода числа в десятичной форме записи и выводит эти числа построчно в восьмеричной форме.

// Программа завершается, когда стандартный ввод закрывается или поступили некорректные данные.

#define __USE_MINGW_ANSI_STDIO 1
// Для использования формата вывода "%lld"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long int pow(long long int x, int a);
void to_binary(int x);
char* to_oct(char* s, long long int n);
long long int to_oct_1(long long int x, int a);

long long int pow(long long int x, int a)
{
    long long int res = 1;
    while (a > 0 && a--)
    {
        res *= x;
    }
    return res;
}

void to_binary(int x)
{
    register int i;
    for (i = 128; i > 0; i /= 2){
        if (x & i) printf("1");
        else printf("0");
    }
    printf("\n");
}

char* to_oct(char* s, long long int n){
    char* i, c, *t = s;
    unsigned long long int x = (unsigned long long int)n;
    do {
        *s++ = (char)(x & 0x7) + '0';
    } while((x >>= 3) != 0);
    *s = '\0';
 
    for (i = t, --s; i < s; ++i, --s){
        c  = *i;
        *i = *s;
        *s = c;
    }
    return t;
}

long long int to_oct_1(long long int x, int a){
	long long int remainder = x % pow(8, a);
	if (x % pow(8, a) == x)
		return x / pow(8, a - 1);
	else
		return remainder / pow(8, a - 1) + 10*to_oct_1(x - remainder, a + 1);
}

int main()
{
	char c[23];
    long long int *m = (long long int*) malloc(10 * sizeof(long long int));
    int i = 0, j = 0;
    while( scanf("%I64d", &m[i]) == 1 && (c[0] = getchar()) != '.' && ++i )
    {
        if (i % 9 == 0)
            realloc(m, (i + 10) * sizeof(long long int));
    }
    for(j = 0; j < i; ++j)
        printf("%s ", to_oct(c, m[j]));
    free(m);
    return 0;
}
