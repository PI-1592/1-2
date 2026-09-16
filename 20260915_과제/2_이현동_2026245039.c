#include <stdio.h>
void PrintArray(int count) {									// 배열을 위쪽을 출력 함수 정의
	for (int i = 0; i < count / 2 + count % 2; i++) {		// 배열을 반으로 나눴을 때 위쪽을 출력하는 반복문
		int PrintNumber = i;
		for (int l = 0; l < i; l++) {						// 왼쪽 공백을 출력하는 반복문
			printf(" ");
		}
		for (int j = i; j < count; j++) {					// 각 줄에 맞는 숫자나 공백을 출력하는 반복문
			PrintNumber++;
			if (j == i || j == count - i - 1) {				// 처음, 마지막 / 처음+1, 마지막-1 ···에만 숫자 출력
				printf("%d", PrintNumber);
			}
			else {											// 나머지 상황에선 공백 출력
				printf(" ");
			}
		}
		printf("\n");
	}
}

void ReversePrintArray(int count) {							// 배열 아래쪽을 출력 함수 정의
	for (int i = count / 2 - 1; i >= 0 ; i--) {				// 배열을 반으로 나눴을 때 아래쪽을 출력하는 반복문
		int PrintNumber = i;

		for (int l = 0; l < i; l++) {						// 왼쪽 공백을 출력하는 반복문
			printf(" ");
		}

		for (int j = i; j < count; j++) {					// 각 줄에 맞는 숫자나 공백을 출력하는 반복문
			PrintNumber++;
			if (j == i || j == count - i - 1) {				// 처음, 마지막 / 처음+1, 마지막-1 ···에만 숫자 출력
				printf("%d", PrintNumber);
			}

			else {											// 나머지 상황에선 공백 출력
				printf(" ");
			}
		}
		if (i > 0) {										// 배열 마지막줄 줄 바꿈 생략
			printf("\n");
		}
	}
}

void RunPrintArray() {										// 배열 출력 함수 정의
	int count = 0;

	printf("도형의 크기를 입력하시오. ");
	scanf("%d", &count);

	PrintArray(count);										// 배열을 위쪽을 출력 함수 호출
	ReversePrintArray(count);								// 배열을 아래쪽을 출력 함수 호출
}

int main() {
	RunPrintArray();										// 배열 출력 함수 호출
	return 0;
}