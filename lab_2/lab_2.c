#include<stdio.h>

float get_discount(float subtotal){
    if (subtotal > 1000) {
        return 0.1 * subtotal;
    }
    else if (subtotal > 500){
        return 0.05 * subtotal;
    }
    else {
        return 0;
    }
}

float get_gst(float subtotal_after_discount){
    return 0.18 * subtotal_after_discount;
}

void main() {
    int ch;
    int burger_count = 0;
    int pizza_count = 0;
    int pasta_count = 0;
    int coke_count = 0;
    int ice_cream_count = 0;
    
    const int burger_price = 120;
    const int pizza_price = 250;
    const int pasta_price = 180;
    const int coke_price = 50;
    const int ice_cream_price = 90;

    int burger_total = 0;
    int pizza_total = 0;
    int pasta_total = 0;
    int coke_total = 0;
    int ice_cream_total = 0;

    do {
        int quantity;
        printf("Foodie Corner Menu:\n1.Burger - Rs.120\n2.Pizza - Rs.250\n3.Pasta - Rs.180\n4.Coke - Rs.50\n5.Ice Cream - Rs.90\n6.Generate Bill\n7.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        if (ch != 6){
            printf("Enter quantity:");
        scanf("%d", &quantity);
        }
        printf("\n\n");
        switch (ch) {
            case 1: burger_count += quantity;
            burger_total = burger_count * burger_price;
            break;

            case 2: pizza_count += quantity;
            pizza_total = pizza_count * pizza_price;
            break;

            case 3: pasta_count += quantity;
            pasta_total = pasta_count * pasta_price;
            break;

            case 4: coke_count += quantity;
            coke_total = coke_count * coke_price;
            break;

            case 5: ice_cream_count += quantity;
            ice_cream_total = ice_cream_count * ice_cream_price;
            break;

            case 6: printf("\n===FINAL BILL===");
            burger_total != 0 ? printf("\nBurger (%d) - Rs.%d", burger_count,burger_total): printf("");
            pizza_total != 0 ? printf("\nPizza (%d) - Rs.%d", pizza_count,pizza_total): printf("");
            pasta_total != 0 ? printf("\nPasta (%d) - Rs.%d",pasta_count, pasta_total) : printf("");
            coke_total != 0 ? printf("\nCoke (%d) - Rs.%d", coke_count, coke_total) : printf("");
            ice_cream_count != 0 ? printf("\nIce Cream (%d) - Rs.%d", ice_cream_count, ice_cream_total) : printf("");
            printf("\n------------");
            float subtotal = burger_total+pizza_total+pasta_total+coke_total+ice_cream_total + 0.0;
            printf("\nSubtotal: Rs.%.2f", subtotal);
            printf("\nDiscount: Rs.%.2f", get_discount(subtotal));
            float subtotal_after_discount = subtotal - get_discount(subtotal); 
            printf("\nGST(18%%): Rs.%.2f",get_gst(subtotal_after_discount));
            float total = subtotal_after_discount + get_gst(subtotal_after_discount);
            printf("\n------------");
            printf("\nTOTAL: %.2f\n\n", total);
            break;
        }
        
    } while (ch < 6);
}

