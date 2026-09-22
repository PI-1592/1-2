#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "4_이현동_2026245039_StudentStatus.h"

void Input_Info(int student_num, Student_Info * students) {
	for (int i = 0; i < student_num; i++) {
		printf("\n[%d번째 학생]\n", i + 1);
		printf("이름: ");
		scanf("%s", students[i].Name);
		printf("학번: ");
		scanf("%d", &students[i].Id);
		printf("국어: ");
		scanf("%d", &students[i].Kor);
		printf("영어: ");
		scanf("%d", &students[i].Eng);
		printf("수학: ");
		scanf("%d", &students[i].Math);
	}
}

void Total_score(int student_num, Student_Info* students) {
	for (int i = 0; i < student_num; i++) {
		students[i].Sum = students[i].Kor + students[i].Eng + students[i].Math;
	}
}

void Avr_score(int student_num, Student_Info* students) {
	for (int i = 0; i < student_num; i++) {
		students[i].Avr = students[i].Sum;
		students[i].Avr /= 3;
	}
}

void Print_Info(Student_Info* students, int user_num) {
	printf("\n이름: %s\n", students[user_num].Name);
	printf("학번: %d\n", students[user_num].Id);
	printf("총점: %d\n", students[user_num].Sum);
	printf("평균: %.2f\n\n", students[user_num].Avr);
}

void Search_Student(int student_num, Student_Info* students) {
	int search_id = 0;
	int user_num = student_num + 1;

	printf("==== 학생 검색 ====\n");
	printf("검색할 학번: ");
	scanf("%d", &search_id);

	for (int i = 0; i < student_num; i++) {
		if (search_id == students[i].Id) {
			user_num = i;
		}
	}
	
	if (user_num != student_num + 1) {
		Print_Info(students, user_num);
	}
	else {
		printf("해당 학번을 찾을 수 없습니다.");
	}
	
}

void Print_All_Student(int student_num, Student_Info* students) {
	printf("\n\n==== 전체 학생 정보 ====\n\n");

	for (int i = 0; i < student_num; i++) {
		printf("%s ", students[i].Name);
		printf("%d\n", students[i].Id);
		printf("총점: %d\n", students[i].Sum);
		printf("평균: %.2f\n\n", students[i].Avr);
	}
}

void Best_Avr_Student(int student_num, Student_Info* students) {
	double temp = 0;
	int user_num = 0;

	printf("==== 최고 평균 학생 ====\n");

	for (int i = 0; i < student_num; i++) {
		if (temp < students[i].Avr) {
			temp = students[i].Avr;
			user_num = i;
		}
	}

	printf("%s ", students[user_num].Name);
	printf("(%.2f)\n\n", students[user_num].Avr);
}

void Ranking_Avr(int student_num, Student_Info* students) {
	Student_Info temp;

	for (int i = 0; i < student_num - 1; i++) {
		for (int j = 0; j < student_num - i - 1; j++) {
			if (students[j].Avr < students[j + 1].Avr) {
				temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	}

	printf("==== 평균 점수 순위 ====\n");

	for (int k = 0; k < student_num; k++) {
		printf("%d. %s %.2f\n", k + 1, students[k].Name, students[k].Avr);
	}
}

void Run_Management_Program() {
	int student_num = 0;
	
	printf("==== 학생 성적 관리 ====\n\n");
	printf("학생 수: ");
	scanf("%d", &student_num);

	Student_Info* students = (Student_Info*)malloc(sizeof(Student_Info) * student_num);
	if (students == NULL) {
		return;
	}

	Input_Info(student_num, students);
	Total_score(student_num, students);
	Avr_score(student_num, students);
	Print_All_Student(student_num, students);
	Best_Avr_Student(student_num, students);
	Search_Student(student_num, students);
	Ranking_Avr(student_num, students);

	free(students);
}