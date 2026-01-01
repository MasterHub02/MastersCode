#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Doubly linked list node
typedef struct Song {
    char name[50];
    struct Song* next;
    struct Song* prev;
} Song;

// Create a new song node
Song* createSong(char name[]) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->name, name);
    newSong->next = NULL;
    newSong->prev = NULL;
    return newSong;
}

// Add song at end
void addSong(Song** head, Song** tail, char name[]) {
    Song* newSong = createSong(name);
    if (*head == NULL) {
        *head = *tail = newSong;
    } else {
        (*tail)->next = newSong;
        newSong->prev = *tail;
        *tail = newSong;
    }
}

// Play playlist forward
void playForward(Song* head) {
    printf("Playing Forward:\n");
    Song* temp = head;
    while (temp) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

// Play playlist backward
void playBackward(Song* tail) {
    printf("Playing Backward:\n");
    Song* temp = tail;
    while (temp) {
        printf("%s\n", temp->name);
        temp = temp->prev;
    }
}

int main() {
    Song *head = NULL, *tail = NULL;
    int n, i;
    char name[50];

    printf("Enter number of songs: ");
    scanf("%d", &n);
    getchar(); // consume newline

    for (i = 0; i < n; i++) {
        printf("Enter song %d name: ", i + 1);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0; // remove newline
        addSong(&head, &tail, name);
    }

    printf("\n");
    playForward(head);
    printf("\n");
    playBackward(tail);

    return 0;
}


1. Start
2. Create a doubly linked list node structure with:
       - song name
       - pointer to next node
       - pointer to previous node
3. Initialize playlist head and tail as NULL
4. To add a song:
       - Create a new node
       - If list is empty, set head and tail to new node
       - Else, add node at end, update tail
5. To play songs forward:
       - Start from head
       - Traverse using next pointer, print song names
6. To play songs backward:
       - Start from tail
       - Traverse using prev pointer, print song names
7. End



Start
  |
  v
Create doubly linked list node (song name, next, prev)
  |
  v
Initialize head = NULL, tail = NULL
  |
  v
Input number of songs (n)
  |
  v
For i = 1 to n
  |  Input song name
  |  Create node and add at end of list
  v
Play Forward:
  - Start from head
  - Traverse using next pointer
  - Print song names
Play Backward:
  - Start from tail
  - Traverse using prev pointer
  - Print song names
  |
  v
End
