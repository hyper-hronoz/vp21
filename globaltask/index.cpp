#include<iostream>
#include<fstream>

#include "Controllers/StartController.h"
#include "Views/StartView.h"

using namespace std;

int main() {
    StartController(StartView());
}
