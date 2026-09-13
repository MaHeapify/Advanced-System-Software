/*
    Write a program to create a child process. Display the process IDs of the process, parent and child 
    (if any) in both the parent and child processes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("Before forking (initial process)\n");
    printf("Initial process PID: %d\n\n", getpid());

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed!");
        exit(1);
    } else if (pid == 0) {
        // Child process block
        // Inside the child, fork() returns 0
        // It has no child of its own in this context
        printf("Inside child process.");
        printf("Current process PID: %D\n", getpid());
        printf("Parent process PPID: %d\n", getppid());
        printf("Child process ID: None (This is the child).");
    } else {
        // Parent process block
        // Inside the parent, fork() returns the PID of the newly created child
        printf("Inside parent process.");
        printf("Current process PID: %D\n", getpid());
        printf("Parent process PPID: %d\n", getppid());
        printf("Child process ID: %d", pid);

        // Wait for the child process to complete before exiting
        wait(NULL);
    }

    return 0;
}
