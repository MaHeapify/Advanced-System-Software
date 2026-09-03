// Demonstrate the use of different conversion specifiers and resulting output to allow the items to be printed.

#include <stdio.h>

int main() {
	int number = 25;
	unsigned int positive = 50;
	float price = 45.75f;
	double pi = 3.14159265;
	char grade = 'A';
	char name[] = "Manipal";
	
	printf("\nInteger using %%d: %d\n", number);
	printf("Integer using %%i: %i\n", number);
	printf("Unsigned integer using %%u: %u\n", positive);
	printf("Float using %%f: %f\n", price);
	printf("Float with two decimals using %%.2f: %.2f\n", price);
	printf("Double using %%lf: %lf\n", pi);
	printf("Character using %%c: %c\n", grade);
	printf("String using %%s: %s\n", name);
	printf("Octal using %%o: %o\n", number);
	printf("Hexadecimal using %%x: %x\n", number);
	printf("Scientific notation using %%e: %e\n", pi);
	printf("Percentage symbol using %%%%: %%\n");
	
	return 0;
}
