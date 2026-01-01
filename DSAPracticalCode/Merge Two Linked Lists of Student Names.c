#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    struct Node* next;
} Node;

// Create node
Node* createNode(const char* name) {
    Node* n = (Node*)malloc(sizeof(Node));
    strcpy(n->name, name);
    n->next = NULL;
    return n;
}

// Insert at end
void insert(Node** head, const char* name) {
    Node* n = createNode(name);
    if (!*head) { *head = n; return; }
    Node* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = n;
}

// Merge lists
Node* merge(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;
    Node* temp = a;
    while (temp->next) temp = temp->next;
    temp->next = b;
    return a;
}

// Print list
void printList(Node* head) {
    while (head) {
        printf("%s", head->name);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *classA = NULL, *classB = NULL;
    int n, i;
    char name[50];

    printf("Enter number of students in Class A: ");
    scanf("%d", &n);
    getchar(); // consume newline
    for(i=0;i<n;i++){
        printf("Student %d: ", i+1);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name,"\n")] = 0; // remove newline
        insert(&classA, name);
    }

    printf("Enter number of students in Class B: ");
    scanf("%d", &n);
    getchar();
    for(i=0;i<n;i++){
        printf("Student %d: ", i+1);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name,"\n")] = 0;
        insert(&classB, name);
    }

    printf("\nClass A: "); printList(classA);
    printf("Class B: "); printList(classB);

    classA = merge(classA, classB);
    printf("Merged Class: "); printList(classA);

    return 0;
}



Algorithm: Merge Two Linked Lists of Student Names

1. Start
2. Create empty linked lists: classA = NULL, classB = NULL
3. Input Class A students:
   - Read number of students n
   - For i = 1 to n:
       - Read name
       - Insert name at end of classA
4. Input Class B students:
   - Read number of students m
   - For i = 1 to m:
       - Read name
       - Insert name at end of classB
5. Merge lists:
   - If classA is empty, merged list = classB
   - Else, attach classB at end of classA
6. Display merged list
7. End


Start
  |
  v
Create classA = NULL, classB = NULL
  |
  v
Input number of students in Class A (n)
  |
  v
For i = 1 to n
  |  Read student name
  |  Insert at end of classA
  v
Input number of students in Class B (m)
  |
  v
For i = 1 to m
  |  Read student name
  |  Insert at end of classB
  v
Merge classB at end of classA
  |
  v
Display merged list
  |
  v
End
