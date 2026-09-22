#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "1_이현동_2026245039_GetStrStatus.h"

void Length_Str(char *start_ptr) {					// 길이 측정 함수 정의
	char *last_p_str = start_ptr;

	while (*last_p_str != '\0') {					// '\0'이 아닐 때 반복하며 문자열 끝까지 이동
		if (*last_p_str == '\n') {					// fgets의 문자열 끝 '\n'을 만나면 '\0'으로 바꾼다.
			*last_p_str = '\0';
			break;
		}
		last_p_str++;
	}
	
	int length = last_p_str - start_ptr;			// 끝에서 시작을 빼 길이 측정
	printf("문자열 길이: %d\n", length);
}

void Alpha_Str(char* ptr) {							// 알파벳 개수 측정 함수 정의
	int alpha_num = 0;

	while (*ptr != '\0') {							// 문자열 끝까지 반복
		if ('A' <= *ptr && *ptr <= 'Z') {			// 대문자 알파벳일 때 카운트
			alpha_num++;
			ptr++;
		}
		else if ('a' <= *ptr && *ptr <= 'z') {		// 소문자 알파벳일 때 카운트
			alpha_num++;
			ptr++;
		}
		else {										// 아니면 다음 문자로 이동
			ptr++;
		}
	}

	if (alpha_num > 0) {							// 알파벳 개수에 맞는 출력
		printf("알파벳 개수: %d\n", alpha_num);
	}
	else
	{
		printf("알파벳 개수: 없음\n");
	}
}

void Number_Str(char* ptr) {						// 숫자 측정 함수 정의
	int Number_num = 0;

	while (*ptr != '\0') {							// 문자열 끝까지 반복
		if ('0' <= *ptr && *ptr <= '9') {			// 숫자면 카운트 아니면 다음으로 이동
			Number_num++;
			ptr++;
		}
		else {
			ptr++;
		}
	}

	printf("숫자 개수: %d\n", Number_num);
}

void Null_Str(char* ptr) {							// 공백 측정 함수 정의
	int Null_num = 0;

	while (*ptr != '\0') {							// 문자열 끝까지 반복
		if (' ' == *ptr) {							// 공백일 때 카운트 아니면 다음 문자열로 이동
			Null_num++;
			ptr++;
		}
		else {
			ptr++;
		}
	}

	printf("공백 개수: %d\n", Null_num);
}

void Mode_Alpha(char* ptr) {						// 최빈 알파벳 측정 함수 정의
	int alpha_count = 0;
	int Alpha[26] = { 0 };
	int judge_mode = 0;
	int Max_index = 27;

	while (*ptr != '\0') {							// 문자열 끝까지 반복
		if ('A' <= *ptr && *ptr <= 'Z') {			// 대문자 알파벳이면 같은 번째 인덱스에 카운트
			alpha_count = *ptr;
			alpha_count -= 'A';
			Alpha[alpha_count] += 1;
			ptr++;
		}
		else if ('a' <= *ptr && *ptr <= 'z') {		// 소문자 알파벳이면 같은 번째 인덱스에 카운트
			alpha_count = *ptr;
			alpha_count -= 'a';
			Alpha[alpha_count] += 1;
			ptr++;
		}
		else {										// 아니면 다음으로 이동
			ptr++;
		}
	}
	
	for (int i = 0; i < 26; i++) {					// 최다 빈도 계산
		if (judge_mode < Alpha[i]) {
			judge_mode = Alpha[i];
			Max_index = i;
		}
	}

	if (Max_index == 27) {							// 알파벳이 있으면 출력 아니면 '없음' 출력
		printf("가장 많이 등장한 알파벳: 없음\n\n");
	}
	else {
		Max_index += 'a';
		printf("가장 많이 등장한 알파벳: %c\n\n", Max_index);
	}
}

void Reverse_Str(char* ptr) {
	char *first_ptr = ptr;

	while (*ptr != '\0') {
		ptr++;
	}

	ptr--;
	printf("역순 문자열: ");

	while (first_ptr <= ptr) {
		printf("%c", *ptr);
		ptr--;
	}
}

void Run_Get_Str_Status() {
	char User_Str[100] = { 0 };

	printf("문자열 입력: ");
	fgets(User_Str, sizeof(User_Str), stdin);
	
	printf("\n==== 문자열 분석 ====\n");

	Length_Str(User_Str);
	Alpha_Str(User_Str);
	Number_Str(User_Str);
	Null_Str(User_Str);
	Mode_Alpha(User_Str);
	Reverse_Str(User_Str);
}