#include <stdio.h>

void CheckNumber(int Check_Number) {									// 회문 검증 함수 정의
	int Original_Number = Check_Number;
	int Reverse_Number = 0;
	while (Check_Number > 0) {											// 사용자가 입력한 수가 0보다 클 때만 반복
		Reverse_Number = 10 * Reverse_Number + Check_Number % 10;		// 10으로 나눈 나머지 값을 더해 1의 자리부터 역수 연산
		Check_Number = Check_Number / 10;
	}
	if (Original_Number == Reverse_Number) {							// 원래 수와 뒤집은 수가 일치하는지 판별
		printf("이 숫자는 회문입니다.");
	}
	else {
		printf("이 숫자는 회문이 아닙니다.");
	}
}

void CheckPalindrome() {												// 회문 검증 프로그램 함수 정의
	int Check_Number = 0;
	printf("자연수를 입력하세요: ");
	scanf("%d", &Check_Number);
	CheckNumber(Check_Number);											// 회문 검증 함수 호출
}

int main() {
	CheckPalindrome();													// 회문 검증 프로그램 함수 호출
	return 0;
}