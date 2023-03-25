#pragma once

#include "iostream"
#include "string"
#include "./Storage/BinaryModel.h"
#include "./Storage/Model.h"
#include "./Storage/Storage.h"
#include "./Storage/StorageCallback.h"

template<class MODEL>
class AUser : public Model<MODEL> {
 protected:
    std::string name;
    std::string sername;

    int age;

    std::string login;
    std::string password;

 public:
    virtual AUser<MODEL>* setName(std::string name) {
        this->name = name;
        return this;
    }

    virtual AUser<MODEL>* setSername(std::string sername) {
        this->sername = sername;
        return this;
    }

    virtual AUser<MODEL>* setLogin(std::string login) {
        this->login = login;
        return this;
    }

    virtual AUser<MODEL>* setPassword(std::string password) {
        this->password = password;
        return this;
    }

    virtual std::string getLogin() {
        return this->login;
    }

    virtual std::string getPassword() {
        return this->password;
    }

    virtual int getAge() {
        return this->age;
    }

    void save() override {
    }
};
