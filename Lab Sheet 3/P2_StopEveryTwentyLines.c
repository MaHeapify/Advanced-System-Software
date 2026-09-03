/*
	Write a program to list the files given as arguments, stopping every 20 lines until a key is hit 
	(a simple version of more UNIX utility).
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *file;
	char line[500];
	int count;
	int choice;

	if (argc < 2) {
		printf("\nUsage: %s <filename1> [filename2...]\n", argv[0]);
		return 1;
	}

	for (int i = 1; i < argc; i++) {
		file = fopen(argv[i], "r");

		if (file == NULL) {
			printf("\nUnable to open %s\n", argv[i]);
			continue;
		}

		printf("\nFile: %s \n", argv[i]);

		count = 0;
		
		while (fgets(line, sizeof(line), file) != NULL) {
			printf("%s", line);
			count++;
			
			if (count == 20) {
				printf("\nPress Enter to continue or q to quit: ");
				choice = getchar();

				if (choice == 'q' || choice == 'Q') {
					fclose(file);
					return 0;
				}
				
				if (choice != '\n') {
					while (getchar() != '\n') {
						// Remove remaining input characters
					}
				}
		
				count = 0;
			}
		}

		fclose(file);
	}

	return 0;
}
