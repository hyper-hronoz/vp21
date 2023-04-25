#include <iostream>

using namespace std;

class StrIterator {
 private:
  char *m_symbol{};
  StrIterator(char *p) : m_symbol(p) {}
  friend class MyString;

 public:
  StrIterator(const StrIterator &it) : m_symbol(it.m_symbol) {}
  bool operator==(const StrIterator &it) const {
    return m_symbol == it.m_symbol;
  }
  bool operator!=(const StrIterator &it) const {
    return m_symbol != it.m_symbol;
  }
  StrIterator &operator++() {
    ++m_symbol;
    return *this;
  }
  char &operator*() const { return *m_symbol; }
};

int main() { return 0; }
