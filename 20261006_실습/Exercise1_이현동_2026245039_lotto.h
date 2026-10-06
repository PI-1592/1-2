#ifndef LOTTO_H
#define LOTTO_H

#define LOTTO_NUMBERS 7
#define MAX_NUMBER 45
#define FILENAME "lotto_numbers.txt"

void generateLottoNumbers(int lottoNumbers[]);
void writeLottoNumbersToFile(int draws);
void readLottoNumbersFromFile(void);

#endif