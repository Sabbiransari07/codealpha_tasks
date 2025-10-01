#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Account
{
    int acc_no;
    char name[100];
    float balance;
};
void CreateAccout()
{
    struct Account acc;
    FILE *f;
    f = fopen("bank.dat", "ab"); // append mode
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }
    printf("Enter Account Number: ");
    scanf("%d", &acc.acc_no);
    printf("Enter Account Holder Name: ");
    getchar(); // clear buffer
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = '\0'; // remove newline
    acc.balance = 0.0;
    fwrite(&acc, sizeof(acc), 1, f);
    fclose(f);
    printf("Account created successfully!\n");
}
void deposit()
{
    int acc_no;
    float amount;
    struct Account acc;
    int found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &acc_no);
    printf("Enter Deposit Amount: ");
    scanf("%f", &amount);

    FILE *f;
    f = fopen("bank.dat", "rb+");
    if (f == NULL) {
        printf("No account records found!\n");
        return;
    }
    while (fread(&acc, sizeof(acc), 1, f)) 
    {
        if (acc.acc_no == acc_no) 
        {
            acc.balance += amount;
            fseek(f, -sizeof(acc), SEEK_CUR);
            fwrite(&acc, sizeof(acc), 1, f);
            printf("Deposit Successful! New Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    if (!found) printf("Account not found!\n");
    fclose(f);
}
void withdraw()
{
     int acc_no;
    float amount;
    struct Account acc;
    int found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &acc_no);
    printf("Enter Withdraw Amount: ");
    scanf("%f", &amount);

    FILE *f;
    f = fopen("bank.dat", "rb+");
    if (f == NULL) {
        printf("No account records found!\n");
        return;
    }
     while (fread(&acc, sizeof(acc), 1, f)) {
        if (acc.acc_no == acc_no) {
            if (amount > acc.balance) {
                printf("Insufficient Balance!\n");
            } else {
                acc.balance -= amount;
                fseek(f, -sizeof(acc), SEEK_CUR);
                fwrite(&acc, sizeof(acc), 1, f);
                printf("Withdrawal Successful! New Balance: %.2f\n", acc.balance);
            }
            found = 1;
            break;
        }
    }

    if (!found) printf("Account not found!\n");
    fclose(f);
}
void balanceEnquiry()
{
    int acc_no;
    struct Account acc;
    int found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &acc_no);

    FILE *f;
    f = fopen("bank.dat", "rb");
    if (f == NULL) {
        printf("No account records found!\n");
        return;
    }
    while (fread(&acc, sizeof(acc), 1, f)) {
        if (acc.acc_no == acc_no) {
            printf("\n--- Account Details ---\n");
            printf("Account No: %d\n", acc.acc_no);
            printf("Holder Name: %s\n", acc.name);
            printf("Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    if (!found) printf("Account not found!\n");
    fclose(f);
}
void displayMenu()
{
    printf("\n------------ Banking System ------------\n");
    printf("1. Create Account\n");
    printf("2. Diposit\n");
    printf("3. Withdraw\n");
    printf("4. Balance Enquiry\n");
    printf("5. Exit\n");
}
int main(){
    int choice;
    displayMenu();
    while(1)
    {
        printf("Enter your choice :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
            {
                CreateAccout();
                break;
            }
            case 2 :
            {
                deposit();
                break;
            }
            case 3 :
            {
                withdraw();
                break;
            }
            case 4 :
            {
                balanceEnquiry();
                break;
            }
            case 5 :
            {
                printf("Thankyou for using Banking System. Exiting....");
                exit(0);
                break;
            }
            default :
                printf("<<Invalid choice>> Please try again...\n");
        }
    }
   
return 0;
}