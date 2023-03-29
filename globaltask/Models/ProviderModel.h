#pragma once
#include "AUser.h"
#include "vector"
#include "ProductModel.h"

class ProviderModel : public AUser<ProviderModel> {
 protected:
    std::vector<ProductModel> products;

 public:
    std::vector<ProductModel> getProducts() {
        return this->products;
    }

    ProviderModel* setProducts(std::initializer_list<ProductModel> products) {
        this->products = products;
        return this; }
};
