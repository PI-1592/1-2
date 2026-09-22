#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Exercise1_이현동_2026245039_Permutation.h"

int main() {
	String inputStr;
	char temp[100];

	printf("문자열을 입력하세요: ");
	scanf("%99s", temp);

	inputStr.len = strlen(temp);

	inputStr.str = (char*)malloc((inputStr.len + 1) * sizeof(char));

	strcpy(inputStr.str, temp);

	int start = 0;
	int end = inputStr.len - 1;

	printf("문자열의 순열:\n");

	permute(inputStr.str, &start, &end);

	free(inputStr.str);

	return 0;
}