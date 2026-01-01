#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int pid;
    int bt; // burst time
    struct Process* next;
} Process;

// Add process to circular linked list
void addProcess(Process** head, Process** tail, int pid, int bt) {
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->pid = pid;
    newProcess->bt = bt;
    if (*head == NULL) {
        *head = *tail = newProcess;
        newProcess->next = *head;
    } else {
        (*tail)->next = newProcess;
        newProcess->next = *head;
        *tail = newProcess;
    }
}

// Round-robin scheduling
void roundRobin(Process** head, int tq) {
    if (*head == NULL) return;
    Process *temp = *head, *prev = NULL;
    printf("\nRound-Robin Execution:\n");
    while (*head) {
        // If only one node remains
        if (temp->next == temp) {
            if (temp->bt <= tq)
                printf("Process %d executed fully (Burst %d)\n", temp->pid, temp->bt);
            else
                printf("Process %d executed partially (Burst left %d)\n", temp->pid, temp->bt - tq);
            free(temp);
            *head = NULL;
            break;
        }

        if (temp->bt <= tq) {
            printf("Process %d executed fully (Burst %d)\n", temp->pid, temp->bt);
            // Remove temp
            Process* toDelete = temp;
            // Find previous node
            prev = temp;
            while (prev->next != temp) prev = prev->next;
            prev->next = temp->next;
            if (temp == *head) *head = temp->next;
            temp = temp->next;
            free(toDelete);
        } else {
            temp->bt -= tq;
            printf("Process %d executed partially, remaining burst = %d\n", temp->pid, temp->bt);
            temp = temp->next;
        }
    }
}

int main() {
    Process *head = NULL, *tail = NULL;
    int n, i, pid, bt, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Process ID: ");
        scanf("%d", &pid);
        printf("Enter Burst Time: ");
        scanf("%d", &bt);
        addProcess(&head, &tail, pid, bt);
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    roundRobin(&head, tq);

    return 0;
}




1. Start
2. Create a circular linked list node structure with:
       - Process ID (pid)
       - Burst time
       - Pointer to next node
3. Initialize head and tail as NULL
4. Input number of processes (n)
5. For each process:
       - Input process ID and burst time
       - Create node and add at end
       - Link last node to head to form circular list
6. Input time quantum (tq)
7. Traverse circular list in round-robin manner:
       - For each process:
           - If burst time <= tq, execute and remove process
           - Else, reduce burst time by tq
           - Move to next process
       - Repeat until all processes complete
8. End




Start
  |
  v
Create circular linked list node (pid, burst time, next)
  |
  v
Input number of processes n
  |
  v
For i = 1 to n:
   Input pid, burst time
   Add node to circular list
Link last node to head
  |
  v
Input Time Quantum tq
  |
  v
While circular list not empty:
   For each process:
       If burst time <= tq:
           Execute fully, remove process
       Else:
           Execute for tq, reduce burst time
       Move to next process
  |
  v
End
