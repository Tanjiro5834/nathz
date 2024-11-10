#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_STUDENTS 100

typedef struct {
    char name[50];
    int id;
    char course[50];
} Student;

Student students[NUM_STUDENTS]; 
int num_students = 0;

void addStudent();
void removeStudent();
void updateStudent();
void viewStudents();
int generateID(); 

int choice;

void addStudent() {
    int num_students_to_add;
    printf("Enter number of students to add: ");
    scanf("%d", &num_students_to_add);
    getchar();

    for (int i = 0; i < num_students_to_add; i++) {
        if (num_students >= NUM_STUDENTS) {
            printf("Maximum student limit reached!\n");
            return;
        }

        printf("Enter student name: ");
        fgets(students[num_students].name, sizeof(students[num_students].name), stdin);
        students[num_students].name[strcspn(students[num_students].name, "\n")] = '\0';

        students[num_students].id = generateID(); 

        printf("Enter course: ");
        fgets(students[num_students].course, sizeof(students[num_students].course), stdin);
        students[num_students].course[strcspn(students[num_students].course, "\n")] = '\0';

        num_students++;
        printf("New student added.\n");
    }
}

void removeStudent() {
    int search_id;
    printf("Enter student ID to find: ");
    scanf("%d", &search_id);

    bool found = false;
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == search_id) {
            found = true;
            printf("\nStudent Information\n");
            printf("Name: %s\n", students[i].name);
            printf("ID: %d\n", students[i].id);
            printf("Course: %s\n", students[i].course);

            for (int j = i; j < num_students - 1; j++) {
                students[j] = students[j + 1];
            }
            num_students--;
            printf("Student removed.\n");
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", search_id);
    }
}

void updateStudent() {
    int search_id;
    printf("Enter student ID to update: ");
    scanf("%d", &search_id);
    getchar();

    bool found = false;
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == search_id) {
            found = true;
            printf("Update student name (current: %s): ", students[i].name);
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0';

            printf("Update course (current: %s): ", students[i].course);
            fgets(students[i].course, sizeof(students[i].course), stdin);
            students[i].course[strcspn(students[i].course, "\n")] = '\0';

            printf("Student updated.\n");
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", search_id);
    }
}

void viewStudents() {
    if (num_students == 0) {
        printf("No students available.\n");
        return;
    }

    printf("\nAll Students:\n");
    for (int i = 0; i < num_students; i++) {
        printf("ID: %d, Name: %s, Course: %s\n", students[i].id, students[i].name, students[i].course);
    }
}

int generateID() { 
    srand(time(0)); 
    int lower = 50, higher = 100;
    return (rand() % (higher - lower + 1)) + lower;  
}

int main() {
    while (1) {
        printf("\n1. Add student\n2. Remove student\n3. Update student\n4. View all students\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                removeStudent();
                break;
            case 3:
                updateStudent();
                break;
            case 4:
                viewStudents();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
