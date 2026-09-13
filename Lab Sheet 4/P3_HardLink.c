/*
    Write a program to create a new hard link to an existing file and unlink the same. 
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

    // Create hard link
    if (link(inputFilePath, newFilePath) == -1) {
        perror("Link error!");
        return 1;
    }

    printf("\nNew hard link path: %s\n", newFilePath);

    // Unlink the hard link
    if (unlink(newFilePath) == -1) {
        perror("Unlink error!");
        return 1;
    }

    printf("\nHard link successfully unlinked.\n");

    return 0;
}
