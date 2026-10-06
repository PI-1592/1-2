#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Homework2_이현동_2026245039_Baseball.h"

int Random_Num() {													// 랜덤 숫자 생성 함수
	int random_num = rand() % 9 + 1;

	return random_num;
}

void Input_Num(int user_answer[]) {								// 사용자 숫자 입력 함수 정의
	int count = 0;
	int input_num[3];
	int is_duplicate = 0;

	printf("\n서로 다른 숫자 3개를 입력하세요: ");
	
	while (count < 3) {												// 서로 다른 숫자 세 개 입력받기
		scanf("%d", &input_num[count]);
		
		for (int i = 0; i < count; i++) {							// 입력된 숫자 중복 검증
			if (user_answer[i] == input_num[count]) {
				is_duplicate = 1;
				break;
			}
		}

		user_answer[count] = input_num[count];
		count++;

		//if (!is_duplicate) {										// 미중복시 다음 숫자 확인
		//	user_answer[count] = input_num[count];
		//	count++;
		//}
		//else {
		//	Input_Num(user_answer);
		//	break;
		//}
	}

	if (is_duplicate) {												// 중복된 입력이 있었다면 재입력
		Input_Num(user_answer);										// 재귀 함수 호출
	}
}

void Drawing_Num(int com_answer[]) {								// 컴퓨터 숫자 생성 및 저장
	int count = 0;
	int random_num[3];

	while (count < 3) {												// 중복 없이 숫자 세 개 뽑기
		random_num[count] = Random_Num();
		int is_duplicate = 0;

		for (int i = 0; i < count; i++) {							// 중복 숫자 검출
			if (random_num[count] == com_answer[i]) {
				is_duplicate = 1;
				break;
			}
		}

		if (!is_duplicate) {										// 미중복 시 다음 숫자 뽑기
			com_answer[count] = random_num[count];
			count++;
		}
	}
}

void Abs(int com_answer[], int user_answer[], int* ptr) {			// 스트라이크, 볼 판정 함수 정의
	*ptr += 1;														// 시도 횟수 측정
	int strike = 0;
	int ball = 0;
	
	Input_Num(user_answer);											// 사용자 수 입력 함수 호출

	for (int i = 0; i < 3; i++) {									// 세 번 반복
		int same_num = 0;
		int same_pos = 0;

		for (int j = 0; j < 3; j++) {								// 같은 숫자, 같은 위치 측정
			if (user_answer[i] == com_answer[j]) {
				same_num++;
				
				if (i == j) {
					same_pos++;
				}

				break;
			}
		}
		
		if (same_num == 1 && same_pos == 1) {						// 스트라이크 수 측정
			strike++;
		}
		else if (same_num == 1) {									// 볼 수 측정
			ball++;
		}
	}

	printf("결과: %d Strike, %d Ball	\n", strike, ball);

	if (strike != 3) {												// 3 스트라이크가 아니면 다시 반복
		Abs(com_answer, user_answer, ptr);							// 재귀 함수 호출
	}
}

void Run_BaseBall() {												// 프로그램 시작 함수 정의
	srand(time(NULL));
	int com_answer[3] = { 0 };
	int user_answer[3] = { 0 };
	int play_count = 0;

	Drawing_Num(com_answer);										// 숫자 뽑기 함수 호출

	printf("==== 숫자 야구 게임 ====\n");

	Abs(com_answer, user_answer, &play_count);						// 스트라이크, 볼 판정 함수 호출

	printf("\n정답입니다!\n");
	printf("총 시도 횟수: %d\n", play_count);
}