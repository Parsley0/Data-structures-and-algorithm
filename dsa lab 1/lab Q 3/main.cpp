#include <iostream>
#include <string>
using namespace std;

struct Course {
    string course_code;
    string course_name;
};

struct Grade {
    int mark;
    char the_grade;
};

struct Student {
    string reg_number;
    string name;
    int age;
    Course course;
    Grade grade;
};

Student students[40];
int num_students = 0;

void addStudent() {
    if (num_students < 40) {
        cout << "Enter registration number: ";
        cin >> students[num_students].reg_number;
        cout << "Enter name: ";
        cin >> students[num_students].name;
        cout << "Enter age: ";
        cin >> students[num_students].age;
        cout << "Enter course code: ";
        cin >> students[num_students].course.course_code;
        cout << "Enter course name: ";
        cin >> students[num_students].course.course_name;
        num_students++;
    } else {
        cout << "Maximum number of students reached." << endl;
    }
}

void editStudent(int index) {
    if (index >= 0 && index < num_students) {
        cout << "Enter new registration number: ";
        cin >> students[index].reg_number;
        cout << "Enter new name: ";
        cin >> students[index].name;
        cout << "Enter new age: ";
        cin >> students[index].age;
        cout << "Enter new course code: ";
        cin >> students[index].course.course_code;
        cout << "Enter new course name: ";
        cin >> students[index].course.course_name;
    } else {
        cout << "Invalid student index." << endl;
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
        cout << "Invalid student index." << endl;
    }
}

int main() {
    int choice, studentIndex, mark;
    while (true) {
        cout << "\n1. Add student\n2. Edit student details\n3. Add marks and calculate grades\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                cout << "Enter index of student to edit: ";
                cin >> studentIndex;
                editStudent(studentIndex);
                break;
            case 3:
                cout << "Enter index of student to add marks: ";
                cin >> studentIndex;
                cout << "Enter marks: ";
                cin >> mark;
                addMarksAndCalculateGrades(studentIndex, mark);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
