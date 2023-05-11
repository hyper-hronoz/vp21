#include <ctime>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int SIZE = 100;

template <class T> class Program {
private:
  std::multiset<T> storage;

public:
  explicit Program(multiset<T> storage) : storage(storage) {}
  Program() {}
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

  multiset<T> copyContainer() {
    multiset<int> copy = this->storage;
    return copy;
  }

  multiset<T> getStorage() { return this->storage; }

  void fillContainerByVector(vector<T> v) {
    this->storage.clear();
    for (auto item : v) {
      this->storage.insert(item);
    }
  }

  void repalceContainer(std::multiset<T> newStorage) {
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

  multiset<T> concatStorage(std::multiset<T> a, std::multiset<T> b) {
    for (auto item : b) {
      a.insert(item);
    }
    return a;
  }

  void initilizeWithList(initializer_list<T> temp) {
    this->storage = temp;
  }

  void setMultiset(std::multiset<T> target) { this->storage = target; }
};

int main() {
  srand(time(nullptr));

  Program<char> program;

  program.initilizeWithList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20});

  program.printStorage();
  program.deleteAfter(10);
  program.printStorage();
  program.printStorageByRange(0, 4);

  return 0;
}
