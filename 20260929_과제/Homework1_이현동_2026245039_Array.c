#include <stdio.h>
#include "Homework1_이현동_2026245039_Array.h"

void Input_Array(int user_array[], int array_size) {											// 배열의 원소를 입력 받는 함수
	printf("배열의 원소 : ");

	for (int i = 0; i < array_size; i++) {														// 사용자 지정 배열 크기 만큼 입력
		scanf("%d", &user_array[i]);
	}
}

void Numerical_Sort(int user_array[], int array_size, int max_count, int count) {				// 숫자 정렬 함수
	int max_num = user_array[count];
	int idx = count;

	for (int i = count + 1; i < array_size && i <= count + max_count; i++) {					// 시작 지점부터 최대 회수까지 반복
		if (max_num < user_array[i]) {
			max_num = user_array[i];
			idx = i;
		}
	}

	for (int j = idx; j > count; j--) {															// 앞 공간 비우기
		user_array[j] = user_array[j - 1];
	}

	user_array[count] = max_num;

	if(max_count - (idx - count) > 0 && count + 1 < array_size){								// 회수가 남았을 경우 재귀 함수 호출
		Numerical_Sort(user_array, array_size, max_count - (idx - count), count + 1);
	}
}

void Print_Array(int user_array[], int array_size) {											// 배열 출력 함수
	for (int i = 0; i < array_size; i++) {														// 전체 배열 출력
		printf("%d ", user_array[i]);
	}
}

void Run_Sort() {																				// 프로그램 시작 함수
	int user_array[50] = { 0 };
	int array_size = 0;
	int max_count = 0;
	int count = 0;

	printf("배열의 크기 입력 : ");
	scanf("%d", &array_size);
	Input_Array(user_array, array_size);														// 배열 원소 입력 함수 호출
	
	printf("최대 교환 횟수 : ");
	scanf("%d", &max_count);
	Numerical_Sort(user_array, array_size, max_count, count);									// 배열 정렬 함수 호출

	Print_Array(user_array, array_size);														// 최종 배열 출력 함수 호출
}