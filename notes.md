## Section 2

### Forks
How many new processes are created in the below program?

```c
int main(void) {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
    }
}
```
Answer: 3

### Stack Allocation

What can C print?

```c
int main(void) {
    int stuff = 7;
    pid_t pid = fork();
    printf("Stuff is %d\n", stuff);
    if (pid == 0)
        stuff = 6;
}
```
Answer: 

```
stuff is 7 // output by parent process
stuff is 7 // output by child process
```

### Heap Allocation

```c
int main(void) {
    int* stuff = malloc(sizeof(int)*1);
    *stuff = 7; // set content of that address as 7
    pid_t pid = fork();
    printf("Stuff is %d\n", *stuff);
    if (pid == 0)
        *stuff = 6
}
```
