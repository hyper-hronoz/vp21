#include "DirectorController.h"

void DirectorController::onSelectSuppliedProducts() {
  cout << "Список всез поставок: " << endl;
  int i = 0;
  for (ProductTransaction pt : this->productTransactionModel) {
    StringFieldORM *searchProduct = new StringFieldORM(pt.getProductId());
    StringFieldORM *searchProvider = new StringFieldORM(pt.getProductId());

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
