# Round Robin CPU Scheduling Algorithm

This program implements the Round Robin CPU scheduling algorithm using a circular linked list data structure in C.

## Approach

1. **Process Node Structure**: Each process is represented by a node in the circular linked list. Each node contains information such as the process name, total execution time, remaining execution time, and a pointer to the next node.

2. **Insertion of Processes**: When a new process is inserted, a new node is created and added to the circular linked list. The process name is assigned alphabetically starting from 'A'. If it's the first process, it becomes the head of the list; otherwise, it's inserted at the end of the list.

3. **Round Robin Scheduling**: The main function `roundRobin` performs the Round Robin scheduling. It iterates through the circular linked list repeatedly until all processes are completed. Each process is given a fixed time quantum for execution. If a process's remaining execution time is greater than the quantum, it runs for the quantum time and then yields the CPU. If the remaining time is less than or equal to the quantum, it completes its execution.

4. **Deletion of Completed Processes**: Completed processes are removed from the list as they finish execution.

## Test Case

**Input:**
``` bash
Enter the number of processes: 3
Enter the time quantum: 5
Enter the execution time for each process:
10 15 8
```
Output
```bash
Process completion order:
A 5
B 10
C 15
A 20
B 25
C 28
```
