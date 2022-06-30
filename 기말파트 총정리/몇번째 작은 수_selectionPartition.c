#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int* A, int p, int r)
{
    int i, j;
    i = p - 1;
    int t;

    for (j = p; j < r; j++) {
        if (A[j] < A[r]) {
            i++;
            //swap A[j] A[i]
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    i++;
    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i;   //pivot�� �ε����� return
}
//A[p.....r]
//q�� subarray���� q-p+1��°
int selection(int* A, int p, int r, int i)
{
    int q;
    int rank;

    q = partition(A, p, r);
    rank = q - p + 1;

    if (i == rank) //ã�� ���
        return A[q];
    else if (i < rank)    //���ʿ� ���� ���ȣ��
        return selection(A, p, q - 1, i);
    else    //�����ʿ� ���� ���ȣ��
        return selection(A, q + 1, r, i - rank);   //i-rank : 7��°�� ���� �� ������ �迭�� 3��°�� �׷� ���
}
int main()
{
    int* A;
    int n, i, rank;

    printf("Enter the number of numbers: ");
    scanf("%d", &n);
    printf("���°�� ���� ��: ");
    scanf("%d", &rank);

    A = (int*)malloc(sizeof(int) * n);

    srand(time(NULL));
    for (i = 0; i < n; i++)
        A[i] = rand() % 1000;

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    printf("%d��° ���� ���� %d\n", rank, selection(A, 0, n - 1, rank));

    free(A);
    return 0;
}