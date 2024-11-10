#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll_no;
    char name[50];
    float marks;
};

void addStudent(struct Student *student) {
    printf("Enter Roll Number: ");
    scanf("%d", &student->roll_no);
    getchar();  // To consume newline character left by scanf

    printf("Enter Name: ");
    fgets(student->name, 50, stdin);
    student->name[strcspn(student->name, "\n")] = '\0'; // Remove trailing newline from name

    printf("Enter Marks: ");
    scanf("%f", &student->marks);
}

void displayStudent(struct Student student) {
    printf("\nStudent Record:\n");
    printf("Roll Number: %d\n", student.roll_no);
    printf("Name: %s\n", student.name);
    printf("Marks: %.2f\n", student.marks);
}

void updateStudent(struct Student *student) {
    int choice;
    printf("Update Record for Roll Number %d:\n", student->roll_no);
    printf("1. Update Name\n");
    printf("2. Update Marks\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            getchar();  // To consume newline character left by scanf
            printf("Enter new Name: ");
            fgets(student->name, 50, stdin);
            student->name[strcspn(student->name, "\n")] = '\0';
            break;
        case 2:
            printf("Enter new Marks: ");
            scanf("%f", &student->marks);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

int main() {
    struct Student student1;
    int choice;

    while (1) {
        printf("\n--- Student Record Management System ---\n");
        printf("1. Add Student Record\n");
        printf("2. Display Student Record\n");
        printf("3. Update Student Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&student1);
                break;
            case 2:
                displayStudent(student1);
                break;
            case 3:
                updateStudent(&student1);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
