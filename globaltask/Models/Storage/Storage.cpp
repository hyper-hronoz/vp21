#include "Storage.h"
#include "fstream"

const std::string DB_FOLDER = "./database/";

template<class T> T* Storage::get(T t) {
    try {
        // T* data = new T();
        //
        // std::ifstream file(DB_FOLDER + static_cast<std::string>(typeid(T).name()), std::ios::in | std::ios::binary);
        //
        // t.read(data);
        //
        // file.close();
    } catch(std::exception const& e) {
        std::cout << e.what() << std::endl;
    }
}

template<class T> void Storage::save(T* t, ASaveStorageCallback<T>* callback) {
    try {
        system("mkdir -p ./database");

        std::ofstream file(DB_FOLDER + static_cast<std::string>
                (typeid(T).name()), std::ios::out | std::ios::binary);

        callback(t, file).exec();

        file.close();
    } catch (std::exception const& e) {
        std::cout << e.what() << std::endl;
    }
}
