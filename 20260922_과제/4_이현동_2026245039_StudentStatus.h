#ifndef STUDENT_STATUS_H
#define STUDENT_STATUS_H

typedef struct {
	char Name[30];
	int Id;
	int Kor;
	int Eng;
	int Math;
	int Sum;
	double Avr;
} Student_Info;

void Input_Info(int student_num, Student_Info* students);
void Total_score(int student_num, Student_Info* students);
void Avr_score(int student_num, Student_Info* students);
void Print_Info(Student_Info* students, int user_num);
void Search_Student(int student_num, Student_Info* students);
void Print_All_Student(int student_num, Student_Info* students);
void Best_Avr_Student(int student_num, Student_Info* students);
void Ranking_Avr(int student_num, Student_Info* students);
void Run_Management_Program();

#endif