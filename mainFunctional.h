#ifndef MAIN_FUNCTIONAL_H
#define MAIN_FUNCTIONAL_H

#include <vector>
#include <string>

struct ProductF {
    std::string name;
    double price;
    int quantity;
    std::string SKU;
};

void addProduct(std::vector<ProductF>& inventory, const ProductF& product);
bool sellProduct(std::vector<ProductF>& inventory, const std::string& SKU, int quantityToSell);
void displayInventory(const std::vector<ProductF>& inventory);

#endif // MAIN_FUNCTIONAL_H
