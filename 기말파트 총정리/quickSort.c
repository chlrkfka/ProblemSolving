#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//pivot�� return
int partition(int* A, int p, int r)
{
    int i, j;
    int t;  //swap�� ���� ����

    j = p;    //���������� loop�� ���� ��
    i = p - 1;  //pivot���� ���� �ָ� ã�� ����(������ boundary)

    for (; j < r; j++) {
        if (A[j] < A[r]) {
            i++;
            //swap A[i] A[j]
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    i++;
    //swap A[i] A[r](pivot�� �����)
    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i;
}
void quickSort(int* A, int p, int r)
{
    int q;
    //�����ؾ� �ϴ� �� 0���� 1���̸� �׳� return
    if (p < r) {
        q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
        //pivot�� ���Ŀ� ���Ե��� �ʴ´�
    }
}
int main()
{
    int* A;
    int n;  //arrayũ��
    int i;

    scanf("%d", &n);
    A = (int*)malloc(sizeof(int) * n);

    srand(time(NULL));
    for (i = 0; i < n; i++)
        A[i] = rand() % 1000;

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
    quickSort(A, 0, n - 1);

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    free(A);
    return 0;
}