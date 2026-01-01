#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef struct {
    char jobName[50];
} PrintJob;

typedef struct {
    PrintJob jobs[MAX];
    int front, rear;
} CircularQueue;

// Initialize queue
void initQueue(CircularQueue* q) {
    q->front = q->rear = -1;
}

// Check if empty
int isEmpty(CircularQueue* q) {
    return q->front == -1;
}

// Check if full
int isFull(CircularQueue* q) {
    return (q->front == (q->rear + 1) % MAX);
}

// Enqueue job
void enqueue(CircularQueue* q, const char* name) {
    if(isFull(q)) {
        printf("Printer queue is full!\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    strcpy(q->jobs[q->rear].jobName, name);
    if(q->front == -1) q->front = q->rear;
    printf("Job '%s' added to printer queue.\n", name);
}

// Dequeue job
void dequeue(CircularQueue* q) {
    if(isEmpty(q)) {
        printf("No jobs to print!\n");
        return;
    }
    printf("Printing job: %s\n", q->jobs[q->front].jobName);
    if(q->front == q->rear) { // only one job
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

// Display jobs
void display(CircularQueue* q) {
    if(isEmpty(q)) {
        printf("Printer queue is empty!\n");
        return;
    }
    printf("Jobs in printer queue: ");
    int i = q->front;
    while(1) {
        printf("%s ", q->jobs[i].jobName);
        if(i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    CircularQueue q;
    initQueue(&q);
    int choice;
    char name[50];

    while(1) {
        printf("\n1. Add Print Job\n2. Process Print Job\n3. Display Queue\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch(choice) {
            case 1:
                printf("Enter job name: ");
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




Algorithm: Circular Printer Queue

1. Start
2. Initialize circular queue with front = -1, rear = -1, MAX size
3. Repeat until exit:
   a) Add Print Job:
       - If queue is full, display "Queue Full"
       - Else, increment rear circularly
       - Insert job at rear
       - If first job, set front = 0
   b) Process Print Job:
       - If queue is empty, display "No jobs"
       - Else, print job at front
       - If front == rear, set front = rear = -1 (queue becomes empty)
       - Else, increment front circularly
   c) Display Queue:
       - If queue is empty, display "Queue empty"
       - Else, print jobs from front to rear circularly
   d) Exit
4. End



Start
  |
  v
Initialize circular queue (front=-1, rear=-1)
  |
  v
Loop:
  |
  +--> Add Print Job:
  |      If queue full -> "Queue Full"
  |      Else -> rear = (rear+1)%MAX, insert job
  |      If first job -> front = rear
  |
  +--> Process Print Job:
  |      If empty -> "No jobs"
  |      Else -> print job at front
  |      If front == rear -> front=rear=-1
  |      Else -> front = (front+1)%MAX
  |
  +--> Display Queue:
  |      If empty -> "Queue empty"
  |      Else -> print jobs from front to rear circularly
  |
  +--> Exit
  |
  v
End
