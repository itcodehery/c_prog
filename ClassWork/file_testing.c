#include<stdio.h>

int main() {
  FILE *fptr;
  char student_name[40];
  int mark_1,mark_2,mark_3, sum = 0;
  
  fptr = fopen("test.txt","w");
  if (fptr == NULL) {
    printf("File error!");
  }
  fprintf(fptr, "This is another file in C");
  fclose(fptr);
  fptr = fopen("test.txt","a");
  fprintf(fptr, " \n");
  for (int i = 0; i < 3 ; i++) {
    printf("Enter the name of the student: ");
    scanf("%s",student_name);
    printf("Enter marks 1: ");
    scanf("%d",&mark_1);
    printf("Enter mark 2: ");
    scanf("%d", &mark_2);
    printf("Enter mark 3: ");
    scanf("%d",&mark_3);
    sum = mark_1 + mark_2 + mark_3;
    fprintf(fptr, "%s %d %d %d Sum:%d\n", student_name,mark_1, mark_2, mark_3, sum);
  }
  fclose(fptr);

  fptr = fopen("test.txt", "r");
  char content[50];
  while (fscanf(fptr, "%s", content) != EOF) {
    printf("%s ",content);
  }
  return 0;
}
