/*
    Write a program to find the inode number of an existing file in a directory. Take the input as a filename and print the inode 
    number of the file.
*/

#include <stdio.h>
#include <sys/stat.h>

int main() {
    char fileName[100];

    // Struct stat stores the information about the file
    struct stat fileInfo;

    printf("\nEnter the file name to print it's inode number: ");
    scanf("%s", fileName);

    // Check if stat function succeeded or not
    if (stat(fileName, &fileInfo) == 0) {
        printf("\nInode number of %s: %lu\n", fileName, fileInfo.st_ino);
    } else {
        printf("\nError fetching file information!\n");
    }

    return 0;
}
