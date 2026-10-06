#include <stdio.h>
#include "Homework1_이현동_2026245039_Diary.h"

int main() {
	char date[9];		// 파일명으로 설정 [날짜를 저장할 문자열 (YYYYMMDD 형식)]
	char filepath[100];		// 파일 경로

	// 사용자로부터 날짜 입력받기
	printf("날짜를 입력하세요 (YYYYMMDD 형식): ");
	scanf("%s", date);
	getchar();

	// 디렉토리의 해당 날짜 파일 경로 설정
	sprintf(filepath, "%s/%s.txt", "D:\\Diary", date);

	// 기존 다이어리 파일이 있으면 내용을 출력
	display_diary(filepath);

	// 다이어리 내용 추가
	append_to_diary(filepath);

	return 0;
}