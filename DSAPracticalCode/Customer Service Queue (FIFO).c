#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
} Customer;

typedef struct {
    Customer items[MAX];
    int front, rear;
} Queue;

// Initialize queue
void initQueue(Queue* q) { q->front = q->rear = -1; }

// Check if empty
int isEmpty(Queue* q) { return q->front == -1; }

// Check if full
int isFull(Queue* q) { return q->rear == MAX-1; }

// Enqueue
void enqueue(Queue* q, const char* name) {
    if(isFull(q)) { printf("Queue is full!\n"); return; }
    if(isEmpty(q)) q->front = 0;
    q->rear++;
    strcpy(q->items[q->rear].name, name);
    printf("%s joined the queue.\n", name);
}

// Dequeue
void dequeue(Queue* q) {
    if(isEmpty(q)) { printf("No customers to serve!\n"); return; }
    printf("%s is served.\n", q->items[q->front].name);
    if(q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
}

// Display queue
void display(Queue* q) {
    if(isEmpty(q)) { printf("Queue is empty!\n"); return; }
    printf("Customers in queue: ");
    for(int i = q->front; i <= q->rear; i++)
        printf("%s ", q->items[i].name);
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);
    int choice;
    char name[50];

    while(1) {
        printf("\n1. Add Customer\n2. Serve Customer\n3. Display Queue\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch(choice) {
            case 1:
                printf("Enter customer name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                enqueue(&q, name);
                break;

            case 2:
                dequeue(&q);
                break;

            case 3:
                display(&q);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}



Algorithm: Customer Service Queue

1. Start
2. Initialize an empty queue
3. Repeat until exit:
   a) Add Customer:
       - Input customer name
       - Enqueue customer at rear of queue
   b) Serve Customer:
       - If queue is empty, display "No customers"
       - Else, dequeue customer from front and display "Customer served"
   c) Display Queue:
       - Print all customers from front to rear
   d) Exit
4. End













Start
  |
  v
Initialize empty queue
  |
  v
Loop:
  |
  +--> Add Customer:
  |      Input name
  |      Enqueue at rear
  |
  +--> Serve Customer:
  |      If queue empty -> "No customers"
  |      Else -> Dequeue from front, display served
  |
  +--> Display Queue:
  |      Print all customers front to rear
  |
  +--> Exit
  |
  v
End
