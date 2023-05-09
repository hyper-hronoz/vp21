#include<iostream>

#include "./src/Controllers/StartController.h"
#include "./src/Controllers/AuthenticationController.h"
#include "./src/Controllers/ProviderController.h"
#include "./src/initializers/ProductTypeInitilizer.h"
#include "./src/Models/ProductType.h"
#include "./src/Models/ProductTransaction.h"

int main() {
  ProductTypeInitilizer().initilizeProductTypes();

  StartController _;

  return 0;
}
