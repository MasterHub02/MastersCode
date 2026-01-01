#include <stdio.h>
#include <string.h>

int main() {
    int n, i, found = 0;
    char students[50][50], search[50];

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter student names:\n");
    for(i = 0; i < n; i++) {
        scanf("%s", students[i]);
    }

    printf("Enter name to search: ");
    scanf("%s", search);

    for(i = 0; i < n; i++) {
        if(strcmp(students[i], search) == 0) {
            found = 1;
            break;
        }
    }

    if(found)
        printf("Student is REGISTERED.\n");
    else
        printf("Student is NOT REGISTERED.\n");

    return 0;
}




Algorithm: Sequential Search for Student Registration

1. Start
2. Input number of students (n)
3. Read n student names into an array
4. Input the name to be searched
5. For i = 0 to n-1:
     a) If student[i] == searchName:
           Display "Student Registered"
           Stop
6. If not found after loop:
     Display "Student Not Registered"
7. End




Start
  |
  v
Read n
  |
  v
Read student names into array
  |
  v
Read search name
  |
  v
i = 0
  |
  v
Is i < n ?
  |
  +-- No --> Student Not Registered --> End
  |
  +-- Yes
        |
        v
   students[i] == search ?
        |
        +-- Yes --> Student Registered --> End
        |
        +-- No --> i = i + 1 --> Repeat
