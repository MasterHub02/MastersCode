#include <stdio.h>

int main() {
    int n, i, key, low, high, mid, found = 0;
    int roll[50];

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter sorted roll numbers:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &roll[i]);

    printf("Enter roll number to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(roll[mid] == key) {
            found = 1;
            break;
        } else if(key < roll[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if(found)
        printf("Roll number FOUND at position %d\n", mid + 1);
    else
        printf("Roll number NOT FOUND\n");

    return 0;
}





Algorithm: Binary Search for Student Roll Number

1. Start
2. Read number of students (n)
3. Read n sorted roll numbers into array
4. Read roll number to search (key)
5. Set low = 0, high = n - 1
6. While low <= high:
     a) mid = (low + high) / 2
     b) If array[mid] == key → Roll Found → Stop
     c) If key < array[mid] → high = mid - 1
     d) If key > array[mid] → low = mid + 1
7. If not found → Roll Not Found
8. End




Start
  |
  v
Read n
  |
  v
Read sorted roll numbers
  |
  v
Read search key
  |
  v
low = 0, high = n-1
  |
  v
low <= high ?
  |
  +-- No --> Roll Not Found --> End
  |
  +-- Yes
        |
        v
     mid = (low + high) / 2
        |
        v
   roll[mid] == key ?
        |
        +-- Yes --> Roll Found --> End
        |
        +-- No
             |
             +--> key < roll[mid] → high = mid - 1
             |
             +--> key > roll[mid] → low = mid + 1
             |
             --> Repeat loop
