#include "iostream"
#include "./Storage/Model.h"

template<class T>
class AUser : public Model<T> {
 protected:
    std::string name;
    std::string sername;

    int age;

    std::string login;
    std::string password;

 public:
    virtual void signUp() = 0;

    virtual AUser<T> setName(std::string name) {
        this->name = name;
        return this;
    }

    virtual AUser<T> setSername(std::string sername) {
        this->sername = sername;
        return this;
    }

    virtual AUser<T> setLogin(std::string login) {
        this->login = login;
        return this;
    }

    virtual AUser<T> setPassword(std::string password) {
        this->password = password;
    }
};

