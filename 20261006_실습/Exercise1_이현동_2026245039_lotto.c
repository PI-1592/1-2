#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Exercise1_이현동_2026245039_lotto.h"

void generateLottoNumbers(int lottoNumbers[]) {
    int isDuplicate;

    for (int i = 0; i < LOTTO_NUMBERS; i++) {
        do {
            isDuplicate = 0;
            lottoNumbers[i] = rand() % MAX_NUMBER + 1;

            for (int j = 0; j < i; j++) {
                if (lottoNumbers[i] == lottoNumbers[j]) {
                    isDuplicate = 1;
                    break;
                }
            }
        } while (isDuplicate);
    }
}

void writeLottoNumbersToFile(int draws) {
    FILE* fp = fopen(FILENAME, "w");

    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return;
    }

    srand((unsigned int)time(NULL));

    int lottoNumbers[LOTTO_NUMBERS];

    for (int draw = 1; draw <= draws; draw++) {
        generateLottoNumbers(lottoNumbers);

        fprintf(fp, "%d 회차 : ", draw);

        for (int i = 0; i < LOTTO_NUMBERS - 1; i++) {
            fprintf(fp, "%d ", lottoNumbers[i]);
        }

        fprintf(fp, "+ 보너스 번호: %d\n", lottoNumbers[LOTTO_NUMBERS - 1]);
    }

    fclose(fp);

    printf("파일에 로또 번호 기록 완료 (%s)\n", FILENAME);
}

void readLottoNumbersFromFile(void) {
    FILE* fp = fopen(FILENAME, "r");

    if (fp == NULL) {
        printf("파일 읽기 실패\n");
        return;
    }

    printf("파일에서 로또 번호 읽기:\n");

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        fputs(buffer, stdout);
    }

    fclose(fp);
}
