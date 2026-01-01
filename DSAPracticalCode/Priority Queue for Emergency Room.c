#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int severity;
} Patient;

typedef struct {
    Patient patients[MAX];
    int size;
} PriorityQueue;

// Initialize
void initQueue(PriorityQueue* pq) {
    pq->size = 0;
}

// Insert patient based on severity (higher severity first)
void enqueue(PriorityQueue* pq, const char* name, int severity) {
    if(pq->size == MAX) {
        printf("Emergency room full!\n");
        return;
    }
    int i = pq->size - 1;
    // Shift patients with lower severity to the right
    while(i >= 0 && pq->patients[i].severity < severity) {
        pq->patients[i+1] = pq->patients[i];
        i--;
    }
    strcpy(pq->patients[i+1].name, name);
    pq->patients[i+1].severity = severity;
    pq->size++;
    printf("Patient %s with severity %d added.\n", name, severity);
}

// Treat patient (remove highest severity)
void dequeue(PriorityQueue* pq) {
    if(pq->size == 0) {
        printf("No patients to treat!\n");
        return;
    }
    printf("Treating patient: %s (Severity %d)\n", pq->patients[0].name, pq->patients[0].severity);
    // Shift remaining patients
    for(int i = 1; i < pq->size; i++)
        pq->patients[i-1] = pq->patients[i];
    pq->size--;
}

// Display all patients
void display(PriorityQueue* pq) {
    if(pq->size == 0) {
        printf("No patients in the queue.\n");
        return;
    }
    printf("Patients in queue (high severity first):\n");
    for(int i = 0; i < pq->size; i++)
        printf("%s (Severity %d)\n", pq->patients[i].name, pq->patients[i].severity);
}

int main() {
    PriorityQueue pq;
    initQueue(&pq);
    int choice, severity;
    char name[50];

    while(1) {
        printf("\n1. Add Patient\n2. Treat Patient\n3. Display Queue\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch(choice) {
            case 1:
                printf("Enter patient name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                printf("Enter severity (higher = more critical): ");
                scanf("%d", &severity);
                getchar();
                enqueue(&pq, name, severity);
                break;

            case 2:
                dequeue(&pq);
                break;

            case 3:
                display(&pq);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}





Algorithm: Hospital Emergency Room (Priority Queue)

1. Start
2. Initialize empty priority queue
3. Repeat until exit:
   a) Add Patient:
       - Input patient name and severity (higher number = higher priority)
       - Insert patient into queue based on severity
   b) Treat Patient:
       - If queue empty, display "No patients"
       - Else, remove patient with highest severity (first in queue)
       - Display "Patient treated"
   c) Display Queue:
       - Print all patients from highest to lowest severity
   d) Exit
4. End



Start
  |
  v
Initialize empty priority queue
  |
  v
Loop:
  |
  +--> Add Patient:
  |      Input name & severity
  |      Insert into queue based on severity (highest first)
  |
  +--> Treat Patient:
  |      If queue empty -> "No patients"
  |      Else -> remove patient with highest severity, display treated
  |
  +--> Display Queue:
  |      Print all patients from highest to lowest severity
  |
  +--> Exit
  |
  v
End
