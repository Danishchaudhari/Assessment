#include <stdio.h>
#include <conio.h>

int main() 
{
    int choice, qty;
    float amount = 0, total = 0;
    char more;

    do 
    {
        printf("\nMenu\n");
        printf("1. Pizza price = 180 rs/pcs\n");
        printf("2. Burger price = 100 rs/pcs\n");
        printf("3. Dosa price = 120 rs/pcs\n");
        printf("4. Idli price = 50 rs/pcs\n");

        printf("Please Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("You have selected Pizza.\n");
                printf("Enter the quantity: ");
                scanf("%d", &qty);
                amount = qty * 180;
                break;
            case 2:
                printf("You have selected Burger.\n");
                printf("Enter the quantity: ");
                scanf("%d", &qty);
                amount = qty * 100;
                break;
            case 3:
                printf("You have selected Dosa.\n");
                printf("Enter the quantity: ");
                scanf("%d", &qty);
                amount = qty * 120;
                break;
            case 4:
                printf("You have selected Idli.\n");
                printf("Enter the quantity: ");
                scanf("%d", &qty);
                amount = qty * 50;
                break;
            default:
                printf("Invalid choice!\n");
                amount = 0;
        }

        printf("Amount: %f\n", amount);
        total += amount;
        printf("Total Amount is = %f\n", total);

        printf("Do you want to place more orders? (y/n): ");
        scanf(" %c", &more); // space before %c to avoid newline issues

    } while (more == 'y' || more == 'Y');

    printf("\nFinal Bill Amount = %f\n", total);
    printf("/nThank you! Visit Again.");

    return 0;
}
