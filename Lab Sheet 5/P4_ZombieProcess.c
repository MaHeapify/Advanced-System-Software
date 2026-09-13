/*
    Create a zombie (defunct) child process (a child with exit() call, but no corresponding wait() 
    in the sleeping parent) and allow the init process to adopt it (after parent terminates). Run the process as a background 
    process and run the "ps" command.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("\nFork failed!");
        exit(1);
    } else if (pid  == 0) {
        // Child process
        printf("\n[Child] PID: %d, Parent PID: %d -> Exiting immediately to become a zombie.", getpid(), getppid());
        exit(0);
    } else {
        // Parent process
        printf("\n[Parent] PID: %d -> Sleeping for 15 seconds. Check 'ps' now.", getpid());
        sleep(15);

        printf("\n[Parent] PID: %d -> Terminating without calling wait().", getpid());
        exit(0);
    }

    return 0;
}
