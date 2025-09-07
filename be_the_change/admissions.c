#include <stdio.h>
#include <stdlib.h>
#define COUNT 4
// Publish a merit list
typedef struct {
  int rollNo;
  char name[20];
  float pcm_total;
} Applicant;

int big_score(const void *a, const void *b) {
  const Applicant *applicantA = (const Applicant *)a;
  const Applicant *applicantB = (const Applicant *)b;

  if (applicantB->pcm_total > applicantA->pcm_total) {
    return 1;
  } else if (applicantB->pcm_total < applicantA->pcm_total) {
    return -1;
  } else {
    return 0;
  }
}

void sort_by_score(Applicant *apls) {
  qsort(apls, COUNT, sizeof(Applicant), big_score);
}

int main() {
  Applicant apls[COUNT];
  Applicant display;
  FILE *fptr;
  printf("\nEnter the details of %d Applicants---------\n", COUNT);
  for (int i = 0; i < COUNT; i++) {
    printf("\nName of Applicant %d: ", i + 1);
    scanf("%s", apls[i].name);
    printf("\nPCM total of Applicant %d:", i + 1);
    scanf("%f", &apls[i].pcm_total);
    apls[i].rollNo = i + 1;
  }

  // File write
  fptr = fopen("applicants.dat", "wb");
  if (fptr == NULL) {
    printf("Error opening file!");
    return 0;
  }
  fwrite(apls, sizeof(Applicant), COUNT, fptr);
  fclose(fptr);

  // File read from binary
  fptr = fopen("applicants.dat", "rb");
  if (fptr == NULL) {
    printf("Error opening file!");
    return 0;
  }
  for (int i = 0; i < COUNT; i++) {
    fread(&display, sizeof(Applicant), 1, fptr);
    printf("\n----------------");
    printf("\nApplicant Roll No: %d", display.rollNo);
    printf("\nApplicant Name: %s", display.name);
    printf("\nApplicant PCM Final: %.2f", display.pcm_total);
  }

  printf("\n----SORTING BY DESC----");
  fread(&apls, sizeof(Applicant), 4, fptr);
  sort_by_score(apls);
  printf("\nPrinting by Descending Order:");
  for (int i = 0; i < COUNT; i++) {
    printf("\n-----------------");
    printf("\nRoll: %d", apls[i].rollNo);
    printf("\nName: %s", apls[i].name);
    printf("\nMarks: %.2f", apls[i].pcm_total);
  }
  return 0;
}
