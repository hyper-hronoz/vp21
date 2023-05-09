#include <iostream>
#include "MyMenuItems.h"

std::string MM::MyMenuItems::getHeader() {
	return header;
}
void MM::MyMenuItems::setHeader(std::string header) {
	this->header = header;
}

MM::MyMenuItems::MyMenuItems(std::string header, Func func) {
	this->header = header;
	this->func = func;
}

int MM::MyMenuItems::getFunc() {
	return func();
}

