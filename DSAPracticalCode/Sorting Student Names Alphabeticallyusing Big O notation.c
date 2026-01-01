#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    int n;
    char names[50][50], temp[50];
    clock_t start, end;
    double time_taken;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter student names:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    start = clock();   // Start time

    // Bubble Sort for strings
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    end = clock();   // End time
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nSorted Student Names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    printf("\nTime taken to sort: %f seconds\n", time_taken);

    return 0;
}

1. Start
2. Read number of students
3. Read student names
4. Sort the names alphabetically using Bubble Sort
5. Calculate execution time
6. Display sorted names
7. Stop


 ┌───────┐
 │ Start │
 └───┬───┘
     ↓
 Read number of students
     ↓
 Input names
     ↓
 Sort names (Bubble Sort)
     ↓
 Display sorted names
     ↓
 Show execution time
     ↓
 ┌───────┐
 │  End  │
 └───────┘
