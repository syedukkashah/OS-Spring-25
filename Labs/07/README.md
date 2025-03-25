*OS Lab 7*

### Task 1: Process Scheduling Analysis

| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |
|---------|-------------|------------|----------------|----------------|--------------|
| P1      | 0           | 6          | 6              | 6              | 0            |
| P2      | 2           | 8          | 14             | 12             | 4            |
| P3      | 4           | 7          | 21             | 17             | 10           |
| P4      | 6           | 3          | 24             | 18             | 15           |

- *Average Waiting Time:* (0 + 4 + 10 + 15) / 4 = 7.25
- *Average Turnaround Time:* (6 + 12 + 17 + 18) / 4 = 13.25

### Task 2: Another Scheduling Approach

| Process | Arrival Time | Burst Time | Execution Order | Completion Time | Turnaround Time | Waiting Time |
|---------|-------------|------------|----------------|----------------|----------------|--------------|
| P1      | 1           | 5          | P1             | 6              | 5              | 0            |
| P2      | 3           | 2          | P2             | 8              | 5              | 3            |
| P3      | 5           | 9          | P4             | 12             | 6              | 2            |
| P4      | 6           | 4          | P3             | 21             | 16             | 7            |

- *Average Waiting Time:* (0 + 3 + 2 + 7) / 4 = 3
- *Average Turnaround Time:* (5 + 5 + 6 + 16) / 4 = 8

### Task 3: Gantt Chart Representation

#### Time and Process Execution
| Time Interval | Running Process |
|--------------|----------------|
| 0 - 1        | P1             |
| 1 - 3        | P2             |
| 3 - 5        | P4             |
| 5 - 7        | P2             |
| 7 - 14       | P3             |
| 14 - 18      | P1             |

*Summary of Process Completion*

| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |
|---------|-------------|------------|----------------|----------------|--------------|
| P1      | 0           | 9          | 18             | 18             | 9            |
| P2      | 1           | 4          | 7              | 6              | 2            |
| P3      | 2           | 7          | 14             | 12             | 5            |
| P4      | 3           | 2          | 5              | 2              | 0            |

- *Average Waiting Time:* (9 + 2 + 5 + 0) / 4 = 4
- *Average Turnaround Time:* (18 + 6 + 12 + 2) / 4 = 9.5

## Task 4

### Gantt Chart
| P1  | P2  | P3  | P4  | P1  | P2  | P3  | P1  | P3  | P1  |
|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|
| 0   | 3   | 6   | 9   | 12  | 15  | 17  | 20  | 23  | 25  | 26  |

### Process Details
| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |
|---------|-------------|------------|----------------|----------------|--------------|
| P1      | 0           | 10         | 26             | 26 - 0 = 26    | 26 - 10 = 16 |
| P2      | 1           | 5          | 17             | 17 - 1 = 16    | 16 - 5 = 11  |
| P3      | 2           | 8          | 25             | 25 - 2 = 23    | 23 - 8 = 15  |
| P4      | 3           | 3          | 12             | 12 - 3 = 9     | 9 - 3 = 6    |

- *Average Waiting Time:* (16 + 11 + 15 + 6) / 4 = *12*
- *Average Turnaround Time:* (26 + 16 + 23 + 9) / 4 = *18.5*

---

## Task 5

### Gantt Chart
| P1  | P2  | P3  | P4  | P1  | P2  | P3  | P4  | P1  | P2  | P3  | P1  | P3  | P1  | P1  |
|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|-----|
| 0   | 2   | 4   | 6   | 8   | 10  | 12  | 14  | 16  | 18  | 20  | 22  | 24  | 26  | 28  | 30 |

### Process Details
| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time |
|---------|-------------|------------|----------------|----------------|--------------|
| P1      | 0           | 12         | 30             | 30 - 0 = 30    | 30 - 12 = 18 |
| P2      | 2           | 6          | 20             | 20 - 2 = 18    | 18 - 6 = 12  |
| P3      | 4           | 8          | 26             | 26 - 4 = 22    | 22 - 8 = 14  |
| P4      | 6           | 4          | 16             | 16 - 6 = 10    | 10 - 4 = 6   |

- *Average Waiting Time:* (18 + 12 + 14 + 6) / 4 = *12.5*
- *Average Turnaround Time:* (30 + 18 + 22 + 10) / 4 = *20*

## Task 6

### Gantt Chart
| P1  | P2  | P3  | P4  |
|-----|-----|-----|-----|
| 0   | 7   | 11  | 17  | 22 |

### Process Details
| Process | Arrival Time | Burst Time | Priority/Queue | Completion Time | Turnaround Time | Waiting Time |
|---------|-------------|------------|---------------|----------------|----------------|--------------|
| P1      | 0           | 7          | 3             | 7              | 7 - 0 = 7      | 7 - 7 = 0    |
| P2      | 1           | 4          | 1             | 11             | 11 - 1 = 10    | 10 - 4 = 6   |
| P3      | 2           | 6          | 2             | 17             | 17 - 2 = 15    | 15 - 6 = 9   |
| P4      | 3           | 5          | 4             | 22             | 22 - 3 = 19    | 19 - 5 = 14  |

- *Average Waiting Time:* (0 + 6 + 9 + 14) / 4 = *7.25*
- *Average Turnaround Time:* (7 + 10 + 15 + 19) / 4 = *12.75*

---

## Task 7

### Gantt Chart
| P1  | P2  | P1  | P3  |
|-----|-----|-----|-----|
| 0   | 1   | 4   | 8   | 13 |

### Process Details
| Process | Arrival Time | Burst Time | Priority/Queue | Completion Time | Turnaround Time | Waiting Time |
|---------|-------------|------------|---------------|----------------|----------------|--------------|
| P1      | 0           | 8          | 2             | 8              | 8 - 0 = 8      | 8 - 8 = 0    |
| P2      | 1           | 3          | 1             | 4              | 4 - 1 = 3      | 3 - 3 = 0    |
| P3      | 2           | 5          | 3             | 13             | 13 - 2 = 11    | 11 - 5 = 6   |

- *Average Waiting Time:* (0 + 0 + 6) / 3 = *2*
- *Average Turnaround Time:* (8 + 3 + 11) / 3 = *7.33*
