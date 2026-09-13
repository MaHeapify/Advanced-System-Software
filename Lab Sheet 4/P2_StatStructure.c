//  Write a program to print out the complete stat structure of the file.

#include <stdio.h>
#include <sys/stat.h>

// Display the complete file stat structure
void displayFileStatStructure(char fileName[], struct stat fileStatStructure) {
    printf("\nStat Structure (%s)", fileName);

    // Display the device ID containing the file
    printf("\nDevice ID: %ld", (long)fileStatStructure.st_dev);

    // Display inode number
    printf("\nInode number: %ld", (long)fileStatStructure.st_ino);

    // Display permissions
    printf("\nPermissions: %o", fileStatStructure.st_mode);

    // Display number of hard links
    printf("\nNumber of hard links: %ld", (long)fileStatStructure.st_nlink);

    // Display owner user ID
    printf("\nOwner user ID: %d", fileStatStructure.st_uid);

    // Display owner group ID
    printf("\nOwner group ID: %d", fileStatStructure.st_gid);

    // Display device ID (if special file)
    printf("\nDevice ID (if special file): %ld", (long)fileStatStructure.st_rdev);

    // Display total size
    printf("\nTotal size: %ld", (long)fileStatStructure.st_size);

    // Display block size
    printf("\nBlock size: %ld", (long)fileStatStructure.st_blksize);

    // Display number of blocks allocated
    printf("\nNumber of blocks: %ld\n", (long)fileStatStructure.st_blocks);
}

int main() {
    char fileName[100];

    struct stat fileStatStructure;

    printf("\nEnter the file name to print it's entire stat structure: ");
    scanf("%s", fileName);

    // Check if stat function succeeded or not
    if (stat(fileName, &fileStatStructure) == 0) {
        displayFileStatStructure(fileName, fileStatStructure);
    } else {
        printf("\nError fetching file information!\n");
    }

    return 0;
}
