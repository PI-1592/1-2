#ifndef PALINDROME_H
#define PALINDROME_H

typedef struct {
	char* str;
	int length;
} StringInfo;

int getLength(StringInfo *info);
int isPalindrome(StringInfo* info, int left, int right);

#endif