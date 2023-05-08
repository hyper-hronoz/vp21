#include "ProviderController.h"
#include "algorithm"
#include "vector"

#include "StartController.h"

void ProviderController::goBack() { StartController(); }

bool comparator(ProductType *pt1, ProductType *pt2) { return *pt1 < *pt2; }

void ProviderController::getAllProductTypes() {
  vector<ProductType *> pts;
  for (auto &model : this->productTypeModel.find()) {
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
      new StringFieldORM("email", this->providerModel->getEmail());

  cout << searchField->getValue() << endl;
  cout << this->providerModel->getProductsAmount() << endl;

  if (this->providerModel->getProductsAmount() > 0) {
    IntFieldORM *replaceField =
        new IntFieldORM("amount", this->providerModel->getProductsAmount() - 1);
    this->providerModel =
        new Provider(this->providerModel->updateOne<StringFieldORM>(
            searchField, {replaceField}));
    cout << *this->providerModel << endl;

    delete replaceField;
  }

  delete searchField;
}

void ProviderController::printInfo() {
  this->view->printProvider(this->providerModel);
}

void ProviderController::deleteAccount() {
  StringFieldORM *query =
      new StringFieldORM("email", this->providerModel->getEmail());
  this->providerModel->deleteOne<StringFieldORM>(query);
  StartController _;
  delete query;
}

void ProviderController::updateAccount() {}

void ProviderController::refillProduct() {
  vector<Error> errors;

  StringFieldORM *type = new StringFieldORM("type");
  IntFieldORM *price = new IntFieldORM("price");
  StringFieldORM *name = new StringFieldORM("name");

  cout << "Enter product type: ";
  cin >> type;
  cout << "Enter product price: ";
  cin >> price;
  cout << "Enter product name: ";
  cin >> name;

  cout << *this->providerModel << endl;

  ProductType _productType =
      this->productTypeModel.findOne<StringFieldORM>(type);

  if (_productType.getType() != type->getValue()) {
    errors.push_back(Error(ERROR_TYPES::NOT_FOUND,
                           "Такой тип продукта не может быть задан"));
    return;
  }

  cout << "Creating new product" << endl;
  Product newProduct = product.create(
      {
          type,
          price,
          name,
      },
      errors);

  cout << newProduct << endl;
  cout << "Updating provider" << endl;
  this->providerModel =
      new Provider(this->providerModel->updateOne<StringFieldORM>(
          new StringFieldORM("productID"),
          {
              new StringFieldORM("productID", newProduct.getId()),
              new IntFieldORM("amount",
                              this->providerModel->getProductsAmount() + 1),
          }));

  cout << *this->providerModel << endl;

  cout << endl;

}
