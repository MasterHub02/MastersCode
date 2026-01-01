#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

struct Book {
    int isbn;
    char title[50];
};

struct Book hashTable[TABLE_SIZE];

// Initialize hash table
void initTable() {
    for(int i = 0; i < TABLE_SIZE; i++)
        hashTable[i].isbn = -1;
}

// Hash function
int hashFunction(int isbn) {
    return isbn % TABLE_SIZE;
}

// Insert book
void insert(int isbn, char title[]) {
    int index = hashFunction(isbn);
    hashTable[index].isbn = isbn;
    strcpy(hashTable[index].title, title);
}

// Search book
void search(int isbn) {
    int index = hashFunction(isbn);
    if(hashTable[index].isbn == isbn)
        printf("Book Found: %s\n", hashTable[index].title);
    else
        printf("Book Not Found!\n");
}

int main() {
    initTable();
    int choice, isbn;
    char title[50];

    while(1) {
        printf("\n1. Add Book\n2. Search Book\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter ISBN: ");
                scanf("%d", &isbn);
                printf("Enter Book Title: ");
                scanf("%s", title);
                insert(isbn, title);
                break;

            case 2:
                printf("Enter ISBN to search: ");
                scanf("%d", &isbn);
                search(isbn);
                break;

            case 3:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}



Algorithm: Book Search using Hashing (ISBN)

1. Start
2. Initialize hash table with size TABLE_SIZE
3. Hash function:
     index = ISBN % TABLE_SIZE
4. Insert Book:
     - Compute index using hash function
     - Store ISBN and book title at that index
5. Search Book:
     - Compute index using same hash function
     - If ISBN at index matches → Book Found
     - Else → Book Not Found
6. End




Start
  |
  v
Initialize hash table
  |
  v
Menu
  |
  +--> Insert Book
  |      Read ISBN, Title
  |      index = ISBN % TABLE_SIZE
  |      Store book at index
  |
  +--> Search Book
  |      Read ISBN
  |      index = ISBN % TABLE_SIZE
  |      ISBN matches?
  |         Yes → Book Found
  |         No  → Book Not Found
  |
  +--> Exit
  |
  v
End
