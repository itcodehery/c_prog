#include<stdio.h>
#define MEDICAL_ALLOWANCE 25000

struct Employee {
	char name[50];
	int age;
	char designation[30];
	float basic_pay;	
};

float getHRA(float basic_pay) {
	return (basic_pay * 25) / 100;
}

float getDA(float basic_pay) {
	return (basic_pay * 30) / 100;
}

float getTravelAllowance(float basic_pay) {
	if (basic_pay >= 100000) {
		return (basic_pay * 3) / 100;
	}
	return (basic_pay * 5) / 100;
}

float computeGrossPay(float basic_pay) {
	return basic_pay + getHRA(basic_pay) + getDA(basic_pay) + getTravelAllowance(basic_pay) + MEDICAL_ALLOWANCE;
}

int main() {
	struct Employee emps[10];
	struct Employee disp;
	FILE *fptr;

	printf("\nEnter the details of Employees\n-----------\n");
	for (int i = 0 ; i < 10 ; i++) {
		printf("\nName of employee %d: ",i + 1);
		scanf("%s",emps[i].name);
		printf("\nAge of employee %d: ",i + 1);
		scanf("%d",&emps[i].age);
		printf("\nDesignation of Employee %d: ",i + 1);
		scanf("%s",emps[i].designation);
		printf("\nBasic Pay: ");
		scanf("%f",&emps[i].basic_pay);
	}
	
	// Writing into file in binary
	fptr = fopen("employee.dat","wb");
	if (fptr == NULL) {
		printf("Error opening file!");
		return 0;
	}
	fwrite(emps,sizeof(struct Employee),10,fptr);
	fclose(fptr);

	// Reading from binary
	fptr = fopen("employee.dat","rb");
	if (fptr == NULL) {
		printf("Error opening file!");
		return 0;
	}
	for (int i = 0 ; i < 10 ; i++) {
		fread(&disp,sizeof(struct Employee),1,fptr);
		printf("\n-------------");
		printf("\nEmployee %d:",i + 1);
		printf("\nName: %s",disp.name);
		printf("\nAge: %d",disp.age);
		printf("\nDesignation: %s",disp.designation);
		printf("\nBasic Pay: %.2f",disp.basic_pay);
		printf("\nHRA(25per): %.2f",getHRA(disp.basic_pay));
		printf("\nDA(30per): %.2f",getDA(disp.basic_pay));
		printf("\nTravelling Allowance(5per if > 1L else 3per): %.2f",getTravelAllowance(disp.basic_pay));
		printf("\nMedical Allowance(fixed): %d", MEDICAL_ALLOWANCE);
		printf("\nGross Pay: %.2f", computeGrossPay(disp.basic_pay));
	}
	return 0;
}
