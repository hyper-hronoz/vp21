#include <ctime>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int SIZE = 100;

class Program {
private:
  std::multiset<int> storage;

public:
  Program() { this->storage = this->createNewContainer(); }

  void printStorage() {
    int i = 1;
    for (auto item : this->storage) {
      cout << item << " ";
      if (i % 11 == 0) {
        cout << endl;
      }
      i++;
    }
  }

  void printStorageByRange(int from, int to) {
    try {
      int i = from;
      int j = 1;
      if (from > this->storage.size() || to > this->storage.size()) {
        throw out_of_range(
            &"from or to is out of range: maximal range is "[this->storage
                                                                 .size()]);
      }
      for (auto item : this->storage) {
        if (from <= i && i <= to) {
          cout << item << " ";
        }
        if (j % 11 == 0) {
          cout << endl;
        }
        i++;
        j++;
      }
    } catch (std::out_of_range &e) {
      cout << e.what() << endl;
    }
  }

  multiset<int> copyContainer() {
    multiset<int> copy = this->storage;
    return copy;
  }

  multiset<int> getStorage() { return this->storage; }

  multiset<int> createNewContainer() {
    multiset<int> temp;
    for (int i = 0; i < SIZE; i++) {
      temp.insert(rand() % 1000);
    }
    return temp;
  }

  void fillContainerByVector(vector<int> v) {
    this->storage.clear();
    for (auto item : v) {
      this->storage.insert(item);
    }
  }

  void repalceContainer(std::multiset<int> newStorage) {
    this->storage = newStorage;
  }

  void deleteAfter(int from) {
    try {
      int i = 0;
      if (from > this->storage.size()) {
        throw out_of_range("from is out of range");
      }
      vector<int> temp;
      for (auto item : this->storage) {
        if (i >= from) {
          temp.push_back(item);
        }
        i++;
      }
      for (auto item : temp) {
        this->storage.erase(item);
      }
    } catch (std::out_of_range &e) {
      cout << e.what() << endl;
    }
  }

  multiset<int> concatStorage(std::multiset<int> a, std::multiset<int> b) {
    for (auto item : b) {
      a.insert(item);
    }
    return a;
  }

  void setMultiset(std::multiset<int> target) { this->storage = target; }
};

int main() {
  srand(time(nullptr));
  Program program;

  program.printStorage();
  program.deleteAfter(10);
  program.printStorage();
  program.printStorageByRange(0, 4);

  return 0;
}
