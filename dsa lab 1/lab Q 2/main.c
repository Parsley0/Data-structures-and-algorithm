#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 40
#define MAX_COURSES 5

typedef struct {
    char course_code[10];
    char course_name[50];
} Course;

typedef struct {
    int mark;
    char the_grade;
} Grade;

typedef struct {
    char reg_number[20];
    char name[50];
    int age;
    Course course;
    Grade grade;
} Student;

Student students[MAX_STUDENTS];
int num_students = 0;

void addStudent() {
    if (num_students < MAX_STUDENTS) {
        printf("Enter registration number: ");
        scanf("%s", students[num_students].reg_number);
        printf("Enter name: ");
        scanf("%s", students[num_students].name);
        printf("Enter age: ");
        scanf("%d", &students[num_students].age);
        printf("Enter course code: ");
        scanf("%s", students[num_students].course.course_code);
        printf("Enter course name: ");
        scanf("%s", students[num_students].course.course_name);
        num_students++;
    } else {
        printf("Maximum number of students reached.\n");
    }
}

void editStudent(int index) {
    if (index >= 0 && index < num_students) {
        printf("Enter new registration number: ");
        scanf("%s", students[index].reg_number);
        printf("Enter new name: ");
        scanf("%s", students[index].name);
        printf("Enter new age: ");
        scanf("%d", &students[index].age);
        printf("Enter new course code: ");
        scanf("%s", students[index].course.course_code);
        printf("Enter new course name: ");
        scanf("%s", students[index].course.course_name);
    } else {
        printf("Invalid student index.\n");
    }
}

void addMarksAndCalculateGrades(int index, int mark) {
    if (index >= 0 && index < num_students) {
        students[index].grade.mark = mark;
        if (mark > 69) {
            students[index].grade.the_grade = 'A';
        } else if (mark > 59) {
            students[index].grade.the_grade = 'B';
        } else if (mark > 49) {
            students[index].grade.the_grade = 'C';
        } else if (mark > 39) {
            students[index].grade.the_grade = 'D';
        } else {
            students[index].grade.the_grade = 'E';
        }
    } else {
        printf("Invalid student index.\n");
    }
}

int main() {
    int choice, studentIndex, mark;
    while (1) {
        printf("\n1. Add student\n2. Edit student details\n3. Add marks and calculate grades\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                printf("Enter index of student to edit: ");
                scanf("%d", &studentIndex);
                editStudent(studentIndex);
                break;
            case 3:
                printf("Enter index of student to add marks: ");
                scanf("%d", &studentIndex);
                printf("Enter marks: ");
                scanf("%d", &mark);
                addMarksAndCalculateGrades(studentIndex, mark);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

