#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for student node
struct Student {
    int roll;
    char name[50];
    struct Student *next;
};

struct Student *head = NULL;

// Create / Insert student at end
void insertStudent() {
    struct Student *newNode, *temp;
    newNode = (struct Student*)malloc(sizeof(struct Student));

    printf("Enter Roll Number: ");
    scanf("%d", &newNode->roll);
    printf("Enter Name: ");
    scanf("%s", newNode->name);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Student record inserted.\n");
}

// Delete student by roll number
void deleteStudent() {
    struct Student *temp, *prev;
    int roll;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    temp = head;

    if (temp->roll == roll) {
        head = temp->next;
        free(temp);
        printf("Student record deleted.\n");
        return;
    }

    prev = temp;
    temp = temp->next;

    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Student not found.\n");
    } else {
        prev->next = temp->next;
        free(temp);
        printf("Student record deleted.\n");
    }
}

// Display student records
void displayStudents() {
    struct Student *temp = head;

    if (head == NULL) {
        printf("No student records available.\n");
        return;
    }

    printf("\nStudent Records:\n");
    while (temp != NULL) {
        printf("Roll: %d, Name: %s\n", temp->roll, temp->name);
        temp = temp->next;
    }
}

int main() {
    int choice;

    do {
        printf("\n--- Student Record System ---\n");
        printf("1. Insert Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertStudent(); break;
            case 2: deleteStudent(); break;
            case 3: displayStudents(); break;
            case 4: printf("Exiting program.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}


1. Start
2. Initialize head pointer to NULL
3. Display menu
4. If choice = Insert
   - Create new node
   - Insert at end of list
5. If choice = Delete
   - Search student by roll number
   - Delete node
6. If choice = Display
   - Traverse and display all records
7. Repeat until Exit
8. Stop


Start
  ↓
Display Menu
  ↓
Read Choice
  ↓
Insert ? → Insert Student
Delete ? → Delete Student
Display ? → Display Records
Exit ? → End
  ↓
Repeat
