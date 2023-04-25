#include "ProviderController.h"
#include "algorithm"
#include "vector"

#include "StartController.h"

void ProviderController::goBack() { StartController(); }

bool comparator(ProductType *pt1, ProductType *pt2) { return *pt1 < *pt2; }

void ProviderController::getAllProductTypes() {
  vector<ProductType *> pts;
  for (auto &model : this->productModel.find()) {
    ProductType *pt = new ProductType(model);
    pts.push_back(pt);
  }
  sort(pts.begin(), pts.end(), comparator);
  for (auto &model : pts) {
    cout << *model << endl;
  }
}

void ProviderController::provideProduct() {
  StringFieldORM *searchField =
      new StringFieldORM("email", this->providerModel.getEmail());
  IntFieldORM *replaceField;
  if (this->providerModel.getProductsAmount() > 0) {
    replaceField =
        new IntFieldORM("amount", this->providerModel.getProductsAmount() - 1);
  }

  this->providerModel =
      this->providerModel.updateOne<IntFieldORM>(searchField, {replaceField});

  delete searchField;
  delete replaceField;
}

void ProviderController::printInfo() {
  this->view->printProvider(this->providerModel);
}

void ProviderController::deleteAccount() {}

void ProviderController::updateAccount() {}

void ProviderController::refillProduct() {}
