#include<iostream>

#include "./src/Controllers/StartController.h"
#include "./src/Controllers/AuthenticationController.h"
#include "./src/Controllers/ProviderController.h"
#include "./src/initializers/ProductTypeInitilizer.h"
#include "./src/Models/ProductType.h"

int main() {
  ProductTypeInitilizer().initilizeProductTypes();
  ProductType pt;
  for (auto item : pt) {
    cout << item << endl;
  }
  StartController _;
  return 0;
}
