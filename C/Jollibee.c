#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define TABLE_SIZE 10
#define MAX_COUPONS 100

typedef struct Product {
    char name[100];
    float price;
} Product;

typedef struct HashTableItem {
    char *key;
    Product *value;
} HashTableItem;

char username[100];
const char *menu[] = {"New Products", "Chickenjoy", "Burgers", "Jolly Spaghetti", "Burger Steak", "Super Meals"};

unsigned long long coupons[MAX_COUPONS];
int couponCount = 0;
HashTableItem *hashTable[TABLE_SIZE] = {NULL};

unsigned int hashFunction(const char *str);
void insert(HashTableItem **hashTable, const char *key, Product *value);
Product *search(HashTableItem **hashTable, const char *key);
void reducePrice(HashTableItem **hashTable, const char *key, float discount);
void addProduct();
void viewProduct();
void reduceProductPrice();
void mainMenu();
void viewAllItems();
void checkOut();
bool couponExists(unsigned long long coupon);
unsigned long long generateRandomNumber();
void addCoupon(unsigned long long coupon);

void fitToScreen(const char *title) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleWidth;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    int titleWidth = strlen(title);
    int totalWidth = consoleWidth - 2; // Total width excluding the edges
    int dashWidth = (totalWidth - titleWidth) / 2; // Dashes on each side

    printf("%.*s\n", dashWidth, "-----------------------------------------------------------------------------------------");
    printf(" %*s%s%*s\n", dashWidth - 1, "", title, totalWidth - dashWidth - titleWidth, "");
    printf("%.*s\n", dashWidth, "-----------------------------------------------------------------------------------------");
}

void addProduct() {
    char productName[100];
    float productPrice;

    printf("Enter product name: ");
    scanf("%99s", productName);

    printf("Enter product price: ");
    scanf("%f", &productPrice);

    Product *newProduct = (Product *)malloc(sizeof(Product));
    strcpy(newProduct->name, productName);
    newProduct->price = productPrice;

    insert(hashTable, productName, newProduct);
    printf("Product %s with price %.2f added successfully.\n", productName, productPrice);
}

void viewProduct() {
    char productName[100];
    printf("Enter product name to view: ");
    scanf("%99s", productName);

    Product *product = search(hashTable, productName);
    if (product != NULL) {
        printf("Product: %s, Price: %.2f\n", product->name, product->price);
    } else {
        printf("Product %s not found.\n", productName);
    }
}

void viewAllItems() {
    printf("All Products:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            printf("Product: %s, Price: %.2f\n", hashTable[i]->value->name, hashTable[i]->value->price);
        }
    }
}

void reduceProductPrice() {
    char productName[100];
    float discount;

    printf("Enter product name to reduce price: ");
    scanf("%99s", productName);

    printf("Enter discount amount: ");
    scanf("%f", &discount);

    reducePrice(hashTable, productName, discount);
}

void checkOut() {
    char productName[100], decision;
    printf("Enter product name to view: ");
    scanf("%99s", productName);

    Product *product = search(hashTable, productName);
    if (product != NULL) {
        printf("Product: %s, Price: %.2f\n", product->name, product->price);

        printf("Checkout? (y/n): ");
        while ((decision = getchar()) != '\n' && decision != EOF);
        scanf("%c", &decision);

        if (decision == 'y' || decision == 'Y') {
            if (couponCount > 0) {
                printf("You have a coupon! You can use it to get a discount when checking out.\nUse Coupon (u) or Cancel (c): ");
                char toUse;
                while ((toUse = getchar()) != '\n' && toUse != EOF);
                scanf("%c", &toUse);
                if (toUse == 'u' || toUse == 'U') {
                    reducePrice(hashTable, productName, 5.0);  // Reduce by 10 units for demonstration
                    printf("You've used a coupon!\n");

                    char r;
                    printf("Proceed to checkout,\nExit");
                    scanf("%c", &r);
                    switch(r){
                        case 'p':
                        for(int i = 0; i < TABLE_SIZE; i++){
                            if(TABLE_SIZE != null){
                                
                            }
                        }
                    }
                } else {
                    printf("Cancelled.\n");
                }
            }
        } else {
            printf("Cancelled.\n");
        }
    } else {
        printf("Product %s not found.\n", productName);
    }
}

unsigned int hashFunction(const char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 5) + *str++;
    }
    return hash % TABLE_SIZE;
}

void insert(HashTableItem **hashTable, const char *key, Product *value) {
    unsigned int index = hashFunction(key);
    HashTableItem *newItem = (HashTableItem *)malloc(sizeof(HashTableItem));
    newItem->key = strdup(key);
    newItem->value = value;
    hashTable[index] = newItem;
}

Product *search(HashTableItem **hashTable, const char *key) {
    unsigned int index = hashFunction(key);
    HashTableItem *item = hashTable[index];
    if (item == NULL) {
        return NULL;
    }
    if (strcmp(item->key, key) == 0) {
        return item->value;
    }
    return NULL;
}

void reducePrice(HashTableItem **hashTable, const char *key, float discount) {
    Product *product = search(hashTable, key);
    if (product != NULL) {
        product->price -= discount;
        if (product->price < 0) {
            product->price = 0;
        }
        printf("Product %s price reduced by %.2f. New price: %.2f\n", key, discount, product->price);
    } else {
        printf("Product %s not found. Price not reduced.\n", key);
    }
}

unsigned long long generateRandomNumber() {
    unsigned long long randomNumber = 0;
    for (int i = 0; i < 10; i++) {
        randomNumber = randomNumber * 10 + (rand() % 10);
    }
    return randomNumber;
}

bool couponExists(unsigned long long coupon) {
    for (int i = 0; i < couponCount; i++) {
        if (coupons[i] == coupon) {
            return true;
        }
    }
    return false;
}

void addCoupon(unsigned long long coupon) {
    if (!couponExists(coupon)) {
        if (couponCount < MAX_COUPONS) {
            coupons[couponCount++] = coupon;
            printf("Coupon %llu added successfully.\n", coupon);
        } else {
            printf("Coupon array is full. Cannot add more coupons.\n");
        }
    } else {
        printf("Coupon %llu already exists. Not added.\n", coupon);
    }
}

void mainMenu() {
    const char *txt = "Jollibee";
    fitToScreen(txt);

    printf("Enter your name: ");
    scanf("%s", username);
    printf("Welcome %s.\n", username);

    int keepRunning = 1; // Flag to keep the menu running
    while (keepRunning) {
        printf("Menu Options:\n");
        printf("1. Add Product\n");
        printf("2. View Product\n");
        printf("3. View All Items\n");
        printf("4. Reduce Product Price\n");
        printf("5. Checkout\n");
        printf("0. Exit\n"); // Option to exit the menu

        int choice;
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                viewProduct();
                break;
            case 3:
                viewAllItems();
                break;
            case 4:
                reduceProductPrice();
                break;
            case 5:
                checkOut();
                break;
            case 0:
                keepRunning = 0;
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}

int main() {
    srand(time(NULL));
    mainMenu();
    return 0;
}
