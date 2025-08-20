#include<stdio.h>
#include<stdlib.h>
#include "medical_constants.h"
#include "medical_functions.h"
#include "banking_functions.h"
#include "banking_constants.h"

const char* MEDICAL_OPTIONS[] = {"\n1. Register a Patient","2. View Patients","3. Exit",};
    const char* BANKING_OPTIONS[] = {"\n1. Open Account","2. View Account","3. View Balance","4. Exit"};
    const char* EDUCATION_OPTIONS[] = {"\n1. Register Ward and Marks","2. View Ward", "3."};

int medical_list(int num_medical_options) {
    int choice = 0;
    printf("\n----------------");
            
        for(int i = 0; i < num_medical_options ; i++){
            printf("\n%s",MEDICAL_OPTIONS[i]);
        }
        
       while (choice < 4 && choice >= 0) {
        printf("\nEnter your choice:");
        scanf("%d",&choice);
         switch (choice) {
            case 1: register_patient();
            break;

            case 2: view_patient();
            break;

            default: return 0; 
        }
       }
       return 0;
}

// const char* BANKING_OPTIONS[] = {"\n1. Open Account","2. View Account","3. View Balance","4. Exit"};

int banking_list(int num_banking_options) {
    int choice = 0;
    printf("\n----------------");
                
        for(int i = 0; i < num_banking_options ; i++){
            printf("\n%s",BANKING_OPTIONS[i]);
        }
        
        while (choice < 5 && choice >= 0) { // Max choice is 4 (Exit), so loop while choice is valid
            printf("\nEnter your choice:");
            scanf("%d",&choice);
            switch (choice) {
                case 1: // open_account(); // Uncomment and define this function
                open_account();
                break;

                case 2: view_account(); // Uncomment and define this function
                // printf("\nViewing account details...");
                break;

                case 3: view_balance(); // Uncomment and define this function
                break;
                
                case 4: return 0; // Exit option
                
                default: printf("\nInvalid choice. Please try again."); // Handle invalid input
            }
        }
        return 0;
}

// const char* EDUCATION_OPTIONS[] = {"\n1. Register Ward and Marks","2. View Ward", "3. Exit"};

int education_list(int num_education_options) {
    int choice = 0;
    printf("\n----------------");
                
        for(int i = 0; i < num_education_options ; i++){
            printf("\n%s",EDUCATION_OPTIONS[i]);
        }
        
        while (choice < 4 && choice >= 0) { // Max choice is 3 (Exit)
            printf("\nEnter your choice:");
            scanf("%d",&choice);
            switch (choice) {
                case 1: // register_ward_and_marks(); // Uncomment and define this function
                printf("\nRegistering ward and marks...");
                break;

                case 2: // view_ward(); // Uncomment and define this function
                printf("\nViewing ward details...");
                break;

                case 3: return 0; // Exit option
                
                default: printf("\nInvalid choice. Please try again."); // Handle invalid input
            }
        }
        return 0;
}

const char* GAMING_OPTIONS[] = {"\n1. Start New Game","2. View High Scores", "3. Exit"};

int gaming_list(int num_gaming_options) {
    int choice = 0;
    printf("\n----------------");
                
        for(int i = 0; i < num_gaming_options ; i++){
            printf("\n%s",GAMING_OPTIONS[i]);
        }
        
        while (choice < 4 && choice >= 0) { // Max choice is 3 (Exit)
            printf("\nEnter your choice:");
            scanf("%d",&choice);
            switch (choice) {
                case 1: // start_new_game(); // Uncomment and define this function
                printf("\nStarting a new game...");
                break;

                case 2: // view_high_scores(); // Uncomment and define this function
                printf("\nViewing high scores...");
                break;

                case 3: return 0; // Exit option
                
                default: printf("\nInvalid choice. Please try again."); // Handle invalid input
            }
        }
        return 0;
}

void generate_list(int option) {
    int num_medical_options = sizeof(MEDICAL_OPTIONS) / sizeof(MEDICAL_OPTIONS[0]);
    int num_banking_options = sizeof(BANKING_OPTIONS) / sizeof(BANKING_OPTIONS[0]);
    int num_education_options = sizeof(EDUCATION_OPTIONS) / sizeof(EDUCATION_OPTIONS[0]);
    int num_gaming_options = sizeof(GAMING_OPTIONS) / sizeof(GAMING_OPTIONS[0]);
    switch (option) {
        case 1: medical_list(num_medical_options);
        break;

        case 2: banking_list(num_banking_options);
        break;

        case 3:education_list(num_education_options);
        break;

        case 4:gaming_list(num_gaming_options);
        break;

        default:exit(0);
    }
}

int main() {
    int option,choice;
    
    printf("\n----------------\n");
    printf("\nDomains:\n----------------");
    printf("\n1. Medical\n2. Banking\n3. Education\n4. Gaming\n5.Exit");
    printf("\nEnter a domain: ");-
    scanf("%d",&option);
    switch (option){
        case 1: generate_list(option);
        break;

        case 2:generate_list(option);
        break;

        case 3:generate_list(option);
        break;

        case 4:generate_list(option);
        break;

        default:
    }
    return 0;
}

