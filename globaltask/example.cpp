
#include "iostream"
#define ll long long
using namespace std;

// Template class to create vector of
// different data_type
template <typename DT> class DBData {
private:
  DT *arr;
  ll capacity;
  ll length;

public:
  explicit DBData(ll = 100);
  ll push_back(DT);

  DT pop_back();

  ll size() const;
  DT &operator[](ll);

  class Iterator {
  private:
    DT *ptr;

  public:
    explicit Iterator() : ptr(nullptr) {}
    explicit Iterator(DT *p) : ptr(p) {}
    bool operator==(const Iterator &rhs) const { return ptr == rhs.ptr; }
    bool operator!=(const Iterator &rhs) const { return !(*this == rhs); }
    DT& operator*() const { return *ptr; }
    Iterator &operator++() {
      ++ptr;
      return *this;
    }
    Iterator operator++(int) {
      Iterator temp(*this);
      ++*this;
      return temp;
    }
  };

  Iterator begin() const;

  Iterator end() const;
};

template <typename DT>
DBData<DT>::DBData(ll n)
    : capacity(n), arr(new DT[n]), length(0) {}

template <typename DT> ll DBData<DT>::push_back(DT data) {
  if (length == capacity) {
    DT *old = arr;
    arr = new DT[capacity = capacity * 2];
    copy(old, old + length, arr);
    delete[] old;
  }
  arr[length++] = data;
  return length;
}

template <typename DT> DT DBData<DT>::pop_back() {
  return arr[length-- - 1];
}

template <typename DT> ll DBData<DT>::size() const { return length; }

template <typename DT> DT &DBData<DT>::operator[](ll index) {
  if (index >= length) {
    cout << "Error: Array index out of bound";
    exit(0);
  }

  return *(arr + index);
}

template <typename DT>
typename DBData<DT>::Iterator DBData<DT>::begin() const {
  return Iterator(arr);
}

template <typename DT>
typename DBData<DT>::Iterator DBData<DT>::end() const {
  return Iterator(arr + length);
}

template <typename V> void display_vector(V &v) {
  typename V::iterator ptr;
  for (ptr = v.begin(); ptr != v.end(); ptr++) {
    cout << *ptr << ' ';
  }
  cout << '\n';
}

int main() {
  DBData<char> c;
  c.push_back('a');
  c.push_back('b');
  c.push_back('c');
  c.push_back('d');
  c.push_back('e');
  c.push_back('f');
  c.push_back('g');
  c.push_back('h');

  for (auto item : c) {
    cout << "That is item: " << item << endl;
  }
  return 0;
}
