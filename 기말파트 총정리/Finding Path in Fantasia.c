#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n, m;
	int rootN = 1, rootM = 1;	//�����
	//���� ����, ���� �и�, ������ ����, ������ �и�
	int pLN = 0, pLM = 1, pRN = 1, pRM = 0;

	scanf("%d %d", &n, &m);

	while (n * rootM != m * rootN) {
		if (n * rootM < m * rootN) {
			pRN = rootN;
			pRM = rootM;
			printf("L");
		}
		else {
			pLN = rootN;
			pLM = rootM;
			printf("R");
		}
		rootN = pRN + pLN;
		rootM = pRM + pLM;
	}
	printf("\n");
}