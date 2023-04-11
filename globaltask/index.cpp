#include<iostream>

#include "./src/Controllers/StartController.h"
#include "./src/Controllers/AuthenticationController.h"
#include "./src/Controllers/ProviderController.h"
#include "./src/initializers/ProductTypeInitilizer.h"

using namespace std;

int main() {
  ProductTypeInitilizer().initilizeProductTypes();
  // AuthenticationController();
  ProviderController();
  return 0;
}
