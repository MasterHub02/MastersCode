#include <stdio.h>

int main() {
    int n, i, j, temp;
    int marks[50];

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter student marks:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &marks[i]);

    // Bubble Sort
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(marks[j] > marks[j + 1]) {
                temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }

    printf("Sorted marks:\n");
    for(i = 0; i < n; i++)
        printf("%d ", marks[i]);

    return 0;
}



Algorithm: Bubble Sort for Student Marks

1. Start
2. Read number of students (n)
3. Read n marks into array
4. For i = 0 to n-2:
     For j = 0 to n-i-2:
        If marks[j] > marks[j+1]:
            Swap marks[j] and marks[j+1]
5. Display sorted marks
6. End




Start
  |
  v
Read n
  |
  v
Read marks array
  |
  v
i = 0
  |
  v
i < n-1 ?
  |
  +-- No --> Display sorted marks --> End
  |
  +-- Yes
        |
        v
     j = 0
        |
        v
     j < n-i-1 ?
        |
        +-- No --> i = i + 1 --> Repeat
        |
        +-- Yes
             |
             v
        marks[j] > marks[j+1] ?
             |
             +-- Yes --> Swap
             |
             +-- No
             |
             --> j = j + 1 --> Repeat
