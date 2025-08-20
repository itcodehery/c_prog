#include <stdio.h>   
#include <ctype.h>   

#include "medical_constants.h"

#define AGE_CHILD_MAX 18
#define AGE_ADULT_MIN 19
#define AGE_SENIOR_MIN 60
#define MAX_SYMPTOMS_TO_RECORD 2
#define MAX_TOTAL_MEDICATION_DOSAGE 100.0

struct Patient {
    int patient_id;
    char patient_initial;
    float temperature;
    double bill_amount;
    char gender_char;
};

struct Patient global_patient;

void register_patient() {
    printf("\n--- Patient Registration Module ---\n");

    int patient_id;
    // printf("\n--- Data Types & Attributes Demonstration ---\n");
    printf("Enter Patient ID (e.g., 1001): ");
    scanf("%d", &patient_id);

    char patient_initial;
    printf("Enter Patient's First Name Initial (e.g., J): ");
    scanf(" %c", &patient_initial);

    float temperature;
    printf("Enter Patient's Body Temperature in Fahrenheit (e.g., 98.6): ");
    scanf("%f", &temperature);

    double bill_amount;
    printf("Enter Patient's Estimated Bill Amount (e.g., 13000.75): ");
    scanf("%lf", &bill_amount);

    char gender_char;
    printf("Enter Patient's Gender (M/F/O for Male/Female/Other): ");
    scanf(" %c", &gender_char);

    printf("\n--- Patient Details Entered ---\n");
    printf("Patient ID: %d\n", patient_id);
    printf("Patient Initial: %c\n", patient_initial);
    printf("Body Temperature: %.2f F\n", temperature);
    printf("Estimated Bill Amount: Rs.%.2f\n", bill_amount);
    printf("Gender: %c\n", gender_char);

    global_patient.patient_id = patient_id;
    global_patient.patient_initial = patient_initial;
    global_patient.temperature = temperature;
    global_patient.bill_amount = bill_amount;
    global_patient.gender_char = gender_char;

    // printf("\n--- Conditional Statements Demonstration ---\n");

    // printf("\n--- if-else: Temperature Check ---\n");
    if (temperature >= FEVER_TEMP_MIN) {
        printf("Alert: Patient has a fever (Temperature %.2f F is >= %.2f F).\n", temperature, FEVER_TEMP_MIN);
    } else {
        printf("Patient temperature (%.2f F) is normal.\n", temperature);
    }

    // printf("\n--- else-if ladder: Age Classification ---\n");
    int patient_age;
    printf("Enter Patient's Age: ");
    scanf("%d", &patient_age);

    if (patient_age <= AGE_CHILD_MAX) {
        printf("Patient is classified as a Child.\n");
    } else if (patient_age >= AGE_ADULT_MIN && patient_age < AGE_SENIOR_MIN) {
        printf("Patient is classified as an Adult.\n");
    } else if (patient_age >= AGE_SENIOR_MIN) {
        printf("Patient is classified as a Senior.\n");
    } else {
        printf("Age entered is invalid or negative.\n");
    }

    // printf("\n--- switch-case: Gender Processing ---\n");
    switch (tolower(gender_char)) {
        case 'm':
            printf("Patient gender recorded as Male.\n");
            break;
        case 'f':
            printf("Patient gender recorded as Female.\n");
            break;
        case 'o':
            printf("Patient gender recorded as Other.\n");
            break;
        default:
            printf("Invalid gender input. Please use M, F, or O.\n");
            break;
    }

    // printf("\n--- Looping Statements Demonstration ---\n");

    // printf("\n--- for loop: Recording Recent Symptoms ---\n");
    printf("Please enter up to %d recent symptoms (single word per symptom):\n", MAX_SYMPTOMS_TO_RECORD);
    char symptom[50];
    for (int i = 0; i < MAX_SYMPTOMS_TO_RECORD; i++) {
        printf("Symptom %d: ", i + 1);
        scanf("%49s", symptom);
        printf("Recorded: %s\n", symptom);
    }
    // printf("Finished recording symptoms.\n");

    // printf("\n--- while loop: Medication Dosage Accumulation ---\n");
    float current_total_dosage = 0.0;
    float dose_input;
    printf("Enter medication dosages (mg). Will stop when total reaches %.2f mg.\n", MAX_TOTAL_MEDICATION_DOSAGE);
    while (current_total_dosage < MAX_TOTAL_MEDICATION_DOSAGE) {
        printf("Enter next dose (mg, 0 to stop early): ");
        scanf("%f", &dose_input);
        if (dose_input <= 0) {
            printf("Stopping dosage input early.\n");
            break;
        }
        current_total_dosage += dose_input;
        printf("Current total dosage: %.2f mg (Target: %.2f mg)\n", current_total_dosage, MAX_TOTAL_MEDICATION_DOSAGE);
    }
    printf("Medication dosage target reached or stopped. Final total: %.2f mg.\n", current_total_dosage);

    // printf("\n--- do-while loop: Adding Patient Allergies ---\n");
    char add_another_allergy;
    char allergy[100];
    int allergy_count = 0;
    do {
        printf("Enter a known allergy (e.g., Penicillin, Peanuts): ");
        scanf("%99s", allergy);
        printf("Allergy recorded: %s\n", allergy);
        allergy_count++;

        printf("Do you want to add another allergy? (y/n): ");
        scanf(" %c", &add_another_allergy);
    } while (tolower(add_another_allergy) == 'y');
    printf("Finished adding allergies. Total allergies recorded: %d.\n", allergy_count);

    // printf("\n--- Patient Registration Complete ---\n");
    printf("Returning to Medical Domain Menu.\n");
}

void view_patient() {
    printf("\n-----------------");
    printf("\nPatient Details");
    printf("\n-----------------\n");
    printf("Patient ID: %d\n", global_patient.patient_id);
    printf("Patient Initial: %c\n", global_patient.patient_initial);
    printf("Body Temperature: %.2f F\n", global_patient.temperature);
    printf("Estimated Bill Amount: Rs.%.2f\n", global_patient.bill_amount);
    printf("Gender: %c\n", global_patient.gender_char);
    return;
}