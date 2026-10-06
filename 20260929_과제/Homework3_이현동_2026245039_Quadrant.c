#include <stdio.h>
#include <stdlib.h>
#include "Homework3_이현동_2026245039_Quadrant.h"

// 번호 -> 좌표 변환 함수
void Qua_To_Num(char* quadrant_num, int count, int half, int* row, int* col) {
	if (count == 0) {																// 글자가 없으면 종료
		return;
	}

	if (quadrant_num[0] == '1') {													// 1: 오른쪽 위
		*col += half;
	}
	else if (quadrant_num[0] == '3') {												// 3: 왼쪽 아래
		*row += half;
	}
	else if (quadrant_num[0] == '4') {												// 4: 오른쪽 아래
		*row += half;
		*col += half;
	}

	Qua_To_Num(quadrant_num + 1, count - 1, half / 2, row, col);					// 재귀함수 호출
}

// 좌표 -> 번호 변환 함수
void Num_To_Qua(char* quadrant_num, int count, int half, int row, int col) {
	if (count == 0) {																// 글자를 다 채웠으면 문자열 끝 표시
		quadrant_num[0] = '\0';
		return;
	}

	if (row < half && col >= half) {												// 오른쪽 위
		quadrant_num[0] = '1';
		col -= half;																// 사분면 안 좌표로 바꾸기
	}
	else if (row < half && col < half) {											// 왼쪽 위
		quadrant_num[0] = '2';
	}
	else if (row >= half && col < half) {											// 왼쪽 아래
		quadrant_num[0] = '3';
		row -= half;
	}
	else {																			// 오른쪽 아래
		quadrant_num[0] = '4';
		row -= half;
		col -= half;
	}

	Num_To_Qua(quadrant_num + 1, count - 1, half / 2, row, col);					// 재귀 함수 호출
}

void Run_Quadrant() {																// 프로그램 시작 함수
	int num_length = 0;
	int row = 0;
	int col = 0;
	int x = 0;
	int y = 0;
	int half = 1;
	char quadrant_num[51] = { 0 };
	char result[51] = { 0 };

	scanf("%d %50s", &num_length, quadrant_num); \
		scanf("%d %d", &x, &y);

	for (int i = 1; i < num_length; i++) {											// half = 2를 (num_length-1)번 곱한 값
		half *= 2;
	}

	Qua_To_Num(quadrant_num, num_length, half, &row, &col);							// 번호 -> 좌표

	col += x;																		// 오른쪽으로 이동하면 열이 커진다
	row -= y;																		// 위로 이동하면 행이 작아진다

	if (row < 0 || col < 0 || row >= half * 2 || col >= half * 2) {					// 사분면 밖으로 나가면 -1 출력
		printf("-1\n");
	}
	else {
		Num_To_Qua(result, num_length, half, row, col);								// 좌표 -> 번호
		printf("%s\n", result);
	}
}