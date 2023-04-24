#include "ProductTypeView.h"

void ProductTypeView::printModel() {
  cout << "--Product Type--";
  cout << this->model << endl;
}

void ProductTypeView::update() { printModel(); }
