#include <stdio.h>
#include <string.h> // Needed for string functions like strlen and strcspn

// Global variables to hold account info
char account_holder_name[100] = ""; // Name of the account holder
float balance = 0.0;             // Current balance

// --- Function Definitions ---

// Opens a new bank account
void open_account() {
    printf("\n--- Open New Account ---\n");
    printf("Enter account holder's name: ");
    // Get the name safely
    fgets(account_holder_name, sizeof(account_holder_name), stdin);
    // Remove the extra Enter keypress (newline character)
    account_holder_name[strcspn(account_holder_name, "\n")] = 0;

    printf("Enter initial deposit amount: $");
    scanf("%f", &balance);
    // Clear the keyboard buffer
    while (getchar() != '\n'); 

    printf("\nAccount created for %s with $%.2f.\n", account_holder_name, balance);
}

// Shows all account details
void view_account() {
    printf("\n--- View Account Details ---\n");
    if (strlen(account_holder_name) > 0) { // Check if an account exists
        printf("Account Holder: %s\n", account_holder_name);
        printf("Current Balance: $%.2f\n", balance);
    } else {
        printf("No account open yet. Please open one first.\n");
    }
}

// Shows just the account balance
void view_balance() {
    printf("\n--- View Account Balance ---\n");
    if (strlen(account_holder_name) > 0) { // Check if an account exists
        printf("Current Balance: $%.2f\n", balance);
    } else {
        printf("No account open yet. Please open one first.\n");
    }
}