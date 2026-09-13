/*
    Write a C program to load the binary executable of the previous program in a child process 
    using the exec system call.
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    printf("\nMain runner program started.\n");
    pid = fork();

    switch (pid) {
        case -1:
            perror("\nFork failed.");
            exit(1);

        case 0:
            // Child process branch
            printf("\nChild process: My PID is %d. Overwriting myself with fork_program.\n", getpid());

            /*
                execl() parameters:
                1. Path to binary ("./fork_program")
                2. Argument 0 (Conventionally the program name: "fork_program")
                3. NULL (Terminator to signal the end of argument arrays)
            */
           execl("./P1_WaitSystemCall", "fork_program", NULL);

           // If execl() succeeds, the code below is never executed because the child's memory is overwritten.
           perror("\nexecl failed.");
           exit(1);

        default:
            // Parent process branch
            printf("\nParent process: Waiting for the child (which is now running fork_program) to finish.\n");
            wait(NULL);
            printf("\nParent process: Child finished. Main runner program exiting.\n");
            break;
    }

    return 0;
}
