#include "iostream"
#include "Model.h"

template<class T>
class AUser : public Model<T> {
 protected:
    std::string name;
    std::string sername;

    int age;

    std::string login;
    std::string password;

 public:
    virtual void registrate() = 0;
};

