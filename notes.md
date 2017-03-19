## Section 2

### 3.1 Forks
How many new processes are created in the below program?

```c
int main(void) {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
    }
}
```
Answer: 3

### 3.2 Stack Allocation

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

### 3.3 Heap Allocation

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

Answer: 
```
stuff is 7 // output by parent process
stuff is 7 // output by child process
```

### 3.4 Slightly More Complex Heap Allocation
what does C print in this case?


```c
void printTenNumbers(int *arr) {
    int i;
    printf("\n");
    for(i = 0; i < 10; i++) {
        printf("arr %d is %d\n",  i, arr[i]);
    }
    exit(0);
}

int main() {
    int *arr, i;
    arr = (int *) malloc (sizeof(int));

    arr[0] = 0;
    for(i = 1; i < 10; i++) {
        arr = (int *) realloc( arr, (i + 1) * sizeof(int));
        arr[i] = i;
        if (i == 7) {
            pid_t pid = fork();
            if (pid == 0) {
                printTenNumbers(arr);
            }
        }
    }

}
```

output is 

```
arr 0 is 0
arr 1 is 1
arr 2 is 2
arr 3 is 3
arr 4 is 4
arr 5 is 5
arr 6 is 6
arr 7 is 7
arr 8 is 0
arr 9 is -1342177280
```

### 3.5 Simple Wait

What can C print? Assume the child PID is 90210
```c

int main(void) {
    pid_t pid = fork();
    int exit;
    // if (pid != 0) {
    //     wait(&exit);
    // }
    printf("Hello world\n: %d\n", pid);
}

// output
// Hello world
// : 31970
// Hello world
// : 0

int main(void) {
    pid_t pid = fork();
    int exit;
    if (pid != 0) {
        wait(&exit);
    }
    printf("Hello world\n: %d\n", pid);
}

// output
// Hello world
// : 0
// Hello world
// : 31928
```
and equivalent `waitpid` is 

```c
int main(void) {
    pid_t pid = fork();
    int exit;
    if (pid > 0) {
        waitpid(pid, &exit, 0);
    }
    printf("Hello world\n: %d\n", pid);
}
```

## Questions
- [cast the result of malloc](http://stackoverflow.com/questions/605845/do-i-cast-the-result-of-malloc)
- [why is not fork bomb](http://stackoverflow.com/questions/13635854/why-doesnt-this-cause-a-fork-bomb)
- [The wait system call](http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/wait.html)
- [Notes on wait & waitpid](https://webdocs.cs.ualberta.ca/~tony/C379/C379Labs/Lab3/wait.html)
