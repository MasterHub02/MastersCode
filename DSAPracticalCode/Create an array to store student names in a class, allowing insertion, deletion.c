#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100; // Maximum number of students

class StudentList {
private:
    string students[MAX_SIZE];
    int count; // Current number of students

public:
    StudentList() {
        count = 0;
    }

    // Insert a student at the end
    void insertStudent(const string& name) {
        if (count < MAX_SIZE) {
            students[count] = name;
            count++;
            cout << name << " added successfully.\n";
        } else {
            cout << "Cannot add more students. Array full.\n";
        }
    }

    // Delete a student by name
    void deleteStudent(const string& name) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (students[i] == name) {
                found = true;
                // Shift remaining elements left
                for (int j = i; j < count - 1; j++) {
                    students[j] = students[j + 1];
                }
                count--;
                cout << name << " deleted successfully.\n";
                break;
            }
        }
        if (!found) {
            cout << name << " not found in the list.\n";
        }
    }

    // Traverse and display all students
    void displayStudents() {
        if (count == 0) {
            cout << "No students in the list.\n";
            return;
        }
        cout << "Students in class:\n";
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". " << students[i] << endl;
        }
    }
};

int main() {
    StudentList classList;
    int choice;
    string name;

    do {
        cout << "\n--- Student Management ---\n";
        cout << "1. Insert student\n";
        cout << "2. Delete student\n";
        cout << "3. Display students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore newline after choice input

        switch (choice) {
            case 1:
                cout << "Enter student name to insert: ";
                getline(cin, name);
                classList.insertStudent(name);
                break;
            case 2:
                cout << "Enter student name to delete: ";
                getline(cin, name);
                classList.deleteStudent(name);
                break;
            case 3:
                classList.displayStudents();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}


Algorithm
1. Start
2. Initialize array and set count = 0
3. Display menu (Insert, Delete, Display, Exit)
4. Read user choice
5. If choice = Insert, add student to array
6. If choice = Delete, remove student by shifting elements
7. If choice = Display, show all students
8. Repeat until Exit
9. Stop

 ┌───────┐
 │ Start │
 └───┬───┘
     ↓
 ┌──────────────┐
 │ Display Menu │
 └───┬──────────┘
     ↓
 ┌──────────────┐
 │ Read Choice  │
 └───┬──────────┘
     ↓
 ┌──────────────┐
 │ Choice = 1 ? │──Yes──► Insert Student
 └───┬──────────┘
     │No
     ↓
 ┌──────────────┐
 │ Choice = 2 ? │──Yes──► Delete Student
 └───┬──────────┘
     │No
     ↓
 ┌──────────────┐
 │ Choice = 3 ? │──Yes──► Display Students
 └───┬──────────┘
     │No
     ↓
 ┌──────────────┐
 │ Choice = 4 ? │──Yes──► End
 └───┬──────────┘
     │No
     ↓
  Invalid Choice
     ↓
   Repeat
