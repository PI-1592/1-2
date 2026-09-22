#include <stdio.h>
#include "5_이현동_2026245039_Custom_Strcmp.h"

void Input_Str(char* str1, char* str2, int size) {
	char* check_ptr1 = str1;
	char* check_ptr2 = str2;

	printf("문자열 1: ");
	fgets(str1, size, stdin);
	while (*check_ptr1 != '\0') {
		if (*check_ptr1 == '\n') {
			*check_ptr1 = '\0';
			break;
		}
		check_ptr1++;
	}

	printf("문자열 2: ");
	fgets(str2, size, stdin);
	while (*check_ptr2 != '\0') {
		if (*check_ptr2 == '\n') {
			*check_ptr2 = '\0';
			break;
		}
		check_ptr2++;
	}
}

int Custom_Strcmp(const char* str1, const char* str2) {
	while (1) {
		if (*str1 == '\0' || *str2 == '\0' || *str1 != *str2) {
			break;
		}
		str1++;
		str2++;
	}

	return *str1 - *str2;
}

void Print_Result(const char* str1, const char* str2) {
	int is_duplicate = 0;

	while (1) {
		if (*str1 != *str2) {
			printf("첫 번째로 다른 문자: %c vs %c\n", *str1, *str2);
			is_duplicate++;
			break;
		}
		else if (*str1 == '\0' && *str2 == '\0') {
			break;
		}

		str1++;
		str2++;
	}

	if (!is_duplicate) {
		printf("첫 번째로 다른 문자가 없습니다.\n");
	}

	if (*str1 > *str2) {
		printf("-> 문자열 1이 문자열 2보다 큽니다.\n");
	}
	else if (*str1 < *str2) {
		printf("-> 문자열 1이 문자열 2보다 작습니다.\n");
	}
	else {
		printf("-> 두 문자열은 같습니다.\n");
	}
}

void Run_Custom_Strcmp() {
	int check_result = 0;
	char first_str[50];
	char second_str[50];
	int size = sizeof(first_str);

	printf("==== 문자열 비교 ====\n\n");

	Input_Str(first_str, second_str, size);

	printf("\n비교 결과: %d\n", Custom_Strcmp(first_str, second_str));

	Print_Result(first_str, second_str);
}