#include <stdio.h>
#include <stdlib.h>
#include "Homework2_이현동_2026245039_System.h"

int main() {
	Student* students[15] = { 0 };
	int studentCount = 0;
	int choice;
	char input_name[MAX_NAME_LENGTH];
	char input_id[MAX_COURSES];
	
	readStudentsFromFile(students, &studentCount);		// 파일 데이터 불러오기

	while (1) {     // 수행할 기능 번호 입력 받기
		printf("\n===== 학생 관리 시스템 =====\n");
		printf("1. 전체 학생 정보 출력\n");
		printf("2. 이름으로 학생 검색\n");
		printf("3. 학번으로 학생 검색\n");
		printf("4. GPA 기준 내림차순 정렬\n");
		printf("5. GPA 기준 내림차순 정렬결과 저장\n");
		printf("6. 학생 정보 추가\n");
		printf("0. 종료\n");
		printf("선택: ");
		scanf("%d", &choice);

		if (choice == 0) {      // 0이면 종료
			break;
		}
		
		switch (choice) {       // 각 번호에 맞는 함수 호출하기
		case 1:
			printStudents(students, studentCount);
			break;
		case 2:
			printf("검색할 이름을 입력하세요 : ");
			scanf("%49s", input_name);

			searchStudentByName(students, studentCount, input_name);
			break;
		case 3:
			printf("검색할 학번을 입력하세요 : ");
			scanf("%9s", input_id);

			searchStudentByID(students, studentCount, input_id);
			break;
		case 4:
			sortStudentsByGPA(students, studentCount);
			break;
		case 5:
			saveSortedStudentsToFile(students, studentCount, "students_sorted.txt");
			break;
		case 6:
			addStudent(students, &studentCount);
			break;
		default:
			printf("잘못된 입력입니다. 다시 선택하세요.\n");
			break;
		}
	}

	// 종료 시 할당 메모리 해제
	for (int i = 0; i < studentCount; i++) {
		if (students[i] != NULL) {
			free(students[i]->name); // 1. 내부 이름 해제
			free(students[i]);       // 2. 구조체 해제
		}
	}

	return 0;
}