#include <iostream>
#include <vector>
#include "mainFunctional.h"
#include "mainOOP.h"

using namespace std;

int main() {
    cout << "START OF FUNCTIONAL" << endl;
    vector<ProductF> inventory;

    addProduct(inventory, {"Laptop", 999.99, 10, "SKU123"});
    addProduct(inventory, {"Smartphone", 599.99, 20, "SKU456"});

    displayInventory(inventory);

    if (sellProduct(inventory, "SKU123", 2)) {
        cout << "Sold 2 laptops." << endl;
    } else {
        cout << "Failed to sell laptops." << endl;
    }

    displayInventory(inventory);

    cout << "START OF OOP" << endl;
    Inventory inventory_oop;

    Electronics laptop("Laptop", 999.99, 10, "SKU123", "Dell");
    Electronics smartphone("Smartphone", 599.99, 20, "SKU456", "Apple");

    inventory_oop.addProduct(&laptop);
    inventory_oop.addProduct(&smartphone);

    inventory_oop.displayInventory();

    if (inventory_oop.sellProduct("SKU123", 2)) {
        cout << "Sold 2 laptops." << endl;
    } else {
        cout << "Failed to sell laptops." << endl;
    }

    inventory_oop.displayInventory();

    return 0;
}

