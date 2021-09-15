// 5.2. Сложение и вычитание целочисленных векторов

// Напишите программу для сложения и вычитания целочисленных векторов.
// Программа считывает знак операции + или -. Затем считывает количество элементов в векторах, затем элементы первого и второго векторов. Программа выводит элементы результирующего вектора через пробел. Если операцию провести невозможно, выведите error.

#define __USE_MINGW_ANSI_STDIO 1 

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    char operator;
    int size = 0, n = 0;
    int j = 0;

    while((c = getc(stdin)) != '\n' && c != EOF && ungetc(c, stdin))
    {
        scanf("%c", &operator);
        scanf("%d", &size);
        long long int *a = (long long int*) calloc(size, sizeof(long long int));
        long long int *b = (long long int*) calloc(size, sizeof(long long int));

        for(j = 0; j < size; ++j)
        {
            if (j % 9 == 0)
                a = (long long int*) realloc(a, (j + 10) * sizeof(long long int));
            n = scanf("%lld", &a[j]);
            if (n != 1)
            {
                printf("error");
                return 0;
            }
        }

        for(j = 0; j < size; ++j)
        {
            if (j % 9 == 0)
                b = (long long int*) realloc(b, (j + 10) * sizeof(long long int));
            n = scanf("%lld", &b[j]);
            if (n != 1)
            {
                printf("error");
                return 0;
            }
        }

        switch (operator)
        {
            case '+':
            {
                for(j = 0; j < size; ++j)
                {
                    printf("%lld ", a[j] + b[j]);
                }
                printf("\n");
                break;
            }
            case '-':
            {
                for(j = 0; j < size; ++j)
                {
                    printf("%lld ", a[j] - b[j]);
                }
                printf("\n");
                break;
            }
            default:
            {
                printf("error");
            }
        }
    }
    return 0;
}
