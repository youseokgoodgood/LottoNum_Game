#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
int main(void) {
	/*
	* �ζǹ�ȣ ���߱� ����
	*
	* - ���� ����
	* 1. for���� Math.
	*/
	int input[6]; // ����� ��ȣ�� ������� ������ �迭
	int random[10]; // �ζǹ�ȣ�� ����� ���� ������ �迭
	int cnt = 0;
	int duplicateInput = 0;
	int cancleNum = 0;
	bool bounsNum = false;

	while (1) {
		printf("�ζǹ�ȣ 6�ڸ��� �Է� �ϼ���: ");

		for (int i = 0; i < 6; i++)
		{
			scanf("%d", &input[i]);
			printf("%d", input[i]);

			if (input[i - 1] > 99) {
				printf("----------------------------------------------------------------------------------------------\n");
				printf("\n");
				printf("\n����° �ڸ��� �Է� �� �� �����ϴ�.\n");
				printf("----------------------------------------------------------------------------------------------\n");
				printf("\n");
				return 0;
			}
			else if (i > 0) {
				duplicateInput = input[i];
				for (int j = 0; j < i; j++) {
					if (duplicateInput == input[j]) {
						printf("\n----------------------------------------------------------------------------------------------\n");
						printf("\n");
						printf("\n������ ���ڴ� �Է� �� �� �����ϴ�.\n");
						printf("----------------------------------------------------------------------------------------------\n");
						printf("\n");
						return 0;
					}
				}
			}
		}

		for (int i = 1; i < 8; i++) {
			random[i - 1] = rand() % 46; // ���� ����
			//printf("%d ", random[i - 1]);
		}

		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 6; j++) {
				if (random[i] == input[j]) {
					cnt++;

				}

				bounsNum = random[6] == input[j] ? true : false;
			}
		}

		printf("\n----------------------------------------------------------------------------------------------\n");
		printf("\n");
		printf("�ζǹ�ȣ: ");
		for (int i = 0; i < 7; i++) {
			printf("%d ", random[i]);
		}

		printf("\n");
		printf("�Է¹�ȣ: ");
		for (int i = 0; i < 6; i++) {
			printf("%d ", input[i]);
		}

		printf("\n");
		printf("���� ����: %d\n", cnt);

		printf("\n\n----------------------------------------------------------------------------------------------\n");
		printf("\n");

		printf("1�� - 6�� ��ȣ ��ġ\n");
		printf("2�� - 5�� ��ȣ ��ġ+ ���ʽ� ��ȣ��ġ\n");
		printf("3�� - 5�� ��ȣ ��ġ\n");
		printf("4�� - 4�� ��ȣ ��ġ\n");
		printf("5�� - 3�� ��ȣ ��ġ\n");

		printf("----------------------------------------------------------------------------------------------\n");
		printf("\n");


		if (cnt == 3) {
			printf("5�� �Դϴ�.\n");
		}
		else if (cnt == 4) {
			printf("4�� �Դϴ�.\n");
		}
		else if (cnt == 5) {
			printf("3�� �Դϴ�.\n");
		}
		else if (cnt == 5 && bounsNum) {
			printf("2�� �Դϴ�.\n");
		}
		else if (cnt == 6) {
			printf("1�� �Դϴ�.\n");
		}
		else {
			printf("��÷�� ��ȣ�� �����ϴ�.\n");
		}
		printf("\n");
		printf("----------------------------------------------------------------------------------------------\n");

		printf("\n\n----------------------------------------------------------------------------------------------\n");
		printf("\n");

		printf("������ �׸� �Ͻðڽ��ϱ�? �׸��α� : 1 , ����ϱ� : 2     ");

		scanf("%d", &cancleNum);

		if (cancleNum == 1) {
			break;
		}
		else {
			cnt = 0;
			duplicateInput = 0;
			cancleNum = 0;
			bounsNum = false;
		}

	}
	return 0;

}