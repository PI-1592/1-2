#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "2_이현동_2026245039_Lotto.h"

int Random_Number() {
	int random_num = rand() % 45 + 1;
	return random_num;
}

void Drawing_Number(int *ptr) {
	int count = 0;
	int random_num = 0;
	int* first_ptr = ptr;

	while (count < 7) {
		random_num = Random_Number();
		int* check_ptr = first_ptr;
		int is_duplicate = 0;
		
		for (int i = 0; i < count; i++) {
			if (random_num == *check_ptr) {
				is_duplicate = 1;
				break;
			}

			else if (random_num != *check_ptr) {
				check_ptr++;
			}
		}

		if (!is_duplicate) {
			*ptr = random_num;
			ptr++;
			count++;
		}
	}
}

void User_Number_Set(int* ptr) {
	int* first_ptr = ptr;
	int count = 0;
	
	while (count < 6) {
		while (1) {
			int* check_ptr = first_ptr;
			int user_num = 0;
			int is_duplicate = 0;

			printf("로또 번호를 입력하세요 (1 ~ 45): ");
			scanf("%d", &user_num);

			if (user_num < 1 || user_num > 45) {
				printf("1 ~ 45 사이의 숫자를 입력해주세요.\n");
			}
			else {
				for (int i = 0; i < count; i++) {
					if (user_num == *check_ptr) {
						is_duplicate = 1;
						printf("중복된 숫자는 입력할 수 없습니다. 다른 숫자를 입력하세요.\n");
						break;
					}
					else {
						check_ptr++;
					}
				}

				if (!is_duplicate) {
					*ptr = user_num;
					ptr++;
					count++;
					break;
				}
			}
		}
	}
}

void Check_Lotto(int* answer_ptr, int* user_ptr) {
	int count = 0;
	int answer_count = 0;

	while (count < 6) {
		for (int i = 0; i < 6; i++) {
			if (*(user_ptr + count) == *(answer_ptr + i)) {
				answer_count++;
			}
		}

		count++;
	}

	for (int j = 0; j < 6; j++) {
		if (answer_count == 5) {
			if (*(user_ptr + j) == *(answer_ptr + 6)) {
				answer_count += 2;
				break;
			}
		}
	}

	printf("로또 번호: ");

	for (int j = 0; j < 7; j++) {
		if (j == 6) {
			printf(" 보너스 번호: %d\n", *(answer_ptr + j));
		}
		else {
			printf("%d ", *(answer_ptr + j));
		}
	}

	switch (answer_count) {
	case 0:
	case 1:
	case 2: printf("꽝입니다! (%d개 번호 일치)\n", answer_count); break;
	case 3:	printf("5등입니다! (%d개 번호 일치)\n", answer_count); break;
	case 4:	printf("4등입니다! (%d개 번호 일치)\n", answer_count); break;
	case 5:	printf("3등입니다! (%d개 번호 일치)\n", answer_count); break;
	case 6:	printf("1등입니다! (%d개 번호 일치)\n", answer_count); break;
	case 7:	printf("2등입니다! (%d개 번호 + bonus 일치)\n", answer_count); break;
	}
}

void Run_Virtual_Lotto() {
	srand(time(NULL));
	int Answer_Lotto[7] = { 0 };
	int User_Lotto[6] = { 0 };

	Drawing_Number(Answer_Lotto);
	User_Number_Set(User_Lotto);
	Check_Lotto(Answer_Lotto, User_Lotto);
}