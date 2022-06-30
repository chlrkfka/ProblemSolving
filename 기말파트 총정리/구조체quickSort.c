#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int korean, english, math;
} Student;
//pivot�� return
int partitionK(Student* A, int p, int r)
{
    int i, j;
    Student t;

    j = p;
    i = p - 1;

    for (; j < r; j++) {
        if (A[j].korean > A[r].korean) {
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    i++;
    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i;
}
int partitionE(Student* A, int p, int r)
{
    int i, j;
    Student t;

    j = p;
    i = p - 1;

    for (; j < r; j++) {
        if (A[j].english > A[r].english) {
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    i++;
    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i;
}
int partitionM(Student* A, int p, int r)
{
    int i, j;
    Student t;

    j = p;
    i = p - 1;

    for (; j < r; j++) {
        if (A[j].math > A[r].math) {
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    i++;
    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i;
}
int partitionID(Student* A, int p, int r)
{
    int i, j;
    Student t;

    j = p;
    i = p - 1;

    for (; j < r; j++) {
        if (A[j].id < A[r].id) {
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    i++;
    t = A[i];
    A[i] = A[r];
    A[r] = t;

    return i;
}
void quickSort(Student* A, int p, int r, int choice)
{
    int q;

    if (p < r) {
        switch (choice) {
        case 1:
            q = partitionK(A, p, r);
            break;
        case 2:
            q = partitionM(A, p, r);
            break;
        case 3:
            q = partitionE(A, p, r);
            break;
        case 4:
            q = partitionID(A, p, r);
            break;
        }
        quickSort(A, p, q - 1, choice);
        quickSort(A, q + 1, r, choice);
    }
}
int main()
{
    int n;
    int i;
    int choice;

    printf("�л� ���� �Է��ϼ��� : ");
    scanf("%d", &n);
    Student* slist = (Student*)malloc(sizeof(Student) * n);

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        slist[i].id = i + 1;
        slist[i].korean = rand() % 101;
        slist[i].english = rand() % 101;
        slist[i].math = rand() % 101;
    }
    for (i = 0; i < n; i++) {
        printf("�й� : %-7d���� : %-7d���� : %-7d���� : %-7d\n", slist[i].id, slist[i].english, slist[i].math, slist[i].korean);
    }

    do {
        printf("\n���� ���� ����<1:����, 2:����, 3:����, 4:id(��������), 0:������> : ");
        scanf("%d", &choice);

        while (choice < 0 || choice >= 5) {
            printf("�ٽ� �����ϼ��� : ");
            scanf("%d", &choice);
        }
        if (choice == 0)
            break;
        quickSort(slist, 0, n - 1, choice);
        for (i = 0; i < n; i++) {
            printf("�й� : %-7d���� : %-7d���� : %-7d���� : %-7d\n", slist[i].id, slist[i].english, slist[i].math, slist[i].korean);
        }
    } while (choice > 0 && choice < 5);

    free(slist);
    return 0;
}