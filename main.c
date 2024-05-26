#include <stdio.h>
#include <stdlib.h>

#define NUM_PRODUCTS 5
#define WEEKS_IN_MONTH 4

// Structure to represent a product
typedef struct {
    int product_id;
    char *product_name;
    float weekly_production[WEEKS_IN_MONTH];
    float weekly_sales[WEEKS_IN_MONTH];
} Product;

// Function prototypes
void initializeProducts(Product products[]);
void calculateWeeklyProductSales(Product products[]);
void displayWeeklyProductSales(Product products[]);
void calculateMonthlyProductSales(Product products[]);
void displayMonthlyProductSales(Product products[]);
void calculateTotalProductSales(Product products[]);
void displayTotalProductSales(Product products[]);
void freeProducts(Product products[]);

int main() {
    Product products[NUM_PRODUCTS];
    initializeProducts(products);
    
    int choice;
    
    do {
        printf("\n1. Weekly production and sales for each product\n");
        printf("2. Weekly production and sales for all products\n");
        printf("3. Production and sales for each product in one month\n");
        printf("4. Total production and sales for all products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                calculateWeeklyProductSales(products);
                break;
            case 2:
                displayWeeklyProductSales(products);
                break;
            case 3:
                calculateMonthlyProductSales(products);
                break;
            case 4:
                calculateTotalProductSales(products);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while(choice != 5);
    
    freeProducts(products);
    
    return 0;
}

void initializeProducts(Product products[]) {
    char *product_names[NUM_PRODUCTS] = {"Product A", "Product B", "Product C", "Product D", "Product E"};
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        products[i].product_id = i + 1;
        products[i].product_name = product_names[i];
    }
}

void calculateWeeklyProductSales(Product products[]) {
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        printf("Enter weekly production for %s:\n", products[i].product_name);
        for (int j = 0; j < WEEKS_IN_MONTH; j++) {
            printf("Week %d:  ", j + 1);
            scanf("%f ", &products[i].weekly_production[j]);
        }
        
        printf("Enter weekly sales for %s:\n", products[i].product_name);
        for (int j = 0; j < WEEKS_IN_MONTH; j++) {
            printf("Week %d:  ", j + 1);
            scanf("%f ", &products[i].weekly_sales[j]);
        }
    }
}

void displayWeeklyProductSales(Product products[]) {
    printf("Weekly production and sales for each product:\n");
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        printf("%s:\n", products[i].product_name);
        printf("Week   Production    Sales\n");
        for (int j = 0; j < WEEKS_IN_MONTH; j++) {
            printf("%-6d%-14.2f%.2f\n", j + 1, products[i].weekly_production[j], products[i].weekly_sales[j]);
        }
        printf("\n");
    }
}

void calculateMonthlyProductSales(Product products[]) {
    printf("Production and sales for each product in one month:\n");
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        float total_production = 0, total_sales = 0;
        for (int j = 0; j < WEEKS_IN_MONTH; j++) {
            total_production += products[i].weekly_production[j];
            total_sales += products[i].weekly_sales[j];
        }
        printf("%s = Production: %.2f, Sales: %.2f\n", products[i].product_name, total_production, total_sales);
    }
}

void calculateTotalProductSales(Product products[]) {
    printf("Total production and sales for all products:\n");
    float total_production = 0, total_sales = 0;
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        for (int j = 0; j < WEEKS_IN_MONTH; j++) {
            total_production += products[i].weekly_production[j];
            total_sales += products[i].weekly_sales[j];
        }
    }
    printf("Total Production: %.2f, Total Sales: %.2f\n", total_production, total_sales);
}

void freeProducts(Product products[]) {
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        free(products[i].product_name);
    }
}

