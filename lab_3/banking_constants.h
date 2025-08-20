// banking_constants.h
#ifndef BANKING_CONSTANTS_H
#define BANKING_CONSTANTS_H

// Account type constants (can also be enums in a real system)
#define ACCOUNT_TYPE_SAVINGS 1
#define ACCOUNT_TYPE_CHECKING 2
#define ACCOUNT_TYPE_LOAN 3

// Interest Rates (as percentages or factors)
#define SAVINGS_INTEREST_RATE 0.035 // 3.5%
#define LOAN_INTEREST_RATE 0.0825   // 8.25%

// Minimum Balances
#define MIN_SAVINGS_BALANCE 500.00
#define MIN_CHECKING_BALANCE 200.00

// Transaction Limits
#define MAX_WITHDRAWAL_PER_DAY 10000.00
#define MAX_TRANSACTION_LIMIT 50000.00
#define MIN_TRANSACTION_AMOUNT 1.00

// Bank Identifier (example)
#define BANK_CODE "ABC123XYZ"

#endif // BANKING_CONSTANTS_H