#include "DirectorController.h"
#include "StartController.h"


void DirectorController::onSelectSuppliedProducts() {
  cout << "Список всез поставок: " << endl;
  int i = 0;
  for (ProductTransaction pt : this->productTransactionModel) {
    cout << pt << endl;
    StringFieldORM *searchProduct = new StringFieldORM(pt.getProductId());
    StringFieldORM *searchProvider = new StringFieldORM(pt.getProviderId());

    cout << "Ids: " << pt.getProviderId() << " " << pt.getProductId() << endl;

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
