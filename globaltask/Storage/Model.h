#include "vector"

template<class T>
class Model {
 private:
    const char* type;
 protected:

    Model();

    virtual T* findOne(T *t);

    virtual std::vector<T*> getAll();

    virtual void save();

    T getType();
};

