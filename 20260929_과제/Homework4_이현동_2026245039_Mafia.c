#include <stdio.h>
#include <stdlib.h>
#include "Homework4_이현동_2026245039_Mafia.h"

void Set_Mafia(int* people, int people_num) {																// 초기 세팅
	int* turn_ptr = people;

	for (int i = 0; i < people_num; i++) {																	// 1~N까지 순서대로 저장
		*turn_ptr = i + 1;
		turn_ptr++;
	}

	printf("\n초기 상태\n");
	printf("남은 사람: ");

	for (int i = 0; i < people_num; i++) {																	// 초기 사람 출력
		printf("%d ", *people);
		people++;
	}

	printf("\n\n");
}

void Print_Array(int* people, int people_num, int* kill_count) {											// 남은 사람 출력 함수
	if(people_num > 0) {
		printf("남은 사람: ");
	}

	for (int i = 0; i < people_num; i++) {																	// 남은 사람 수 만큼 출력
		printf("%d ", *people);
		people++;
	}

	printf("\n");
	if (people_num > 0) {
		printf("\n");
	}
}

// 제거 함수
void Kill_People(int* people, int people_num, int kill_num, int* kill_count, int turn_kill[100], int start_idx) {
	int kill_idx = (start_idx + kill_num - 1) % people_num;													// 제거할 순번 계산

	turn_kill[*kill_count] = *(people + kill_idx);															// 제거될 번호 계산
	printf("%d번 제거\n", turn_kill[*kill_count]);

	for (int i = kill_idx; i < people_num - 1; i++) {														// 숫자 앞으로 당기기
		*(people + i) = *(people + i + 1);
	}

	Print_Array(people, people_num - 1, kill_count);														// 남은 사람 출력 함수 호출

	if (people_num > 1) {																					// 남은 사람이 있으면 재귀함수 호출
		(*kill_count)++;
		Kill_People(people, people_num - 1, kill_num, kill_count, turn_kill, kill_idx);
	}
}

void Run_Mafia() {																							// 프로그램 시작 함수
	int people_num = 0;																						// 남은 사람 수
	int kill_num = 0;																						// 번째 사람 제거
	int kill_count = 0;																						// 제거한 사람 수
	int turn_kill[100] = { 0 };																				// 제거된 사람 저장

	printf("사람의 수를 입력하세요: ");
	scanf("%d", &people_num);
	printf("제거할 순번을 입력하세요: ");
	scanf("%d", &kill_num);

	int* people = (int*)malloc(sizeof(int) * people_num);													// 동적 할당

	Set_Mafia(people, people_num);																			// 초기 세팅 함수 호출

	Kill_People(people, people_num, kill_num, &kill_count, turn_kill, 0);									// 제거 함수 호출

	printf("최종 제거 순서\n");

	for (int i = 0; i < people_num; i++){
		printf("%d ", turn_kill[i]);
	}

	free(people);
}