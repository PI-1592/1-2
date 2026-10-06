#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Homework5_이현동_2026245039_Sudoku.h"

int Random_Num() {																		// 랜덤 숫자 생성 함수
	int random_num = rand() % 81;
	return random_num;
}

void Random_Sudoku(int random_num[10]) {												// 공백 위치 함수
	int count = 0;
	int check_num[10];

	while (count < 10) {																// 중복 없이 숫자 10개 뽑기
		check_num[count] = Random_Num();
		int is_duplicate = 0;

		for (int i = 0; i < count; i++) {												// 중복 숫자 검출
			if (check_num[count] == random_num[i]) {
				is_duplicate = 1;
				break;
			}
		}

		if (!is_duplicate) {															// 미중복 시 다음 숫자 뽑기
			random_num[count] = check_num[count];
			count++;
		}
	}
}

// 숫자 배열 복사 함수
void Clone_Matrix(int first_matrix[9][9], int second_matrix[9][9], int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			second_matrix[i][j] = first_matrix[i][j];
		}
	}
}

void Run_Blank(int second_matrix[9][9], int random_num[10], int row, int column) {		// 공백을 만드는 함수
	for (int i = 0; i < 10; i++) {														// 공백 10개 추가
		row = random_num[i] / 9;
		column = random_num[i] % 9;

		second_matrix[row][column] = 0;
	}
}

void Print_Sudoku(int second_matrix[9][9], int row, int column) {						// 스도쿠를 출력하는 함수
	printf("===== Sudoku =====\n\n");

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (second_matrix[i][j] == 0) {
				printf(". ");
			}
			else {
				printf("%d ", second_matrix[i][j]);
			}

			if (j == 2 || j == 5) {
				printf("| ");
			}
		}
		printf("\n");

		if (i == 2 || i == 5) {
			printf("---------------------\n");
		}
	}
	printf("\n");
}

// 스도쿠 정답 입력 및 채점 함수
void Play_Sudoku(int first_matrix[9][9], int second_matrix[9][9], int random_num[10], int row, int column, int count) {
	int user_num = 0;
	int i = 0;
	int j = 0;
	int is_duplicate = 0;

	system("cls");
	
	Print_Sudoku(second_matrix, row, column);

	for (i = 0; i < row; i++) {																	// .인 공간 찾기
		for (j = 0; j < column; j++) {
			if (second_matrix[i][j] == 0) {
				is_duplicate++;
				break;
			}
		}

		if (is_duplicate) {
			break;
		}
	}

	while (1) {																					// 정답이 입력될 때까지 반복
		printf("%d행 %d열의 숫자를 입력하세요 (1~9): ", i + 1, j + 1);
		scanf("%d", &user_num);

		if (user_num > 0 && user_num < 10 && first_matrix[i][j] == user_num) {					// 정답이 입력되면 다음으로
			second_matrix[i][j] = user_num;
			count++;
			break;
		}
		else {
			printf("틀렸습니다. 다시 입력하세요.\n");
		}
	}

	if (count < 10) {																			// 스도쿠가 끝날 때까지 재귀 함수 호출
		Play_Sudoku(first_matrix, second_matrix, random_num, row, column, count);
	}
	else if (count == 10) {
		system("cls");
		Print_Sudoku(second_matrix, row, column);
		printf("스도쿠를 모두 완성했습니다!");
	}
}

void Run_Sudoku() {
	srand(time(NULL));

	int count = 0;					// 재귀 함수 호출 수
	int row = 9;
	int column = 9;	
	int first_matrix[9][9] = { 
		{5,3,4,6,7,8,9,1,2},
		{6,7,2,1,9,5,3,4,8},
		{1,9,8,3,4,2,5,6,7},
		{8,5,9,7,6,1,4,2,3},
		{4,2,6,8,5,3,7,9,1},
		{7,1,3,9,2,4,8,5,6},
		{9,6,1,5,3,7,2,8,4},
		{2,8,7,4,1,9,6,3,5},
		{3,4,5,2,8,6,1,7,9}
	};
	int second_matrix[9][9] = { 0 };
	int random_num[10] = { 0 };

	Clone_Matrix(first_matrix, second_matrix, row, column);								// 스도쿠 기본 세팅
	Random_Sudoku(random_num);
	Run_Blank(second_matrix, random_num, row, column);
	Play_Sudoku(first_matrix, second_matrix, random_num, row, column, count);			// 스도쿠 시작 함수
}