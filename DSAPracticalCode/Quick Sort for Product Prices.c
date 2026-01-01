#include <stdio.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while(i <= j) {
        while(i <= high && arr[i] <= pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    int n, i;
    int price[50];

    printf("Enter number of products: ");
    scanf("%d", &n);

    printf("Enter product prices:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &price[i]);

    quickSort(price, 0, n - 1);

    printf("Sorted product prices:\n");
    for(i = 0; i < n; i++)
        printf("%d ", price[i]);

    return 0;
}




Algorithm: Quick Sort for Product Prices

1. Start
2. Read number of products (n)
3. Read n product prices into array
4. Apply Quick Sort:
     a) Choose first element as pivot
     b) Partition array so that:
          - Elements < pivot are on left
          - Elements > pivot are on right
     c) Recursively apply Quick Sort on left sub-array
     d) Recursively apply Quick Sort on right sub-array
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
QuickSort(array, low, high)
  |
  v
low < high ?
  |
  +-- No --> Return
  |
  +-- Yes
        |
        v
   Select pivot
        |
        v
   Partition array
        |
        v
QuickSort(left sub-array)
QuickSort(right sub-array)
  |
  v
Display sorted prices
  |
  v
End
