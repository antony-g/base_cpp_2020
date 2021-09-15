// 1.1. ����� ����� � ������� ������� even

// �������� ������� � ��������� even, ������� ��������� �� ���� ����� �����. ��� ������ ������� ���������� ���� ������������� ������ ����� �� 1 �� ����� ����� ������������.

// ��������� ������ ������� even ����� ���������� � printf("%ld ", num), ��� num - ��� ���������� ������������� ������ �����.

#include <stdio.h>
#include <stdint.h>

void even1(int64_t x);
int even2(int64_t x);

void even1(int64_t x)
{
	int64_t num = 0;
    for (int i = 1; i <= x; ++i)
    {
        if(i % 2 == 0)
            num++;
    }
    printf("%I64d ",num);
}

int even2(long long int x)
{
	if (x > 0)
		return x >> 1;
	else
		return 0;
}

int main()
{
	printf("%d\n", even2(-10));
	printf("%d\n", even2(5001));
	return 0;
}
