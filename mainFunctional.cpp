#include "mainFunctional.h"
#include <iostream>
#include <algorithm>

void addProduct(std::vector<ProductF>& inventory, const ProductF& product) {
    inventory.push_back(product);
}

bool sellProduct(std::vector<ProductF>& inventory, const std::string& SKU, int quantityToSell) {
    auto it = std::find_if(inventory.begin(), inventory.end(), [&](const ProductF& product) {
        return product.SKU == SKU;
    });

    if (it != inventory.end() && it->quantity >= quantityToSell) {
        it->quantity -= quantityToSell;
        return true;
    }
    return false;
}

void displayInventory(const std::vector<ProductF>& inventory) {
    std::cout << "Inventory:" << std::endl;
    for (const auto& product : inventory) {
        std::cout << "Name: " << product.name << ", Price: $" << product.price << ", Quantity: " << product.quantity << ", SKU: " << product.SKU << std::endl;
    }
}
