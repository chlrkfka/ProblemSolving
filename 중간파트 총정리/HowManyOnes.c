#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//c���� 1�� �����
int solution(int c)
{
	if (c == 1)
		return 1;
	else
		return 1 + solution(c / 10);
}
//ã�� ���� 1�θ� ������ ���� �´���
int isItAll(int c)
{
	while (c != 0) {
		if (c % 10 != 1)
			return 0;
		else
			c /= 10;
	}
	return 1;
}
//b = _n�̴ϱ� c�� ã�ƾ� ��(�Լ� ȣ��)
void findC(int a, int n)
{
	int i = 0;

	while (!isItAll(a * (i * 10 + n))) {
		i++;
	}
	printf("%d\n", solution(a * (i * 10 + n)));
}
//a�� ���ؼ� ���� �ڸ����� 1�� �� ã��
void findB(int a)
{
	int i;

	for (i = 1; i < 10; i++) {
		if ((a * i) % 10 == 1)
			findC(a, i);
	}

}
int main()
{
	int a;

	scanf("%d", &a);

	findB(a);
}