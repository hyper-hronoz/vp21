#include <algorithm>
#include <ctime>
#include <functional>
#include <iostream>
#include <set>
#include <stdarg.h>
#include <vector>

using namespace std;

const int SIZE = 100;

template <class T> class IComparator {
 public:
  virtual bool operator()(T const &a, T const &b) const = 0;
};

template <class T> class DownComparator : public IComparator<T> {
 public:
  bool operator()(T const &a, T const &b) const override { return a > b; }
};

template <class T> class UpComparator : public IComparator<T> {
 public:
  bool operator()(T const &a, T const &b) const override { return a < b; }
};

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
    std::cout << endl;
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
      cout << endl;
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

  void initilizeWithList(initializer_list<T> temp) { this->storage = temp; }

  void setMultiset(std::multiset<T> target) { this->storage = target; }

  template <class C> void printAndSort(std::multiset<T> target) {
    vector<T> temp = this->sortDown<C>(target);

    int i = 1;
    for (auto item : temp) {
      cout << item << " ";
      if (i % 11 == 0) {
        cout << endl;
      }
      i++;
    }
    cout << endl;
  }

  template <class C> void printAndSort() {
    vector<T> temp = this->sortDown<C>();

    int i = 1;
    for (auto item : temp) {
      cout << item << " ";
      if (i % 11 == 0) {
        cout << endl;
      }
      i++;
    }
    cout << endl;
  }

  void printStorage(std::multiset<T> temp) {
    std::multiset<T> copy = this->storage;
    this->storage = temp;
    this->printStorage();
    this->storage = copy;
  }

  void printStorage(vector<T> temp) {
    int i = 1;
    for (auto item : temp) {
      if (i % 11 == 0) {
        cout << endl;
      }
      cout << item << " ";
      i++;
    }
    cout << endl;
  }

  template <class C> std::vector<T> sortDown() {
    std::vector<T> output(this->storage.size());
    std::copy(this->storage.begin(), this->storage.end(), output.begin());
    std::sort(output.begin(), output.end(), C());
    return output;
  }

  template <class C> std::vector<T> sortDown(std::multiset<T> temp) {
    std::multiset<T> copy = this->storage;
    this->storage = temp;
    auto res = this->sortDown<C>();
    this->storage = copy;
    return res;
  }

  std::multiset<T> filterTo(std::multiset<T> set, bool (*condition)(T)) {
    std::multiset<T> temp;
    for (auto item : set) {
      if (condition(item)) {
        temp.insert(item);
      }
    }
    return temp;
  }

  std::multiset<T> filterTo(bool (*condition)(T)) {
    std::multiset<T> temp;
    for (auto item : this->storage) {
      if (condition(item)) {
        temp.insert(item);
      }
    }
    return temp;
  }

  T findOne(std::multiset<T> set, bool (*condition)(T)) {
    for (auto item : set) {
      if (condition(item)) {
        return item;
      }
    }
    return {};
  }

  T findOne(bool (*condition)(T)) {
    for (auto item : this->storage) {
      if (condition(item)) {
        return item;
      }
    }
    return {};
  }

  std::multiset<T> merge(initializer_list<std::multiset<T>> list) {
    std::multiset<T> res;
    for (auto set : list) {
      for (auto item : set) {
        res.insert(item);
      }
    }
    return res;
  }
};

int main() {
  srand(time(nullptr));

  Program<int> program;

  program.initilizeWithList(
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20});

  cout << "Иходники: ";
  program.printStorage();
  cout << "Удаляем все после 10: ";
  program.deleteAfter(10);
  cout << "Что стало: ";
  program.printStorage();
  cout << "От 0 до 4: ";
  program.printStorageByRange(0, 4);

  cout << "Сортировано по наклонной: ";
  program.printAndSort<DownComparator<int>>();

  cout << "Найти один: ";
  cout << program.findOne([](int a) {
    if (a == 2) {
      return true;
    }
    return false;
  }) << endl;

  cout << "По условию все четные: ";
  multiset<int> newSet = program.filterTo([](int a) {
    if (a % 2 == 0) {
      return true;
    }
    return false;
  });

  program.printStorage(newSet);

  cout << "Сортируем оба котейнера по возрастанию: " << endl;
  program.printStorage(program.sortDown<UpComparator<int>>());
  program.printStorage(program.sortDown<UpComparator<int>>(newSet));

  cout << "Merged: ";
  std::multiset<int> set = program.merge({program.getStorage(), newSet});
  program.printStorage(set);

  cout << "Condition amount: ";
  cout << program.filterTo(set, [](int a) {
    if (a % 3 == 0) {
      return true;
    }
    return false;
  }).size() << endl;

  cout << "Элемент 3 по условию: ";
  cout << program.findOne(set, [](int a) {
    if (a == 3) {
      return true;
    }
    return false;
  }) << endl;

  return 0;
}
