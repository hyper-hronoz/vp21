#pragma once
#include <string>


#include "iostream"
// #include "ASaveStorageCallback.h"
// #include "ASaveStorageCallback.h"
#include "StorageCallback.h"

class Storage {
    const std::string DB_FOLDER = "./database/";

 private:
    Storage() {}
    Storage(const Storage&);
    Storage& operator=(Storage&);

 public:
    static Storage& getInstance() {
        static Storage instance;
        return instance;
    }

    template<class SavingModel, class Callback = StorageCallback<SavingModel>> void get(SavingModel* model) {
        try {
        } catch (std::exception const& e) {
            std::cout << e.what() << std::endl;
        }
    }

    template<class SavingModel, class Callback = StorageCallback<SavingModel>> void save(SavingModel* model) {
        try {
            system("mkdir -p ./database");

            std::fstream *file = new std::fstream(DB_FOLDER +
            static_cast<std::string> (typeid(SavingModel).name()),
            std::ios::out | std::ios::in | std::ios::binary);

            Callback* callback = new Callback(model, file);
            callback->exec();

            file->close();

            delete callback;
        } catch (std::exception const& e) {
            std::cout << e.what() << std::endl;
        }
    }
};
