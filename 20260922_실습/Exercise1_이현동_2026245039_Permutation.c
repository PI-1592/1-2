#include <stdio.h>
#include "Exercise1_ÀÌÇöµ¿_2026245039_Permutation.h"

void swap(char* x, char* y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}

void permute(char* str, int* l, int* r) {
	if (*l == *r) {
		printf("%s\n", str);
		return;
	}

	for (int i = *l; i <= *r; i++) {
		int duplicate = 0;

		for (int j = *l; j < i; j++) {
			if (*(str + j) == *(str + i)) {
				duplicate = 1;
				break;
			}
		}

		if (duplicate)
			continue;

		swap(str + *l, str + i);

		int next = *l + 1;
		permute(str, &next, r);

		swap(str + *l, str + i);
	}
}