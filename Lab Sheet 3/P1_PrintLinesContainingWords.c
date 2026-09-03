/*
	Write a program to print the lines of a file that contain a word given as the program argument 
	(a simple version of grep UNIX utility).
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *file;
	char line[500];
	
	if (argc != 3) {
		printf("\nUsage: %s <word> <filename>\n", argv[0]);
		return 1;
	}
	
	file = fopen(argv[2], "r");
	
	if (file == NULL) {
		printf("\nUnable to open the file.\n");
		return 1;
	}

	while (fgets(line, sizeof(line), file) != NULL) {
		if (strstr(line, argv[1]) != NULL) {
			printf("%s", line);
		}
	}
	
	fclose(file);
    
	return 0;
}
