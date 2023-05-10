#include "DirectorController.h"
#include "StartController.h"


void DirectorController::onSelectSuppliedProductsEmployer() {
  cout << "Полный список как производят на заводе" << endl;
  for (auto item : this->productionTransactionModel) {
    if (item.size() != 0) {
      ProductionTransaction *transaction = new ProductionTransaction(item);
      cout << *transaction << endl;
    }
  }
}

void DirectorController::onSelectSuppliedProducts() {
  cout << "Список всез поставок: " << endl;
  int i = 0;
  for (auto item : this->productTransactionModel) {
    if (item.size() == 0) {
      continue;
    }

    ProductTransaction pt = item;
    cout << pt << endl;
    StringFieldORM *searchProduct = new StringFieldORM("_id", pt.getProductId());
    StringFieldORM *searchProvider = new StringFieldORM("_id", pt.getProviderId());

    Product product = this->productModel.findOne<StringFieldORM>(searchProduct);
    Provider provider =
        this->providerModel.findOne<StringFieldORM>(searchProvider);

    cout << "Транзакция №" << i << endl;

    cout << "====Поставленный продукт====" << endl;
    cout << product << endl;
    cout << "====Поставщик продукта====" << endl;
    cout << provider << endl;

    cout << "Конец транзакции" << endl;

    delete searchProduct;
    delete searchProvider;
    i++;
  }
}

void DirectorController::goBack() {
  StartController _;
}

void DirectorController::deleteAccount() {
  StringFieldORM *query =
      new StringFieldORM("email", this->directorModel->getEmail());
  this->directorModel->deleteOne<StringFieldORM>(query);
  StartController _;
  delete query;
}
