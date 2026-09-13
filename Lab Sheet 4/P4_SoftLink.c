/*
    Write a program to create a new soft link to an existing file and unlink the same. 
    Accept the old path as input and print the new path.
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    char inputFilePath[500];
    char newFilePath[500] = "/home/maheapify/contents";
    int ret;

    printf("\nEnter the old input file path: ");
    scanf("%s", inputFilePath);

    // Create soft link
    if (symlink(inputFilePath, newFilePath) == -1) {
        perror("Symlink error!");
        return 1;
    }

    printf("\nNew soft link path: %s\n", newFilePath);

    // Unlink the soft link
    if (unlink(newFilePath) == -1) {
        perror("Unlink error!");
        return 1;
    }

    printf("\nSoft link successfully unlinked.\n");

    return 0;
}
