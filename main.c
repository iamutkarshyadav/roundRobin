#include <stdio.h>
#include <stdlib.h>

struct Node {
    char name; 
    int total_time; 
    int remaining_time; 
    struct Node* next;
};

struct Node* Head = NULL;
int process_count = 0;

void insertProcess(int execution_time);
void deleteProcess(char processName);
void roundRobin(int quantum);
void insertProcess(int execution_time) {
    struct Node* newProcess = (struct Node*)malloc(sizeof(struct Node));
    newProcess->name = 'A' + process_count;
    newProcess->total_time = execution_time;
    newProcess->remaining_time = execution_time;
    process_count++;

    if (Head == NULL) {
        Head = newProcess;
        Head->next = Head;
    } else {
        struct Node* temp = Head;
        while (temp->next != Head)
            temp = temp->next;
        newProcess->next = temp->next;
        temp->next = newProcess;
    }
}
void deleteProcess(char processName) {
    struct Node* prev = NULL;
    struct Node* temp = Head;

    if (Head->name == processName) {
        while (temp->next != Head)
            temp = temp->next;
        prev = Head;
        temp->next = Head->next;
        Head = Head->next;
        free(prev);
    } else {
        while (temp->next != Head && temp->name != processName) {
            prev = temp;
            temp = temp->next;
        }
        if (temp->name == processName) {
            prev->next = temp->next;
            free(temp);
        }
    }
}
void roundRobin(int quantum) {
    struct Node* current = Head;
    int clock = 0;
    while (Head != NULL) {
        if (current->remaining_time > quantum) {
            current->remaining_time -= quantum;
            clock += quantum;
        } else {
            clock += current->remaining_time;
            printf("%c %d\n", current->name, clock);
            struct Node* temp = current;
            current = current->next;
            deleteProcess(temp->name);
        }
        if (Head != NULL)
            current = current->next;
    }
}

int main() {
    int n, quantum, execution_time;
    printf("Enter the number of processes: ");
    if (scanf("%d", &n) != 1) {
        printf("\nInput interrupted.\n");
        return 1;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    printf("Enter the execution time for each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &execution_time);
        insertProcess(execution_time);
    }

    printf("Process completion order:\n");
    roundRobin(quantum);

    return 0;
}
