#include<stdio.h>
int main() {
int students, subjects;
printf("Enter number of students: ");
scanf("%d", &students);
printf("Enter number of subjects: ");
scanf("%d", &subjects);
int marks[students][subjects]; // 2D Array Declaration
// Input marks
printf("\nEnter marks for each student:\n");
for (int i = 0; i< students; i++) {
printf("Student %d:\n", i + 1);
for (int j = 0; j< subjects; j++) {
printf(" Subject %d: ", j + 1);
scanf("%d", &marks[i][j]);
}
}

// Display marks
printf("\n===== Student Marks Table =====\n");
for (int i = 0; i< students; i++) {
printf("Student %d: ", i + 1);
for (int j = 0; j< subjects; j++) {
printf("%d ", marks[i][j]);
}
printf("\n");
}
return 0;
}


1. Start
2. Read number of students and subjects
3. Input ensure marks into a 2D array
4. Display marks of all students
5. Stop

Start
  ↓
Read students & subjects
  ↓
Input marks into 2D array
  ↓
Display marks
  ↓
End
