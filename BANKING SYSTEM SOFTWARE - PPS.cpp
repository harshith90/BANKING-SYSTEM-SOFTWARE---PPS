/*MINI-PROJECT TOPIC NAME : BANKING SYSTEM SOFTWARE
   TEAM MEMBERS :
    1)M.V.S.HARSHITH - RA2311003011196
    2)DASARI SAI ROHITH - RA2311003011219
    */

/*
    FILE NAME  : BANKING SYSTEM SOFTWARE--PPS.CPP
    PURPOSE    : THE PRIMARY PURPOSE OF THIS BANKING SYSTEM SOFTWARE IS TO PROVIDE A SIMPLE FLATFROM FOR USERS TO CREATE A BANK
                 ACCOUNT WHERE THEY CAN :
                 1) MAKE A DEPOSIT
                 2) TAKE A LOAN
                 3) CHECK THE ACCOUNT BALANCE
                 4) CHECK THEIR EMI RECIPTS
                 5) CHECK SEE THEIR INTEREST TO PAY 
    AUTHORS    : M.V.S.HARSHITH 
                 DASARI SAI ROHITH
    CREATED BY : M.V.S.HARSHITH
                 DASARI SAI ROHITH
    UPDATED ON : 17-11-23
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CUSTOMERS 100

typedef struct {
    int accNumber;
    char name[50];
    double balance;
    double loanAmount;
    double interestRate;
    int loanTermMonths;
} Customer;

Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

// Function prototypes
void displayMenu();
void createAccount();
void deposit();
void withdraw();
void loanEMI();
void calculateInterest();
void displayBalance();

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                loanEMI();
                break;
            case 5:
                calculateInterest();
                break;
            case 6:
                displayBalance();
                break;
            case 7:
                printf("Thank you for using the banking system. Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}

void displayMenu() {
    printf("\n===== Banking System Menu =====\n");
    printf("1. Create Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Loan EMI Calculator\n");
    printf("5. Interest Calculator\n");
    printf("6. Display Balance\n");
    printf("7. Exit\n");
}

void createAccount() {
    if (customerCount < MAX_CUSTOMERS) {
        Customer newCustomer;
        printf("Enter your name: ");
        scanf("%s", newCustomer.name);
        newCustomer.accNumber = 1000 + customerCount; // Simple account number generation
        newCustomer.balance = 0.0;
        newCustomer.loanAmount = 0.0;
        newCustomer.interestRate = 0.0;
        newCustomer.loanTermMonths = 0;

        customers[customerCount++] = newCustomer;

        printf("Account created successfully. Your account number is %d\n", newCustomer.accNumber);
    } else {
        printf("Sorry, the maximum number of customers has been reached.\n");
    }
}

void deposit() {
    int accNumber;
    double amount;
    printf("Enter your account number: ");
    scanf("%d", &accNumber);

    int found = 0;
    for (int i = 0; i < customerCount; ++i) {
        if (customers[i].accNumber == accNumber) {
            found = 1;
            printf("Enter the amount to deposit: ");
            scanf("%lf", &amount);
            customers[i].balance += amount;
            printf("Deposit successful. Your new balance is %.2lf\n", customers[i].balance);
            break;
        }
    }

    if (!found) {
        printf("Account not found. Please check your account number.\n");
    }
}

void withdraw() {
    int accNumber;
    double amount;
    printf("Enter your account number: ");
    scanf("%d", &accNumber);

    int found = 0;
    for (int i = 0; i < customerCount; ++i) {
        if (customers[i].accNumber == accNumber) {
            found = 1;
            printf("Enter the amount to withdraw: ");
            scanf("%lf", &amount);

            if (amount <= customers[i].balance) {
                customers[i].balance -= amount;
                printf("Withdrawal successful. Your new balance is %.2lf\n", customers[i].balance);
            } else {
                printf("Insufficient funds.\n");
            }

            break;
        }
    }

    if (!found) {
        printf("Account not found. Please check your account number.\n");
    }
}

void loanEMI() {
    int accNumber;
    double loanAmount;
    double interestRate;
    int loanTermMonths;
    printf("Enter your account number: ");
    scanf("%d", &accNumber);

    int found = 0;
    for (int i = 0; i < customerCount; ++i) {
        if (customers[i].accNumber == accNumber) {
            found = 1;
            printf("Enter the loan amount: ");
            scanf("%lf", &loanAmount);
            printf("Enter the interest rate (in percentage): ");
            scanf("%lf", &interestRate);
            printf("Enter the loan term (in months): ");
            scanf("%d", &loanTermMonths);

            customers[i].loanAmount = loanAmount;
            customers[i].interestRate = interestRate;
            customers[i].loanTermMonths = loanTermMonths;

            double monthlyInterest = interestRate / 100.0 / 12.0;
            double emi = (loanAmount * monthlyInterest) / (1 - pow(1 + monthlyInterest, -loanTermMonths));
            printf("Loan EMI calculated. Your monthly EMI is %.2lf\n", emi);
            break;
        }
    }

    if (!found) {
        printf("Account not found. Please check your account number.\n");
    }
}

void calculateInterest() {
    int accNumber;
    printf("Enter your account number: ");
    scanf("%d", &accNumber);

    int found = 0;
    for (int i = 0; i < customerCount; ++i) {
        if (customers[i].accNumber == accNumber) {
            found = 1;
            double interest = (customers[i].loanAmount * customers[i].interestRate / 100.0) * customers[i].loanTermMonths / 12.0;
            printf("Interest calculated. Your total interest is %.2lf\n", interest);
            break;
        }
    }

    if (!found) {
        printf("Account not found. Please check your account number.\n");
    }
}

void displayBalance() {
    int accNumber;
    printf("Enter your account number: ");
    scanf("%d", &accNumber);

    int found = 0;
    for (int i = 0; i < customerCount; ++i) {
        if (customers[i].accNumber == accNumber) {
            found = 1;
            printf("Your balance is %.2lf\n", customers[i].balance);
            break;
        }
    }

    if (!found) {
        printf("Account not found. Please check your account number.\n");
    }
}

