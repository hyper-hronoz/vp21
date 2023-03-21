#include "vector"
#include <typeinfo>

template<class T>
class Model {
 private:
    const char* type = typeid(T).name();
 protected:
    Model();

    virtual T* findOne(T *t);

    virtual std::vector<T*> getAll();

    virtual void save();

    T getType();
};

