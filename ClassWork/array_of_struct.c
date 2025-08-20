#include<stdio.h>

struct Student
{
	char name[30];
	int m1,m2,m3;
};

int main() {
	struct Student st[5],stud;
	FILE *fptr;
	for (int i = 0 ; i < 5 ; i++) {
		printf("\nEnter the info for Student %d:",i + 1);
		printf("\nName: ");
		scanf("%s",st[i].name);
		printf("\nEnter the marks in subject 1:");
		scanf("%d",&st[i].m1);
		printf("\nEnter the marks in subject 2:");
		scanf("%d",&st[i].m2);
		printf("\nEnter the marks in subject 3:");
		scanf("%d",&st[i].m3);
	}

	// Opening for binary write
	fptr = fopen("test.dat", "wb");
	if (fptr == NULL) {
		printf("Error opening file...");
	}

	// fwrite for writing directly as binary
	fwrite(st,sizeof(struct Student),5,fptr);
	fclose(fptr);

	/// The below code can technically be run
	/// on another file.
	// Opening for binary read
	fptr = fopen("test.dat","rb");
	if (fptr == NULL) {
		printf("Error opening file.");
	}

	// fread for reading directly from binary
	for (int i = 0 ; i < 5 ; i++)
	{
		fread(&stud, sizeof(struct Student),1,fptr);
		printf("\nStudent %d: ",i + 1);
		printf("\n%s -> %d %d %d", stud.name, stud.m1, stud.m2, stud.m3);
	}
	
	return 0;
}
