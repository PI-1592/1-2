#include <string.h>
#include "Exercise1_2026245039_ÀÌÇöµ¿_Palindrome.h"

int getLength(StringInfo* info) {
	return strlen(info->str);
}

int isPalindrome(StringInfo* info, int left, int right) {
	if (left >= right) {
		return 1;
	}

	if (info->str[left] != info->str[right]) {
		return 0;
	}

	return isPalindrome(info, left + 1, right - 1);
}