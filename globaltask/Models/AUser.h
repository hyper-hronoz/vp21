#pragma once

#include "iostream"
#include "string"
#include "./Storage/BinaryModel.h"
#include "./Storage/Model.h"
#include "./Storage/Storage.h"
#include "./Storage/ASaveStorageCallback.h"

template<class T>
class AUser : public Model<T> {
 protected:
    std::string name;
    std::string sername;

    int age;

    std::string login;
    std::string password;

 public:
    virtual AUser<T>* setName(std::string name) {
        this->name = name;
        return this;
    }

    virtual AUser<T>* setSername(std::string sername) {
        this->sername = sername;
        return this;
    }

    virtual AUser<T>* setLogin(std::string login) {
        this->login = login;
        return this;
    }

    virtual AUser<T>* setPassword(std::string password) {
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

    class Savier : public ASaveStorageCallback<AUser<T>> {
     public:
        Savier(T* t, std::ofstream stream) :
            ASaveStorageCallback<AUser<T>>(t, stream) {}

        void exec() override {
            size_t size = this->getModel().getLogin().size();
            this->getStrem().write(&this->getModel().getLogin, sizeof(size));
            this->getStrem().write(&this->getModel.getLogin()[0], size);
        }
    };

    void save() override {
        Storage::getInstance().save<AUser<T>>(this, Savier);
    }
};
