#include<stdio.h>

typedef struct {
	int id;
	char[20] name;
	char[20] course;
	int trimester;
	float gpa;
} Student;

void display_student(Student student) {
	printf("\nStudent Details: ");
	printf("\nStudent Name: %s",student.name);
	printf("\nCourse Enrolled: %s", student.course);
	printf("\nTrimester: %d",student.trimester);
	printf("\nMarks (in gpa): %.2f",student.gpa);
}

int main() {
	return 0;
}
