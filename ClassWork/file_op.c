#include<stdio.h>

int main() {
	FILE *ptr;
	ptr = fopen("t2.txt","w");
	if (ptr == NULL) {
		printf("\nUnable to open file!");
		return 0;
	}
	fprintf(ptr, "Welcome to a brand new C file!");
	fclose(ptr);

	ptr = fopen("t2.txt","r");
	char string[50];
	while (fscanf(ptr,"%s",string) != EOF) {
		printf("%s ",string);
	}
	// fputs(string,ptr);
	// printf("%s",string);	
	return 0;
}
