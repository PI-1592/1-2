#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RandomNumber() {														// 난수 생성 함수 정의
	int Random_Number = rand() % 100 + 1;
	return Random_Number;
}

int EnterNumber() {															// 사용자 정수 입력 함수 정의
	int EnterNumber = 0;
	while (1) {																// 숫자가 유효 범주면 반복 중지
		printf("숫자를 맞춰보세요 (1-100): ");
		scanf("%d", &EnterNumber);
		if (EnterNumber > 0 && EnterNumber <= 100) {
			return EnterNumber;
		}
		else {
			printf("1과 100 사이의 숫자를 입력하세요.\n");
		}
	}
}

int JudgmentNumber(int Random_Number, int Enter_Number, int *Count) {		// 난수와 사용자 입력 정수 비교 밎 시도 회수 측정 함수 정의
	(*Count)++;
	if (Enter_Number == Random_Number) {									// 일치하면 1 반환 / 불일치하면 대소 출력 및 0 반환
		return 1;
	}
	else if (Enter_Number < Random_Number) {
		printf("%d보다 큰 숫자입니다.\n", Enter_Number);
		return 0;
	}
	else {
		printf("%d보다 작은 숫자입니다.\n", Enter_Number);
		return 0;
	}
}

void RunQuiz() {															// 퀴즈 프로그램 실행 함수 정의
	int Random_Number = 0;
	int Enter_Number = 0;
	int Count = 0;
	
	printf("숫자 추측 게임을 시작합니다! (1~100 사이)\n");

	Random_Number = RandomNumber();											// 난수 생성 함수 호출 및 변수에 입력
	while (1) {																// 1이 반환 될 경우 반복 중지
		Enter_Number = EnterNumber();										// 사용자 정수 입력 함수 호출 및 변수에 입력

		if (JudgmentNumber(Random_Number, Enter_Number, &Count)) {			// 난수와 사용자 입력 정수 비교 밎 시도 회수 측정 함수 호출 및 1이 반환 될 때  반복 종료
			break;
		}
	}

	printf("정답입니다! %d번 만에 맞췄습니다!", Count);
}

int main() {
	srand(time(NULL));														// 시간을 이용해 랜덤 시드 생성
	RunQuiz();																// 퀴즈 프로그램 실행 함수 호출
	return 0;
}