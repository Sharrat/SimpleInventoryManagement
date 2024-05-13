#include "mainOOP.h"
#include <iostream>
#include <algorithm>

void Product::displayDetails() const {
    std::cout << "Name: " << name << ", Price: $" << price << ", Quantity: " << quantity << ", SKU: " << SKU << std::endl;
}

double Product::calculateTotalPrice(int quantityToBuy) const {
    return price * quantityToBuy;
}

void Product::updateQuantity(int delta) {
    quantity += delta;
}

std::string Product::getSKU() const {
    return SKU;
}

int Product::getQuantity() const {
    return quantity;
}

void Electronics::displayDetails() const {
    std::cout << "Category: Electronics, ";
    Product::displayDetails();
    std::cout << "Brand: " << brand << std::endl;
}

void Inventory::addProduct(Product* product) {
    products.push_back(product);
}

bool Inventory::sellProduct(const std::string& SKU, int quantityToSell) {
    auto it = std::find_if(products.begin(), products.end(), [&](Product* product) {
        return product->getSKU() == SKU;
    });

    if (it != products.end() && (*it)->getQuantity() >= quantityToSell) {
        (*it)->updateQuantity(-quantityToSell);
        return true;
    }
    return false;
}

void Inventory::displayInventory() const {
    std::cout << "Inventory:" << std::endl;
    for (const auto& product : products) {
        product->displayDetails();
    }
}
