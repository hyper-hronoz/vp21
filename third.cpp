#include <ctime>
#include <iostream>

class Integers {
private:
  int m_data[200];

public:
  class Iterator {
  private:
    int *m_ptr;

  public:
    explicit Iterator(int *ptr) : m_ptr(ptr) {}

    int &operator*() const { return *m_ptr; }

    Iterator &operator++() {
      m_ptr++;
      return *this;
    }

    Iterator operator++(int) {
      Iterator tmp = *this;
      ++(*this);
      return tmp;
    }

    friend bool operator!=(const Iterator &a, const Iterator &b) {
      return a.m_ptr != b.m_ptr;
    }
  };

  Iterator begin() { return Iterator(&m_data[0]); }
  Iterator end() { return Iterator(&m_data[200]); }
};

int main() {
  srand(time(nullptr));
  Integers integers;

  for (int &item : integers) {
    item = rand() % 10000;
  }

  // for (int item : integers) {
  //   std::cout << item << std::endl;
  // }

  for (auto it = integers.begin(), end = integers.end(); it != end; it++) {
    const auto i = *it;
    std::cout << i << "\n";
  }

  return 0;
}
