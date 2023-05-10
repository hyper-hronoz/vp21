#include "ProviderController.h"
#include "algorithm"
#include "vector"

#include "../Exceptions/NegativeIndexException.h"
#include "StartController.h"

void ProviderController::goBack() { StartController(); }

bool comparator(ProductType *pt1, ProductType *pt2) { return *pt1 < *pt2; }

void ProviderController::printProductInfo() {
  if (this->providerModel->getProductId() == "") {
    cout << "Нет у него поставляемого продукта" << endl;
    return;
  }
  StringFieldORM *search =
      new StringFieldORM("_id", this->providerModel->getProductId());
  Product product = this->productModel.findOne<StringFieldORM>(search);
  cout << product << endl;
  delete search;
}

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
  IntFieldORM *amount = new IntFieldORM("amount", 1);

  cout << "Введите количество поставляемого товара: ";
  cin >> amount;

  StringFieldORM *searchField =
      new StringFieldORM("email", this->providerModel->getEmail());

  if (this->providerModel->getProductsAmount() - amount->getValue() >= 0) {
    IntFieldORM *replaceField =
        new IntFieldORM("amount", this->providerModel->getProductsAmount() -
                                      amount->getValue());
    this->providerModel =
        new Provider(this->providerModel->updateOne<StringFieldORM>(
            searchField, {replaceField}));

    if (this->providerModel->getProductId() == "") {
      cout << "Операция не может быть выпослнена тк поставщик пустой. Нет поля "
              "productID"
           << endl;
      return;
    }

    cout << "IDs: " << this->providerModel->getProductId() << " "
         << this->providerModel->getId() << endl;
    StringFieldORM *productID =
        new StringFieldORM("productID", this->providerModel->getProductId());
    StringFieldORM *providerID =
        new StringFieldORM("providerID", this->providerModel->getId());

    vector<Error> errors;
    this->productTransaction.create({productID, providerID, amount}, errors);

    if (errors.size() == 0) {
      cout << "Транзакция совершена успешно!" << endl;
    } else {
      for (Error error : errors) {
        cout << "Provider product error: " << error.getMessage() << endl;
      }
    }

    delete replaceField;
    delete providerID;
    delete productID;
    delete amount;
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

void ProviderController::updateAccount() {
  try {
    char y = 'n';
    cout << "Хотите обновить поставщика(y/n)?: ";
    cin >> y;
    if (y == 'y') {
      cout << "Обновляем строковое поле..." << endl;
      vector<AFieldORM *> fields = {};
      for (auto item : *this->providerModel) {
        for (auto inner : item) {
          fields.push_back(inner);
        }
        break;
      }

      for (int i = 0; i < fields.size(); i++) {
        if (fields[i]->getKey() == "_id") {
          continue;
        }
        cout << i << ") " << fields[i]->getKey() << endl;
      }

      int fieldIndex;
      cout << "Введите поле, которое хотитете обновить: ";
      cin >> fieldIndex;

      if (fieldIndex < 0) {
        throw new NegativeIndexException();
      }

      if (fieldIndex > fields.size() - 1 || fieldIndex == 0) {
        throw new out_of_range("Index in allowed fields out of range");
      }

      StringFieldORM *searchField =
          new StringFieldORM("_id", this->providerModel->getId());
      AFieldORM *replaceField;
      if (fields[fieldIndex]->getType() == typeid(StringFieldORM).name()) {
        std::string replaceString{};
        cout << "Input replace string: ";
        cin >> replaceString;
        replaceField =
            new StringFieldORM(fields[fieldIndex]->getKey(), replaceString);
      } else if (fields[fieldIndex]->getType() == typeid(IntFieldORM).name()) {
        int replaceInt;
        cout << "Input replace integer: ";
        cin >> replaceInt;
        replaceField =
            new IntFieldORM(fields[fieldIndex]->getKey(), replaceInt);
      } else {
        cout << "my custom undefined begavior" << endl;
        return;
      }

      this->providerModel =
          new Provider(this->providerModel->updateOne<StringFieldORM>(
              searchField, {replaceField}));

      delete searchField;
      delete replaceField;
    } else {
      this->view->display();
    }
  } catch (std::out_of_range &e) {
    cout << "Index out of range in updateAccount: " << e.what() << endl;
  } catch (NegativeIndexException &e) {
    cout << e.what() << endl;
  }
  // this->providerModel->updateOne
}

void ProviderController::refillProduct() {
  vector<Error> errors;

  StringFieldORM *type = new StringFieldORM("type");
  IntFieldORM *price = new IntFieldORM("price");
  StringFieldORM *name = new StringFieldORM("name");

  int productAmount = 1;

  cout << "Enter product type: ";
  cin >> type;
  cout << "Enter product price: ";
  cin >> price;
  cout << "Enter product name: ";
  cin >> name;
  cout << "Enter product amount: ";
  cin >> productAmount;

  cout << *this->providerModel << endl;

  ProductType _productType =
      this->productTypeModel.findOne<StringFieldORM>(type);

  if (_productType.getType() != type->getValue()) {
    errors.push_back(Error(ERROR_TYPES::NOT_FOUND,
                           "Такой тип продукта не может быть задан"));
    return;
  }

  Product newProduct = this->productModel.create(
      {
          type,
          price,
          name,
      },
      errors);

  cout << "Before couting new product" << endl;
  cout << newProduct << endl;

  StringFieldORM *searchField = new StringFieldORM("productID");
  StringFieldORM *replaceField =
      new StringFieldORM("productID", newProduct.getId());

  IntFieldORM *amount = new IntFieldORM(
      "amount", this->providerModel->getProductsAmount() + productAmount);
  cout << "Amount: " << amount->getValue() << endl;
  cout << "Search field: " << searchField->getValue() << endl;
  cout << "Repalce field: " << replaceField->getValue() << endl;

  this->providerModel =
      new Provider(this->providerModel->updateOne<StringFieldORM>(
          searchField, {
                           replaceField,
                           amount,
                       }));

  cout << "After changing provider model" << endl;

  delete searchField;
  delete replaceField;
  delete amount;

  cout << "Пополнение на складе успешно!" << endl;
}
