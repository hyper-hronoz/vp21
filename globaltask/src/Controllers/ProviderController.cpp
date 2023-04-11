#include "ProviderController.h"
#include "algorithm"
#include "vector"

#include "StartController.h"

void ProviderController::goBack() { StartController(); }

bool comparator(ProductType *pt1, ProductType *pt2) { return *pt1 < *pt2; }

void ProviderController::getAllProductTypes() {
  vector<ProductType *> pts;
  for (auto &model : this->model.find()) {
    ProductType *pt = new ProductType(model);
    pts.push_back(pt);
  }
  sort(pts.begin(), pts.end(), comparator);
  for (auto &model : pts) {
    cout << *model << endl;
  }
}
