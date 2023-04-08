#include <algorithm> // std::sort
#include <iostream>  // std::cout
#include <vector>    // std::vector
                     //
using namespace std;

struct Person {
  string name;
  int age;

  Person(string name, int age) {
    this->name = name;
    this->age = age;
  }
};


class Fuck {
 private:
  std::vector<Person> myvector{Person("Dragon", 22), Person("Putin", 21), Person("Zombie", 199), Person("Vlad", 12), Person("Alice", 20), }; // create vector from array
  static bool compareFunction(Person a, Person b) { return a.name < b.name; }
 public:
  Fuck() {
  std::sort(myvector.begin(), myvector.end(),
            compareFunction); // sort the vector

  for (auto& person : myvector) {
    cout << person.name << endl;
  }

  }
};

int main() {
  Fuck();

  return 0;
}
