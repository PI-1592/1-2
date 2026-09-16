#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MakeRandomNumber(int Map_Size) {																						// 난수 생성 함수 정의
	int Random_Number = rand() % Map_Size;
	return Random_Number;
}

void InitialMapSetup(char Map[100][100], int Map_Size, int Player_X, int Player_Y, int EndPoint_X, int EndPoint_Y) {		// 초기 맵 세팅 함수 정의
	for (int i = 0; i < Map_Size; i++) {																					// 2중 for문으로 모든 배열을 .으로 초기화
		for (int j = 0; j < Map_Size; j++) {
			Map[i][j] = '.';
		}
	}
	Map[Player_Y][Player_X] = 'P';																							// 플레이어 좌표에 P 입력
	Map[EndPoint_Y][EndPoint_X] = 'D';																						// 도착지 좌표에 D 입력
}

void PrintMap(char Map[100][100], int Map_Size) {																			// 맵 출력 함수 정의
	for (int i = 0; i < Map_Size; i++) {																					// 모든 열 출력을 위한 반복문
		for (int j = 0; j < Map_Size; j++) {																				// 2중 for문 모든 행 출력을 위한 반복문
			printf("%c", Map[i][j]);
			if (j != Map_Size - 1) {																						// 배열 출력 뒤 공백
				printf(" ");
			}
			else {
				printf("\n");
			}
		}
	}
}

void MovePlayer(char Map[100][100], int Map_Size, int *Player_X, int *Player_Y, int EndPoint_X, int EndPoint_Y) {			// 플레이어 이동 함수 정의
	char Enter_Key;
	printf("이동할 방법을 입력하세요\n");
	printf(" (w: 위, s: 아래, a: 왼쪽, d: 오른쪽): ");
	scanf(" %c", &Enter_Key);
	if (Enter_Key == 'w' && *Player_Y > 0) {																				// w를 입력 받았을 때 플레이어를 위로 이동
		Map[*Player_Y][*Player_X] = '.';
		(*Player_Y)--;
		Map[*Player_Y][*Player_X] = 'P';
	}
	else if (Enter_Key == 's' && *Player_Y < Map_Size - 1) {																// s를 입력 받았을 때 플레이어를 아래로 이동
		Map[*Player_Y][*Player_X] = '.';
		(*Player_Y)++;
		Map[*Player_Y][*Player_X] = 'P';
	}
	else if (Enter_Key == 'a' && *Player_X > 0) {																			// a를 입력 받았을 때 플레이어를 왼쪽으로 이동
		Map[*Player_Y][*Player_X] = '.';
		(*Player_X)--;
		Map[*Player_Y][*Player_X] = 'P';
	}
	else if (Enter_Key == 'd' && *Player_X < Map_Size - 1) {																// d를 입력 받았을 때 플레이어를 오른쪽으로 이동
		Map[*Player_Y][*Player_X] = '.';
		(*Player_X)++;
		Map[*Player_Y][*Player_X] = 'P';
	}
	else {
		return;																												// 플레이어가 배열 바깥으로 나가는 예외 처리
	}
}

void RunMap() {																												// 맵 프로그램을 시작하는 함수 정의
	int Map_Size = 0;
	int Reset = 0;
	while (1) {																												// 유효 범위 검사
		printf("맵 크기를 입력하세요: ");
		scanf("%d", &Map_Size);
		if (Map_Size > 0 && Map_Size < 100) {																				// 정상 범위 크기일 때 반복문 종료
			break;
		}
	}
	char Map[100][100];
	int Player_X = 0;
	int Player_Y = 0;
	int EndPoint_X = 0;
	int EndPoint_Y = 0;
	while (1) {																												// 플레이어와 도착지 좌표가 서로 다를 때까지 반복
		Player_X = MakeRandomNumber(Map_Size);																				// 난수 생성 함수 호출 및 사용자 X좌표 입력
		Player_Y = MakeRandomNumber(Map_Size);																				// 난수 생성 함수 호출 및 사용자 Y좌표 입력
		EndPoint_X = MakeRandomNumber(Map_Size);																			// 난수 생성 함수 호출 및 도착지 X좌표 입력
		EndPoint_Y = MakeRandomNumber(Map_Size);																			// 난수 생성 함수 호출 및 도착지 Y좌표 입력
		if (Player_X != EndPoint_X || Player_Y != EndPoint_Y) {
			break;
		}
	}
	InitialMapSetup(Map, Map_Size, Player_X, Player_Y, EndPoint_X, EndPoint_Y);												// 초기 맵 세팅 함수 호출
	PrintMap(Map, Map_Size);																								// 초기 세팅 된 맵 출력 함수 호출
	while (1) {																												// 플레이어와 도착지의 좌표가 같아질 때까지 반복
		MovePlayer(Map, Map_Size, &Player_X, &Player_Y, EndPoint_X, EndPoint_Y);											// 플레이어 이동 함수 호출
		if (Player_X == EndPoint_X && Player_Y == EndPoint_Y) {																// 도착지에 도착했을 때 최종 맵 출력 및 종료 문구 출력
			system("cls");																									// 프롬프트 창 초기화
			Map[Player_Y][Player_X] = 'D';
			PrintMap(Map, Map_Size);																						// 맵 출력 함수 호출
			printf("도착지에 도착했습니다!");
			break;
		}
		system("cls");																										// 프롬프트 창 초기화
		PrintMap(Map, Map_Size);																							// 맵 출력 함수 호출
	}
}

int main() {
	srand(time(NULL));																									// 시간을 이용해 랜덤 시드 생성
	RunMap();																												// 맵 프로그램을 시작하는 함수 호출
	return 0;
}