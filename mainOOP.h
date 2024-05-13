#ifndef MAIN_OOP_H
#define MAIN_OOP_H

#include <vector>
#include <string>

class Product {
protected:
    std::string name;
    double price;
    int quantity;
    std::string SKU;

public:
    Product(const std::string& _name, double _price, int _quantity, const std::string& _SKU)
            : name(_name), price(_price), quantity(_quantity), SKU(_SKU) {}

    virtual void displayDetails() const;
    virtual double calculateTotalPrice(int quantityToBuy) const;
    virtual void updateQuantity(int delta);
    std::string getSKU() const;
    int getQuantity() const;
};

class Electronics : public Product {
private:
    std::string brand;

public:
    Electronics(const std::string& _name, double _price, int _quantity, const std::string& _SKU, const std::string& _brand)
            : Product(_name, _price, _quantity, _SKU), brand(_brand) {}

    void displayDetails() const override;
};

class Inventory {
private:
    std::vector<Product*> products;

public:
    void addProduct(Product* product);
    bool sellProduct(const std::string& SKU, int quantityToSell);
    void displayInventory() const;
};

#endif // MAIN_OOP_H
