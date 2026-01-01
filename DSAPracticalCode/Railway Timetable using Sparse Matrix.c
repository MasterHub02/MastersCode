#include <stdio.h>
#define MAX 100
// Structure to store sparse matrix elements
struct Sparse {
int row;
int col;
int value;
};
int main() {
int railway[10][10], rows, cols;
struct Sparse sparse[MAX];
int k = 0;
printf("Enter number of trains (rows): ");
scanf("%d", &rows);
printf("Enter number of stations/time-slots (cols): ");
scanf("%d", &cols);
printf("\nEnter the railway timetable matrix (0 for no train, 1 for active train):\n");
// Input timetable
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
scanf("%d", &railway[i][j]);
if (railway[i][j] != 0) {
// Store only active entries
sparse[k].row = i;
sparse[k].col = j;
sparse[k].value = railway[i][j];
k++;
}
}

}
// Print sparse matrix representation
printf("\nSparse Matrix Representation (Only Active Train Schedules):\n");
printf("Row\tCol\tValue\n");
for (int i = 0; i < k; i++) {
printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
}
printf("\nTotal active schedules stored: %d\n", k);
return 0;
}


Algorithm
1. Start
2. Read number of trains and time-slots
3. Input railway timetable matrix
4. If element is non-zero, store row, column and value in structure
5. Display sparse matrix
6. Stop





 ┌───────┐
 │ Start │
 └───┬───┘
     ↓
 ┌──────────────────────┐
 │ Read rows & columns  │
 └───┬──────────────────┘
     ↓
 ┌──────────────────────┐
 │ Input timetable      │
 └───┬──────────────────┘
     ↓
 ┌──────────────────────┐
 │ Element ≠ 0 ?        │
 └───┬───────────┬──────┘
     │Yes         │No
     ↓            ↓
 Store in sparse  Ignore
     ↓
 ┌──────────────────────┐
 │ Display sparse matrix│
 └───┬──────────────────┘
     ↓
 ┌───────┐
 │  End  │
 └───────┘
