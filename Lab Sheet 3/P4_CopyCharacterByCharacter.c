// Write a program to copy character by character. Copy is accomplished using calls to the functions referenced in stdio.h.

#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *source;
    FILE *destination;
    int character;
 
    if (argc != 3) {
        printf("\nUsage: %s <source-file> <destination-file>\n", argv[0]);
        return 1;
    }
 
    source = fopen(argv[1], "r");
 
    if (source == NULL) {
        printf("\nUnable to open the source file.\n");
        return 1;
    }
 
    destination = fopen(argv[2], "w");
 
    if (destination == NULL) {
        printf("\nUnable to create the destination file.\n");
        fclose(source);
        return 1;
    }
 
    while ((character = fgetc(source)) != EOF) {
        fputc(character, destination);
    }
 
    fclose(source);
    fclose(destination);
 
    printf("\nFile copied successfully.\n");
 
    return 0;
}
