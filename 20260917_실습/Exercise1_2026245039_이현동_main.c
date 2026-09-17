#include <stdio.h>
#include <stdlib.h>
#include "Exercise1_2026245039_이현동_Palindrome.h"

int main() {
	StringInfo info;

	info.str = (char*)malloc(100 * sizeof(char));

	printf("문자열 입력: ");
	scanf_s("%99s", info.str, 100);

	info.length = getLength(&info);

	printf("\n문자열 길이: %d\n", info.length);

	if (isPalindrome(&info, 0, info.length - 1)) {
		printf("회문입니다.\n");
	}
	
	else
	{
		printf("회문이 아닙니다.\n");
	}

	free(info.str);

	return 0;
}