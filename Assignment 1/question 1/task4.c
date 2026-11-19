#include <stdio.h>

int main()
{
    int quantity;
    float price, discount, tax;
    float subtotal, discountedAmount;
    float finalBill;

    FILE *file;

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    printf("Enter price per item: ");
    scanf("%f", &price);

    printf("Enter discount percentage: ");
    scanf("%f", &discount);

    printf("Enter tax percentage: ");
    scanf("%f", &tax);

    // Input validation

    if (quantity <= 0)
    {
        printf("Error: Invalid quantity.\n");
        return 0;
    }
    else if (price < 0)
    {
        printf("Error: Invalid price.\n");
        return 0;
    }
    else if (discount < 0 || discount > 100)
    {
        printf("Error: Invalid discount percentage.\n");
        return 0;
    }
    else if (tax < 0)
    {
        printf("Error: Invalid tax percentage.\n");
        return 0;
    }

    // Calculate subtotal

    subtotal = quantity * price;

    // Calculate discounted amount

    discountedAmount = subtotal -
                       (subtotal * discount / 100);

    // Calculate final bill

    finalBill = discountedAmount +
                (discountedAmount * tax / 100);

    // Display bill

    printf("\n========== SHOPPING BILL ==========\n");
    printf("Quantity: %d\n", quantity);
    printf("Price Per Item: Rs. %.2f\n", price);
    printf("Subtotal: Rs. %.2f\n", subtotal);
    printf("Discount: %.2f%%\n", discount);
    printf("Discounted Amount: Rs. %.2f\n", discountedAmount);
    printf("Tax: %.2f%%\n", tax);
    printf("Final Bill: Rs. %.2f\n", finalBill);
    printf("===================================\n");

    // Store bill in a file

    file = fopen("bill.txt", "w");

    if (file == NULL)
    {
        printf("Error: Unable to create bill document.\n");
        return 0;
    }

    fprintf(file, "========== SHOPPING BILL ==========\n");
    fprintf(file, "Quantity: %d\n", quantity);
    fprintf(file, "Price Per Item: Rs. %.2f\n", price);
    fprintf(file, "Subtotal: Rs. %.2f\n", subtotal);
    fprintf(file, "Discount: %.2f%%\n", discount);
    fprintf(file, "Discounted Amount: Rs. %.2f\n",
            discountedAmount);
    fprintf(file, "Tax: %.2f%%\n", tax);
    fprintf(file, "Final Bill: Rs. %.2f\n", finalBill);

    fclose(file);

    printf("\nBill successfully saved in bill.txt\n");

    return 0;
}
