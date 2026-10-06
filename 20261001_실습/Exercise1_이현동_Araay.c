#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Exercise1_이현동_Array.h"

void dup_removal(void) {
    int n;

    printf("배열의 크기를 입력하세요: ");
    scanf_s("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));

    int* unique = (int*)malloc(n * sizeof(int));

    int unique_count = 0;

    if (arr == NULL || unique == NULL) {
        printf("메모리 할당에 실패했습니다.\n");

        free(arr);
        free(unique);

        return;
    }

    printf("배열의 요소를 입력하세요: ");

    for (int i = 0; i < n; i++) {
        scanf_s("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        int is_dup = 0;

        for (int j = 0; j < unique_count; j++) {
            if (arr[i] == unique[j]) {
                is_dup = 1;
                break;
            }
        }

        if (!is_dup) {
            unique[unique_count] = arr[i];
            unique_count++;
        }
    }

    printf("중복을 제거한 배열: ");

    for (int i = 0; i < unique_count; i++) {
        printf("%d ", unique[i]);
    }

    printf("\n");

    free(arr);
    free(unique);
}