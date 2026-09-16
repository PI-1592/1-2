#include <stdio.h>

void PrintHeartHead(int count, char symbol) {						// 반원을 출력 함수 정의
	for (int i = count / 3; i > 0; i--) {							// 반원의 줄 수
		for (int j = i - 1; j > 0; j--) {							// 왼쪽 공백을 출력하는 반복문
			printf(" ");
		}
		printf("*");
		for (int k = 0; k < count - 3 - 2 * (i - 1); k++) {			// 사용자가 입력한 기호로 반원을 채우는 반복문
			printf("%c", symbol);
		}
		printf("*");

		for (int l = 2 * i - 1; l > 0; l--) {						// 반원 사이의 공백을 출력하는 반복문
			printf(" ");
		}
		printf("*");												// 오른쪽 반원 출력
		for (int k = 0; k < count - 3 - 2 * (i - 1); k++) {
			printf("%c", symbol);
		}
		printf("*");
		printf("\n");
	}
}

void PrintHeartBody(int count, char symbol) {						// 역삼각형을 출력하는 함수 정의
	for (int i = count; i > 0; i--) {								// 역삼각형 줄 수
		for (int j = count - i; j > 0; j--) {						// 각 줄 앞 공백 출력
			printf(" ");
		}

		printf("*");

		for (int k = 2 * (i - 1) - 1; k > 0; k--) {					// 사용자가 입력한 기호로 역삼각형을 채우는 반복문
			printf("%c", symbol);
		}
		if (i > 1) {
			printf("*");
			printf("\n");
		}
	}
}

void RunDrawingHeart() {											// 하트 그리기 프로그램 함수 정의
	int count = 0;
	char symbol;
	
	printf("도형의 크기를 입력하시오. ");	
	scanf("%d", &count);
	printf("도형을 채울 기호를 입력하시오. ");
	scanf(" %c", &symbol);
	
	PrintHeartHead(count, symbol);									// 반원 출력 함수 호출
	PrintHeartBody(count, symbol);									// 역삼각형 출력 함수 호출
}

int main() {
	RunDrawingHeart();												// 하트 그리기 함수 호출
	return 0;
}