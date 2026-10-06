#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Homework2_이현동_2026245039_System.h"

// 파일에서 데이터 읽기
void readStudentsFromFile(Student* students[], int* studentCount) {
	char tempName[MAX_NAME_LENGTH] = { 0 };
	char tempID[10] = { 0 };
	FILE* ptr = fopen("students.txt", "r");

	// 이름을 읽었을 때 반복
	while (fscanf(ptr, "%s", tempName) == 1) {
		students[*studentCount] = (Student*)malloc(sizeof(Student));        // Student 동적 할당
		students[*studentCount]->name = (char*)malloc(strlen(tempName) + 1);        // name 동적 할당
		
		strcpy(students[*studentCount]->name, tempName);        // tempName에서 name으로 복사

		// 학번을 읽은 뒤 복사
		fscanf(ptr, "%s", tempID);
		strcpy(students[*studentCount]->studentID, tempID);

		// numCourses에 과목 수 입력
		fscanf(ptr, "%d", &students[*studentCount]->numCourses);

		// 과목 수 만큼 과목 정보 읽기
		for (int i = 0; i < students[*studentCount]->numCourses; i++) {
			fscanf(ptr, "%s", tempName);
			strcpy(students[*studentCount]->courses[i].courseName, tempName);     // tempName에서 courseName으로 복사
			fscanf(ptr, "%d", &students[*studentCount]->courses[i].credit);        // credit에 수강 학점 입력
			fscanf(ptr, "%f", &students[*studentCount]->courses[i].score);     // score에 과목 학점 입력
		}

		(*studentCount)++;
	}

	fclose(ptr);
}

// 전체 학생 출력
void printStudents(Student* students[], int studentCount) {
	for (int count = 0; count < studentCount; count++) {		// 0 ~ studentCount-1까지 반복
		// 학생 정보 출력
		printf("이름 : %s, 학번 : %s, 과목 수 : %d, GPA : %.2f\n", students[count]->name, students[count]->studentID, students[count]->numCourses, calculateGPA(students[count]));

		// 과목 수 만큼 과목 정보 출력
		for (int i = 0; i < students[count]->numCourses; i++) {
			printf("과목명 : %s, 수강 학점 : %d, 학점 : %.2f\n", students[count]->courses[i].courseName, students[count]->courses[i].credit, students[count]->courses[i].score);
		}
	}
}

// GPA 기준 버블 정렬
void sortStudentsByGPA(Student* students[], int studentCount) {
	for (int i = 0; i < studentCount - 1; i++) {
		for (int j = 0; j < studentCount - 1 - i; j++) {
			if (calculateGPA(students[j]) < calculateGPA(students[j + 1])) {
				Student* temp = students[j];		// temp에 j값 저장
				students[j] = students[j + 1];		// j에 j+1 값 대입
				students[j + 1] = temp;		// j+1에 temp에 저장된 값 대입
			}
		}
	}
	printf("GPA 기준 내림차순으로 정렬되었습니다.\n");
}

// GPA 계산 및 반환
float calculateGPA(Student* student) {
	float gpa_count = 0;
	float GPA = 0;

	// GPA = (수강 학점 x 학점)의 합 / 수강 학점의 합 (학점 가중 평균)
	for (int i = 0; i < student->numCourses; i++) {
		GPA = GPA + student->courses[i].credit * student->courses[i].score;
		gpa_count += student->courses[i].credit;
	}
	GPA /= gpa_count;

	return GPA;
}

// 이름으로 학생 찾기
void searchStudentByName(Student* students[], int studentCount, const char* name) {
	for (int count = 0; count < studentCount; count++) {		// 0 ~ studentCount-1까지 반복
		if (!strcmp(students[count]->name, name)) {		// 이름이 같으면 정보 출력
			printf("이름 : %s, 학번 : %s, GPA : %.2f\n", students[count]->name, students[count]->studentID, calculateGPA(students[count]));		
			
			break;
		}
	}
}

void searchStudentByID(Student* students[], int studentCount, const char* studentID) {
	for (int count = 0; count < studentCount; count++) {		// 0 ~ studentCount-1까지 반복
		if (!strcmp(students[count]->studentID, studentID)) {		// 학번이 같으면 정보 출력
			printf("이름 : %s, 학번 : %s, GPA : %.2f\n", students[count]->name, students[count]->studentID, calculateGPA(students[count]));

			break;
		}
	}
}

// 학생 추가
void addStudent(Student* students[], int* studentCount) {
	char tempName[MAX_NAME_LENGTH] = { 0 };
	char tempID[10] = { 0 };

	students[*studentCount] = (Student*)malloc(sizeof(Student));        // Student 동적 할당
	
	// 이름을 입력 받아 동적 할당
	printf("학생 이름 : ");
	scanf("%49s", tempName);
	students[*studentCount]->name = (char*)malloc(strlen(tempName) + 1);

	strcpy(students[*studentCount]->name, tempName);        // tempName에서 name으로 복사

	// 학번을 입력 받아 복사
	printf("학생 학번 : ");
	scanf("%9s", tempID);
	strcpy(students[*studentCount]->studentID, tempID);

	// numCourses에 과목 수 입력
	printf("수강 과목 수 : ");
	scanf("%d", &students[*studentCount]->numCourses);

	// 과목 수 만큼 과목 정보 입력 받기
	for (int i = 0; i < students[*studentCount]->numCourses; i++) {
		printf("과목명 : ");
		scanf("%49s", tempName);
		strcpy(students[*studentCount]->courses[i].courseName, tempName);     // tempName에서 courseName으로 복사
		printf("수강 학점 : ");
		scanf("%d", &students[*studentCount]->courses[i].credit);        // credit에 수강 학점 입력
		printf("학점 : ");
		scanf("%f", &students[*studentCount]->courses[i].score);     // score에 과목 학점 입력
	}

	(*studentCount)++;

	saveAddedStudentsToFile(students, *studentCount, "students_add.txt");
}

// GPA 기준 내림차순 정렬결과 저장
void saveSortedStudentsToFile(Student* students[], int studentCount, const char* filename) {
	FILE* ptr = fopen(filename, "w");
	
	for (int count = 0; count < studentCount; count++) {
		// 학생 정보 저장
		fprintf(ptr, "%s %s %d", students[count]->name, students[count]->studentID, students[count]->numCourses);
	
		// 과목 수 만큼 과목 정보 저장
		for (int i = 0; i < students[count]->numCourses; i++) {
			fprintf(ptr, " %s %d %.2f", students[count]->courses[i].courseName, students[count]->courses[i].credit, students[count]->courses[i].score);
		}
		fprintf(ptr, "\n");
	}
	printf("GPA 기준으로 정렬된 학생 정보가 'students_sorted.txt' 파일에 저장되었습니다.\n");

	fclose(ptr);
}

// 추가된 학생 포함 정보 저장
void saveAddedStudentsToFile(Student* students[], int studentCount, const char* filename) {
	FILE* ptr = fopen(filename, "w");

	for (int count = 0; count < studentCount; count++) {
		// 학생 정보 저장
		fprintf(ptr, "%s %s %d", students[count]->name, students[count]->studentID, students[count]->numCourses);

		// 과목 수 만큼 과목 저장
		for (int i = 0; i < students[count]->numCourses; i++) {
			fprintf(ptr, " %s %d %.2f", students[count]->courses[i].courseName, students[count]->courses[i].credit, students[count]->courses[i].score);
		}
		fprintf(ptr, "\n");
	}

	printf("추가된 학생 정보가 'students_add.txt' 파일에 저장되었습니다.\n");

	fclose(ptr);
}