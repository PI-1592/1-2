#pragma once
#ifndef PERMUTATION_H
#define PERMUTATION_H

typedef struct {
	char* str;
	int len;
}String;

void swap(char* x, char* y);
void permute(char* str, int* l, int* r);

#endif // !PERMUTATION_H