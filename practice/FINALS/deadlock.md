```c
void *philosopher(void *_args) {
    /* Cast the args as struct with self identifier, semaphores */
    struct args *args = (struct args *)_args;
    int self = args->self;        /* unique thread identifier */
    int next = (self + 1) % SIZE; /* right neighbor's index */
    
    sem_wait(args->sems[self]);   /* pick up left fork */
    sem_wait(args->sems[next]);   /* pick up right fork */
    
    /* Critical section (eating) */
    
    sem_post(args->sems[next]);   /* put down right fork */
    sem_post(args->sems[self]);   /* put down left fork */
    
    /* Do other work and exit thread */
}
```
### This is solved by enforcing ordering on the philosophers 
```c
void *philosopher(void *_args) {
    /* Cast the args as struct with self identifier, semaphores */
    struct args *args = (struct args *)_args;
    int self = args->self;        /* unique thread identifier */
    int next = (self + 1) % SIZE; /* right neighbor's index */

    if (self > next) swap(&next, &self); /* enforce order */

    sem_wait(args->sems[self]);   /* pick up left fork */
    sem_wait(args->sems[next]);   /* pick up right fork */
    
    /* Critical section (eating) */
    
    sem_post(args->sems[next]);   /* put down right fork */
    sem_post(args->sems[self]);   /* put down left fork */
    
    /* Do other work and exit thread */
}
```
## Why the Original Approach Deadlocks (No Ordering)

**Scenario without ordering:**
1. All 5 philosophers try to eat at the same time
2. Each picks up their **left fork first**:
   - P0 takes F0
   - P1 takes F1
   - P2 takes F2
   - P3 takes F3
   - P4 takes F4
3. Then each tries to pick up their **right fork**:
   - P0 tries F1 (but P1 holds it)
   - P1 tries F2 (but P2 holds it)
   - P2 tries F3 (but P3 holds it)
   - P3 tries F4 (but P4 holds it)
   - P4 tries F0 (but P0 holds it)

**Result:** Everyone holds one fork and waits forever → **deadlock**

## Why Ordering Solves It

The ordering rule (`if (self > next) swap`) changes fork acquisition to follow one key principle:  
**Always pick up the lower-numbered fork first**

Let's see how this plays out:

### Key Changes:
- For philosophers 0-3: No change (left fork is already lower-numbered)
- For philosopher 4: Normally would take F4 then F0 → Now takes F0 first (since 4 > 0)

### Execution with Ordering:
1. **Initial fork pickup**:
   - P0 takes F0
   - P1 takes F1
   - P2 takes F2
   - P3 takes F3
   - P4 tries to take F0 first (not F4!) but **blocks** because P0 has F0

2. **Now only 4 philosophers hold forks**:
   - P0 has F0 (tries F1 next → blocks, since P1 has F1)
   - P1 has F1 (tries F2 next → blocks, since P2 has F2)
   - P2 has F2 (tries F3 next → blocks, since P3 has F3)
   - P3 has F3 → successfully takes F4 (no one was competing for F4!)
   - P4 is already blocked

3. **P3 can now eat** (has both F3 and F4)
   - After eating, P3 releases both forks
   - This allows P2 to get F3
   - Then P2 can eat, then P1, then P0
   - Finally P4 gets a turn

### Why This Works:
1. **Breaks the circle**: P4 can't participate in the deadlock because it's blocked early
2. **Guarantees progress**: At least one philosopher (P3) can always eat
3. **No starvation**: The chain of releases ensures everyone eventually eats

## Concrete Timeline Example

With ordering:
```
Time 0: P0 takes F0, P1 takes F1, P2 takes F2, P3 takes F3, P4 blocks on F0
Time 1: P3 takes F4 (eats)
Time 2: P3 releases F3,F4 → P2 can now take F3
Time 3: P2 takes F4 (eats)
Time 4: P2 releases F2,F3 → P1 takes F2
Time 5: P1 takes F3 (eats)
... and so on until P4 gets to eat
```

Without ordering:
```
Time 0: Everyone takes left fork
Time 1: Everyone tries right fork → all block forever
```

The ordering ensures there's always at least one philosopher who can make progress, breaking the deadlock cycle. This is why the solution works!
