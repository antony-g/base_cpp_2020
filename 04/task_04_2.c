// 4.2. Перевод буквенных символов в верхний регистр

// Напишите функцию с названием upperCase, которая принимает строку и видоизменяет ее таким образом, что все буквенные символы в ней переводятся в верхний регистр. Функция ничего не возвращает, библиотечные функции использовать запрещено.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void upperCase(char* a);
void upperCase1(char* a, char* b);

void upperCase(char* a){
	while (*a != '\0')
	{
		if (*a >= 'a' && *a <= 'z')
		{
			*a -= 32;
		}
		a++;
	}
}

void upperCase1(char* a, char* b){
	while (*a != '\0')
		if (*a >= 'a' && *a <= 'z'){
			*b++ = *a++ - 32;
		}
		else
			*b++ = *a++;
}

int main()
{
	char x[] = "Hello World!";
	printf("%s\n", x);
	upperCase(x);
	printf("%s\n\n", x);

	char y[] = "Sed non dolor ac diam dignissim pharetra. Nullam eleifend pellentesque eleifend. Sed eget risus id lorem molestie sollicitudin id at ligula. Nullam sodales urna sit amet leo pharetra, non fermentum mi volutpat. Nulla eget enim massa. In hac habitasse platea dictumst. Duis eu erat varius, dignissim justo et, posuere ex. Nunc consectetur ac metus eu malesuada. Fusce vel neque malesuada, aliquet erat ut, faucibus ante. Aliquam auctor velit a ipsum egestas vehicula. Sed sed dignissim lorem. Quisque sollicitudin vulputate nisi, eget tempor urna iaculis vel. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Cras suscipit id lacus a aliquet. Donec mattis elementum ligula, id aliquet nisl luctus non.";
	upperCase(y);
	printf("%s\n", y);

	return 0;
}
