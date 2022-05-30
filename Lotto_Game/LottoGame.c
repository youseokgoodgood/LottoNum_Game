#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
int main(void) {
	/*
	* 로또번호 맞추기 게임
	*
	* - 사용된 구문
	* 1. for문과 Math.
	*/
	int input[6]; // 사용자 번호를 담기위한 정수형 배열
	int random[10]; // 로또번호를 만들기 위한 정수형 배열
	int cnt = 0;
	int duplicateInput = 0;
	int cancleNum = 0;
	bool bounsNum = false;

	while (1) {
		printf("로또번호 6자리를 입력 하세요: ");

		for (int i = 0; i < 6; i++)
		{
			scanf("%d", &input[i]);
			printf("%d", input[i]);

			if (input[i - 1] > 99) {
				printf("----------------------------------------------------------------------------------------------\n");
				printf("\n");
				printf("\n세번째 자리는 입력 할 수 없습니다.\n");
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
						printf("\n동일한 숫자는 입력 할 수 없습니다.\n");
						printf("----------------------------------------------------------------------------------------------\n");
						printf("\n");
						return 0;
					}
				}
			}
		}

		for (int i = 1; i < 8; i++) {
			random[i - 1] = rand() % 46; // 난수 생성
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
		printf("로또번호: ");
		for (int i = 0; i < 7; i++) {
			printf("%d ", random[i]);
		}

		printf("\n");
		printf("입력번호: ");
		for (int i = 0; i < 6; i++) {
			printf("%d ", input[i]);
		}

		printf("\n");
		printf("맞춘 갯수: %d\n", cnt);

		printf("\n\n----------------------------------------------------------------------------------------------\n");
		printf("\n");

		printf("1등 - 6개 번호 일치\n");
		printf("2등 - 5개 번호 일치+ 보너스 번호일치\n");
		printf("3등 - 5개 번호 일치\n");
		printf("4등 - 4개 번호 일치\n");
		printf("5등 - 3개 번호 일치\n");

		printf("----------------------------------------------------------------------------------------------\n");
		printf("\n");


		if (cnt == 3) {
			printf("5등 입니다.\n");
		}
		else if (cnt == 4) {
			printf("4등 입니다.\n");
		}
		else if (cnt == 5) {
			printf("3등 입니다.\n");
		}
		else if (cnt == 5 && bounsNum) {
			printf("2등 입니다.\n");
		}
		else if (cnt == 6) {
			printf("1등 입니다.\n");
		}
		else {
			printf("당첨된 번호가 없습니다.\n");
		}
		printf("\n");
		printf("----------------------------------------------------------------------------------------------\n");

		printf("\n\n----------------------------------------------------------------------------------------------\n");
		printf("\n");

		printf("게임을 그만 하시겠습니까? 그만두기 : 1 , 계속하기 : 2     ");

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