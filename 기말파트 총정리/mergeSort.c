#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//A[p...q], A[q+1....r]������ merge
void merge(int* A, int p, int q, int r, int* B)
{
	int i, j, t;

	i = p;
	j = q + 1;
	t = 0;  //B�� ä���� ��ġ

	//�� �� �ϳ��� ����� Ż��(&&)
	while (i <= q && j <= r) {
		if (A[i] < A[j])
			B[t++] = A[i++];
		else
			B[t++] = A[j++];
	}

	//copy...(���� �� ����) >> ���ʿ����� �� ��� ���Ҵ��� Ȯ��
	if (i > q)	//������ ����
		for (; j <= r; j++)
			B[t++] = A[j];
	else    //�������� ����
		for (; i <= q; i++)
			B[t++] = A[i];
	
	//B�� ����� ���������� ���ĵ� �迭�� A�� copy
	for (i = p, t = 0; i <= r; i++, t++)
		A[i] = B[t];
}

void mergeSort(int* A, int p, int r, int* B)
{
	int q;

	if (p < r) {
		q = (p + r) / 2;
		mergeSort(A, p, q, B);
		mergeSort(A, q + 1, r, B);
		merge(A, p, q, r, B);
	}
}

int main()
{
	int* A;
	int* B;
	int n;
	int i;

	scanf("%d", &n);

	A = (int*)malloc(sizeof(int) * n);
	B = (int*)malloc(sizeof(int) * n);

	srand(time(NULL));
	for (i = 0; i < n; i++)
		A[i] = rand() % 1000;

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");
	mergeSort(A, 0, n - 1, B);

	for (i = 0; i < n; i++)
		printf("%d ", A[i]);
	printf("\n");

	free(A);
	free(B);
	return 0;
}