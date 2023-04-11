#include<iostream>

#include "./src/Controllers/StartController.h"
#include "./src/Controllers/AuthenticationController.h"
#include "./src/initializers/ProductTypeInitilizer.h"

using namespace std;

int main() {
  ProductTypeInitilizer().initilizeProductTypes();
  StartController();
  // AuthenticationController();
  return 0;
}
