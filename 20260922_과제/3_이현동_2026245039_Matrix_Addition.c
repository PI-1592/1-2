#include <stdio.h>
#include "3_이현동_2026245039_Matrix_Addition.h"

void Input_Matrix_Size(int* row_ptr, int* column_ptr) {
	printf("행렬의 행과 열의 크기를 입력하세요 (n m): ");
	scanf("%d %d", row_ptr, column_ptr);
}
void Input_Matrix(int matrix[10][10], int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
}

void Matrix_Addition(int first_matrix[10][10], int second_matrix[10][10], int final_matrix[10][10], int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			final_matrix[i][j] = first_matrix[i][j] + second_matrix[i][j];
		}
	}
}

void Print_Matrix(int final_matrix[10][10], int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			printf("%d ", final_matrix[i][j]);
		}
		printf("\n");
	}
}

void Run_Matrix_Addition() {
	int row = 0;
	int column = 0;
	int first_matrix[10][10] = { 0 };
	int second_matrix[10][10] = { 0 };
	int final_matrix[10][10] = { 0 };
	
	Input_Matrix_Size(&row, &column);

	printf("1 번째 행렬을 입력하세요:\n");
	Input_Matrix(first_matrix, row, column);

	printf("2 번째 행렬을 입력하세요:\n");
	Input_Matrix(second_matrix, row, column);

	printf("두 행렬의 합은 다음과 같습니다:\n");
	Matrix_Addition(first_matrix, second_matrix, final_matrix, row, column);
	Print_Matrix(final_matrix, row, column);
}