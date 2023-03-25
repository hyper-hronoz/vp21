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

    class Savier : public StorageCallback<AUser<MODEL>> {
     public:
        Savier(AUser<MODEL>* model, std::fstream* stream) :
            StorageCallback<AUser<MODEL>>(model, stream) {}


        void exec() override {
            std::cout << "Writing to storage" << std::endl;
            this->writeLogin();
        }

     private:
        void writeLogin() {
            std::string loginString = (this->getModel()->getLogin());

            size_t size = loginString.size();
            this->getStream()->write((char*)(&size), sizeof(size));
            this->getStream()->write((char*)(loginString.c_str()), size);
        }
    };

    class Getter : public StorageCallback<AUser<MODEL>> {
     public:
        Getter(AUser<MODEL>* model, std::fstream* stream) :
            StorageCallback<AUser<MODEL>>(model, stream) {

            }

        void exec() override {
            this->readLogin();
        }

     private:
        void readLogin() {
            std::string loginString;;
            size_t size;
            this->getStream()->read(&size, sizeof(size));
        }
    };

    void save() override {
        Storage::getInstance().save<AUser<MODEL>, Savier>(this);
        // Storage::getInstance().get<AUser<MODEL>, Savier>(this);
    }
};
