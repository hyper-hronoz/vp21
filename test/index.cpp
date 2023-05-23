#include <iostream>
#include <iterator>
#include <set>
#include <vector>

using namespace std;

struct CompareDown {
  bool operator()(const int lhs, const int rhs) const /* noexcept */ {
    return lhs > rhs;
  }
};

template <class T> class MultisetContainer : public multiset<T> {
protected:
  int maxItemsInRow = 11;

public:
  using multiset<T>::multiset;
  using multiset<T>::begin;
  using multiset<T>::end;

  void printStorage() {
    int i = 1;
    for (auto item : *this) {
      cout << item << " ";
      if (i % this->maxItemsInRow == 0) {
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
      if (from > this->size()) {
        throw out_of_range("from is out of range");
      }
      vector<int> temp;
      for (auto item : *this) {
        if (i >= from) {
          temp.push_back(item);
        }
        i++;
      }
      for (auto item : temp) {
        this->erase(item);
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

  // void initilizeWithList(initializer_list<T> temp) { this->storage = temp; }
  //
  // void setMultiset(std::multiset<T> target) { this->storage = target; }

  // template <class C> void printAndSort(std::multiset<T> target) {
  //   vector<T> temp = this->sortDown<C>(target);
  //
  //   int i = 1;
  //   for (auto item : temp) {
  //     cout << item << " ";
  //     if (i % 11 == 0) {
  //       cout << endl;
  //     }
  //     i++;
  //   }
  //   cout << endl;
  // }
  //
  // template <class C> void printAndSort() {
  //   vector<T> temp = this->sortDown<C>();
  //
  //   int i = 1;
  //   for (auto item : temp) {
  //     cout << item << " ";
  //     if (i % 11 == 0) {
  //       cout << endl;
  //     }
  //     i++;
  //   }
  //   cout << endl;
  // }
  //
  // void printStorage(std::multiset<T> temp) {
  //   std::multiset<T> copy = this->storage;
  //   this->storage = temp;
  //   this->printStorage();
  //   this->storage = copy;
  // }
  //
  // void printStorage(vector<T> temp) {
  //   int i = 1;
  //   for (auto item : temp) {
  //     if (i % 11 == 0) {
  //       cout << endl;
  //     }
  //     cout << item << " ";
  //     i++;
  //   }
  //   cout << endl;
  // }
  //
  // template <class C> std::vector<T> sortDown() {
  //   std::vector<T> output(this->storage.size());
  //   std::copy(this->storage.begin(), this->storage.end(), output.begin());
  //   std::sort(output.begin(), output.end(), C());
  //   return output;
  // }
  //
  // template <class C> std::vector<T> sortDown(std::multiset<T> temp) {
  //   std::multiset<T> copy = this->storage;
  //   this->storage = temp;
  //   auto res = this->sortDown<C>();
  //   this->storage = copy;
  //   return res;
  // }
  //
  // std::multiset<T> filterTo(std::multiset<T> set, bool (*condition)(T)) {
  //   std::multiset<T> temp;
  //   for (auto item : set) {
  //     if (condition(item)) {
  //       temp.insert(item);
  //     }
  //   }
  //   return temp;
  // }
  //
  // std::multiset<T> filterTo(bool (*condition)(T)) {
  //   std::multiset<T> temp;
  //   for (auto item : this->storage) {
  //     if (condition(item)) {
  //       temp.insert(item);
  //     }
  //   }
  //   return temp;
  // }
  //
  // T findOne(std::multiset<T> set, bool (*condition)(T)) {
  //   for (auto item : set) {
  //     if (condition(item)) {
  //       return item;
  //     }
  //   }
  //   return {};
  // }
  //
  // T findOne(bool (*condition)(T)) {
  //   for (auto item : this->storage) {
  //     if (condition(item)) {
  //       return item;
  //     }
  //   }
  //   return {};
  // }
  //
  // std::multiset<T> merge(initializer_list<std::multiset<T>> list) {
  //   std::multiset<T> res;
  //   for (auto set : list) {
  //     for (auto item : set) {
  //       res.insert(item);
  //     }
  //   }
  //   return res;
  // }
};

template <class T> class DownMultiset : multiset<T, CompareDown> {
public:
  using multiset<T, CompareDown>::multiset;
  using multiset<T, CompareDown>::begin;
  using multiset<T, CompareDown>::end;
  void operator=(multiset<T> &fuck) {
    this->clear();
    for (auto item : fuck) {
      this->insert(item);
    }
  };
};

int main() {
  MultisetContainer<int> data = {1, 2, 3, 4, 5};

  data.printStorage();
}
