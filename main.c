#include <stdio.h>

#define NUM_PRODUCTS 5
#define NUM_WEEKS 4

// Structure to represent product
typedef struct {
    int production[NUM_WEEKS];
    int sales[NUM_WEEKS];
} Product;

// Function prototypes
void calculateWeeklyValue(Product products[], int week);
void calculateTotalValue(Product products[]);
void displayMenu();

int main() {
    Product products[NUM_PRODUCTS] = {0}; // Initialize all products to zero

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the week number (1-%d): ", NUM_WEEKS);
                int week;
                scanf("%d", &week);
                calculateWeeklyValue(products, week - 1);
                break;
            case 2:
                calculateTotalValue(products);
                break;
            case 3:
                printf("Enter the product number (1-%d): ", NUM_PRODUCTS);
                int productNum;
                scanf("%d", &productNum);
                printf("Enter the month number (1-%d): ", NUM_WEEKS);
                int month;
                scanf("%d", &month);
                printf("Production value for product %d in month %d: %d\n", productNum, month, products[productNum - 1].production[month - 1]);
                printf("Sales value for product %d in month %d: %d\n", productNum, month, products[productNum - 1].sales[month - 1]);
                break;
            case 4:
                calculateTotalValue(products);
                break;
            case 5:
                printf("Exiting...");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 5);

    return 0;
}

// Function to calculate weekly production and sales values for each product
void calculateWeeklyValue(Product products[], int week) {
    printf("Weekly production and sales values for each product:\n");
    for(int i = 0; i < NUM_PRODUCTS; i++) {
        printf("Product %d - Production: %d, Sales: %d\n", i + 1, products[i].production[week], products[i].sales[week]);
    }
}

// Function to calculate total production and sales values for all products
void calculateTotalValue(Product products[]) {
    int totalProduction = 0;
    int totalSales = 0;
    for(int i = 0; i < NUM_PRODUCTS; i++) {
        for(int j = 0; j < NUM_WEEKS; j++) {
            totalProduction += products[i].production[j];
            totalSales += products[i].sales[j];
        }
    }
    printf("Total production value: %d\n", totalProduction);
    printf("Total sales value: %d\n", totalSales);
}

// Function to display menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Weekly production and sales values for each product\n");
    printf("2. Weekly production and sales values for all products\n");
    printf("3. Production and sales value for each product in a month\n");
    printf("4. Total production and sales values for all products\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}
