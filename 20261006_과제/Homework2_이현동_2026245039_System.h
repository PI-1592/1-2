#ifndef STUDENT_H
#define STUDENT_H

#define MAX_NAME_LENGTH 50
#define MAX_COURSES 10

// 과목 구조체
typedef struct {
    char courseName[MAX_NAME_LENGTH];
    int credit; // 수강 학점
    float score; // 학점
} Course;

// 학생 구조체
typedef struct {
    char* name;
    char studentID[10];
    int numCourses;
    Course courses[MAX_COURSES];
} Student;

// 함수 원형 선언
// 파일에서 데이터 읽기
void readStudentsFromFile(Student* students[], int* studentCount);
// 전체 학생 출력
void printStudents(Student* students[], int studentCount);
// GPA 기준 버블 정렬
void sortStudentsByGPA(Student* students[], int studentCount);
// GPA 계산 및 반환
float calculateGPA(Student* student);
// 이름으로 학생 찾기
void searchStudentByName(Student* students[], int studentCount, const char* name);
// 학번으로 학생 찾기
void searchStudentByID(Student* students[], int studentCount, const char* studentID);
// 학생 추가
void addStudent(Student* students[], int* studentCount);
// GPA 기준 내림차순 정렬결과 저장
void saveSortedStudentsToFile(Student* students[], int studentCount, const char* filename);
// 추가된 학생 포함 정보 저장
void saveAddedStudentsToFile(Student* students[], int studentCount, const char* filename);

#endif // !STUDENT_H