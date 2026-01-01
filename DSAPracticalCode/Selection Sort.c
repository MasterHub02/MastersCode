#include <stdio.h>

int main() {
    int n, i, j, minIndex, temp;
    int price[50];

    printf("Enter number of products: ");
    scanf("%d", &n);

    printf("Enter product prices:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &price[i]);

    // Selection Sort
    for(i = 0; i < n - 1; i++) {
        minIndex = i;
        for(j = i + 1; j < n; j++) {
            if(price[j] < price[minIndex])
                minIndex = j;
        }
        // Swap
        temp = price[i];
        price[i] = price[minIndex];
        price[minIndex] = temp;
    }

    printf("Sorted product prices:\n");
    for(i = 0; i < n; i++)
        printf("%d ", price[i]);

    return 0;
}



Algorithm: Selection Sort for Product Prices

1. Start
2. Read number of products (n)
3. Read n product prices into array
4. For i = 0 to n-2:
     a) Set minIndex = i
     b) For j = i+1 to n-1:
          If price[j] < price[minIndex]:
              minIndex = j
     c) Swap price[i] and price[minIndex]
5. Display sorted prices
6. End



Start
  |
  v
Read n
  |
  v
Read product prices
  |
  v
i = 0
  |
  v
i < n-1 ?
  |
  +-- No --> Display sorted prices --> End
  |
  +-- Yes
        |
        v
   minIndex = i
        |
        v
   j = i + 1
        |
        v
   j < n ?
        |
        +-- No --> Swap price[i] & price[minIndex]
        |           i = i + 1 → Repeat
        |
        +-- Yes
             |
             v
      price[j] < price[minIndex] ?
             |
             +-- Yes → minIndex = j
             |
             +-- No
             |
             --> j = j + 1 → Repeat
