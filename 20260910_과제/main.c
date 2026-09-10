#include <stdio.h>

void runCafeProgram();
void printMenu();
int choice_number(int num);

int main() {
	runCafeProgram;
	return 0;
}


void runCafeProgram() {
	int choice = 0;
	int tatalPrice = 0;

	printMenu();


}

void printMenu() {
	printf("=== 메뉴 ===/n");
	printf("1. 아메리카노 (3,000원)/n");
	printf("2. 카푸치노 (4,000원)/n");
	printf("3. 카라멜 마끼야또 (6,000원)/n");
	printf("4. 녹차라떼 (5,000원)/n");
	printf("5.딸기 스무디 (4,000원)/n");
	printf("6. 달고나 라떼 (2,000원)/n");
	printf("7. 종료/n");
	printf("==========/n");
}

int choice_number(int num) {
	
}