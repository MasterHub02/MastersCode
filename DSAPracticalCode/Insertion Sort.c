#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j;
    char names[50][50], temp[50];

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter student names:\n");
    for(i = 0; i < n; i++)
        scanf("%s", names[i]);

    // Insertion Sort
    for(i = 1; i < n; i++) {
        strcpy(temp, names[i]);
        j = i - 1;

        while(j >= 0 && strcmp(names[j], temp) > 0) {
            strcpy(names[j + 1], names[j]);
            j--;
        }
        strcpy(names[j + 1], temp);
    }

    printf("\nSorted student names:\n");
    for(i = 0; i < n; i++)
        printf("%s\n", names[i]);

    return 0;
}



Algorithm: Insertion Sort for Student Names

1. Start
2. Read number of students (n)
3. Read n student names into array
4. For i = 1 to n-1:
     a) Store current name in temp
     b) Set j = i - 1
     c) While j >= 0 and name[j] > temp:
           name[j+1] = name[j]
           j = j - 1
     d) Insert temp at position j+1
5. Display sorted names
6. End




Start
  |
  v
Read n
  |
  v
Read student names
  |
  v
i = 1
  |
  v
i < n ?
  |
  +-- No --> Display sorted names --> End
  |
  +-- Yes
        |
        v
     temp = names[i]
     j = i - 1
        |
        v
   j >= 0 AND names[j] > temp ?
        |
        +-- Yes --> names[j+1] = names[j]
        |           j = j - 1 → Repeat
        |
        +-- No --> names[j+1] = temp
                    i = i + 1 → Repeat
