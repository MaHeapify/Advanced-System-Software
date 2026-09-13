/*
    Write a C program to block a parent process until the child completes 
    using a wait() system call.
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    printf("\nFork program starting.\n");

    // Perform a fork system call
    pid = fork();

    switch (pid) {
        case -1:
            // Fork system call failed
            perror("\nFork failed!");
            exit(1);
        
        case 0:
            // Executed by the child process
            printf("\nThis is the child process.");
            break;
        
        default:
            // Executed by the parent process
            /*
                The parent immediately calls wait(NULL).
                This blocks the parent and forces it to sleep until 
                the child process terminates completely.    
            */
           printf("\nParent process is waiting for the child to finish.\n");
           wait(NULL);

           break;
    }

    return 0;
}
