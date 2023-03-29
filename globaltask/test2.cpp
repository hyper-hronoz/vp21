#include <iostream>
#include <vector>

using namespace std;

class C {
 private:
  string name;
 public:
  C(string name) : name(name) {}

  virtual void doWork() {
    cout << this->name << " " << endl;
  }
};

class B : public C {
 public:
  B(string name) : C(name) {}

  void doWork() override {
    cout << " Fuck " << endl;
  }
};

class A {
 private:
  vector<C> v;
 public:
  A(initializer_list<C> list) : v(list) {}
};


int main (int argc, char *argv[])
{

  A({
    B("Vlad"),
  });

  return 0;
}
