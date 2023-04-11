#include<iostream>

#include "./src/Controllers/StartController.h"
#include "./src/Controllers/SecondLabController.h"
#include "./src/initializers/ProductTypeInitilizer.h"

using namespace std;

int main() {
  ProductTypeInitilizer().initilizeProductTypes();
  // StartController();
  SecondLabController();
  return 0;
}
