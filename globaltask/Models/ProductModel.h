#pragma once
#include "vector"
#include "iostream"
#include "string"

enum PRODUCT_TYPE {
    TOYS,
    BOYS,
    GIRLS,
};

class ProductModel {
 protected:
    std::string name;
    std::vector<PRODUCT_TYPE> productTypes;
    int price;
    int amount;

 public:
    std::string getName() {
        return this->name;
    }

    std::vector<PRODUCT_TYPE> getProductType() {
        return this->productTypes;
    }

    int getPrice() {
        return this->price;
    }

    int getAmount() {
        return this->amount;
    }

    ProductModel* setName(std::string name) {
        this->name = name;
        return this;
    }

    ProductModel* setProductTypes(std::initializer_list<PRODUCT_TYPE> types) {
        this->productTypes = types;
        return this;
    }

    ProductModel* setPrice(int price) {
        this->price = price;
        return this;
    }

    ProductModel* setAmount(int amount) {
        this->amount = amount;
        return this;
    }

    ProductModel();
};

