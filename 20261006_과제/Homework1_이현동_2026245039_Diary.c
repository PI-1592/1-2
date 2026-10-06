#include <stdio.h>
#include <string.h>

void display_diary(const char* filepath) {
	char diary[500] = { 0 };		// 다이어리 내용 출력용 배열
	FILE* ptr = fopen(filepath, "r");		// 파일 읽기

	if (ptr == 0) {		// 파일이 없을 경우 출력
		printf("해당 날짜의 일기가 존재하지 않습니다. 새로 작성하세요.\n");
		return;
	}
	
	// 파일이 있을 경우 내용을 출력
	printf("-- 기존 다이어리 내용 --\n");

	// 모든 줄을 출력할 때까지 반복
	while (fgets(diary, sizeof(diary), ptr) != NULL) {
		printf("%s", diary);
	}
	printf("\n");

	fclose(ptr);		// 파일 닫기
}

void append_to_diary(const char* filepath) {
	char diary[500] = { 0 };		// 다이어리 내용 입력용 배열
	FILE* ptr = fopen(filepath, "a");		// 파일 이어쓰기

	printf("다이어리에 작성할 내용을 입력하세요 (입력을 종료하려면 빈 줄을 입력하세요):\n");

	// 빈 줄이 입력될 때까지 다이어리에 내용 추가
	while (fgets(diary, sizeof(diary), stdin) != NULL) {
		if (diary[0] == '\n') {		// 빈 줄이면 종료
			break;
		}

		fputs(diary, ptr);		// 다이어리에 내용 입력하기
	}

	fclose(ptr);		// 파일 닫기

	printf("다이어리 저장 !!!!\n");
}