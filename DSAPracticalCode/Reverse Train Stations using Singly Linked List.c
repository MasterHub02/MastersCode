#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for station node
struct Station {
    char name[50];
    struct Station *next;
};

struct Station *head = NULL;

// Insert station at end
void insertStation() {
    struct Station *newNode, *temp;
    newNode = (struct Station *)malloc(sizeof(struct Station));

    printf("Enter station name: ");
    scanf("%s", newNode->name);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Display stations
void displayStations() {
    struct Station *temp = head;
    if (head == NULL) {
        printf("No stations available.\n");
        return;
    }
    printf("Stations:\n");
    while (temp != NULL) {
        printf("%s -> ", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Reverse the linked list
void reverseList() {
    struct Station *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int main() {
    int n;

    printf("Enter number of stations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        insertStation();
    }

    printf("\nForward Journey:\n");
    displayStations();

    reverseList();

    printf("\nReturn Journey (Reversed Order):\n");
    displayStations();

    return 0;
}


1. Start
2. Initialize head pointer to NULL
3. Insert station names into singly linked list
4. Display stations (forward journey)
5. Reverse the linked list
6. Display reversed list (return journey)
7. Stop


Start
  ↓
Insert stations into list
  ↓
Display forward journey
  ↓
Reverse linked list
  ↓
Display return journey
  ↓
End
