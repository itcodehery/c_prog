#include <stdio.h>

int main() {
    float totalCost, discount, finalAmount;
   
    printf("Enter the total cost of items: Rs. ");
    scanf("%f", &totalCost);
    
    if (totalCost <= 2000) {
        discount = totalCost * 0.05; 
    } else if (totalCost <= 5000) {
        discount = totalCost * 0.25; 
    } else if (totalCost <= 10000) {
        discount = totalCost * 0.35; 
    } else {
        discount = totalCost * 0.50; 
    }
    
    finalAmount = totalCost - discount;
    
    printf("\nTotal Cost: Rs. %.2f\n", totalCost);
    printf("Discount Amount: Rs. %.2f\n", discount);
    printf("Final Amount to Pay: Rs. %.2f\n", finalAmount);
    
    return 0;
}
