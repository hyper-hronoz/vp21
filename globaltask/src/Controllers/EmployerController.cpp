#include "EmployerController.h"
#include "algorithm"
#include "vector"

#include "../Exceptions/NegativeIndexException.h"
#include "StartController.h"

void EmployerController::goBack() { StartController(); }

void EmployerController::produceProduct() {
  cout << "====Доступные продукты сырье====" << endl;

  vector<Product *> products{};
  for (auto item : this->productModel) {
    if (item.size() != 0) {
      Product *pt = new Product(item);
      cout << *pt << endl;
      products.push_back(pt);
    }
  }

  StringFieldORM *productName = new StringFieldORM("name");
  IntFieldORM *oldProductAmount = new IntFieldORM("oldProductAmount");

  cout << "Введите имя продукта: ";
  cin >> productName;

  vector<AFieldORM *> productFields =
      this->productModel.findOne<StringFieldORM>(productName);

  if (productFields.size() == 0) {
    cout << "Ничего не вышло, такого продукта нет" << endl;
    return;
  }

  Product product = productFields;

  StringFieldORM *searchProduct =
      new StringFieldORM("productID", product.getId());
  vector<AFieldORM *> providerFields =
      this->providerModel.findOne<StringFieldORM>(searchProduct);
  delete searchProduct;

  if (providerFields.size() == 0) {
    cout << "Такого поставщика уже нет" << endl;
    return;
  }

  Provider provider = providerFields;

  cout << "Введите количество сырья кторое, нужно переработать: ";
  cin >> oldProductAmount;

  if (provider.getProductsAmount() - oldProductAmount->getValue() < 0) {
    cout << "Нет необходимого количества сырья: "
         << provider.getProductsAmount() << " - max" << endl;
    return;
  }

  StringFieldORM *updatePattern = new StringFieldORM("_id", provider.getId());
  IntFieldORM *amount = new IntFieldORM(
      "amount", provider.getProductsAmount() - oldProductAmount->getValue());
  vector<AFieldORM *> status =
      this->providerModel.updateOne<StringFieldORM>(updatePattern, {amount});
  delete updatePattern;

  if (status.size() == 0) {
    cout << "Не удалось обновить данные у поставщика" << endl;
    return;
  }

  cout << "Введите количество произведенных продуктов: ";
  cin >> amount;

  StringFieldORM *searchEmployer =
      new StringFieldORM("_id", this->employerModel->getId());
  IntFieldORM *newEmployerAmount = new IntFieldORM(
      "amount", this->employerModel->getAmount() + amount->getValue());
  status = this->employerModel->updateOne<StringFieldORM>(searchEmployer,
                                                          {newEmployerAmount});
  delete searchEmployer;

  if (status.size() == 0) {
    cout << "Не удалось обновить сотрудника" << endl;
    return;
  }

  this->employerModel = new Employer(status);

  StringFieldORM *newProductType = new StringFieldORM("type");
  StringFieldORM *newProductName = new StringFieldORM("name");
  IntFieldORM *newProductPrice = new IntFieldORM("price");

  cout << "Имя нового продукта: ";
  cin >> newProductName;
  cout << "Тип нового продукта: ";
  cin >> newProductType;
  cout << "Цена нового продукта: ";
  cin >> newProductPrice;

  vector<Error> errors{};

  cout << "Creating new product" << endl;
  Product newProduct = this->productModel.create(
      {newProductName, newProductType, newProductPrice}, errors);

  if (errors.size() != 0) {
    for (Error error : errors) {
      cout << error.getMessage() << endl;
    }
    return;
  }

  StringFieldORM *providerID =
      new StringFieldORM("providerID", provider.getId());
  StringFieldORM *newProductID =
      new StringFieldORM("newProductID", newProduct.getId());
  StringFieldORM *oldProductID =
      new StringFieldORM("oldProductID", product.getId());
  IntFieldORM *newProductAmount =
      new IntFieldORM("newProductAmount", amount->getValue());

  this->productionTransactionModel.create(
      {
          providerID,
          newProductID,
          newProductAmount,
          oldProductID,
          oldProductAmount,
      },
      errors);

  if (errors.size() != 0) {
    for (Error error : errors) {
      cout << error.getMessage() << endl;
    }
    return;
  }

  cout << "Произведено успешно" << endl;

  for (Product *product : products) {
    delete product;
  }

  products.clear();

  delete productName;
}

void EmployerController::printInfo() {
  this->view->printEmployer(this->employerModel);
}

void EmployerController::deleteAccount() {
  StringFieldORM *query =
      new StringFieldORM("email", this->employerModel->getEmail());
  this->employerModel->deleteOne<StringFieldORM>(query);
  StartController _;
  delete query;
}

void EmployerController::updateAccount() {
  try {
    char y = 'n';
    cout << "Хотите обновить сотрудника(y/n)?: ";
    cin >> y;
    if (y == 'y') {
      cout << "Обновляем строковое поле..." << endl;
      vector<AFieldORM *> fields = {};
      for (auto item : *this->employerModel) {
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
          new StringFieldORM("_id", this->employerModel->getId());
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

      this->employerModel =
          new Employer(this->employerModel->updateOne<StringFieldORM>(
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
}
