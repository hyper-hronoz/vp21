#include "Storage.h"
#include "iostream"
#include "fstream"


template<class T> void Storage::save(T t) {
    try {
        // std::ofstream file(*"../../database" + typeid(T).name(), std::ios::out | std::ios::binary);
        //
        // file.write(reinterpret_cast<char*>(&t), sizeof(T));
        //
        // file.close();
    } catch (std::exception const& e) {
        std::cout << e.what() << std::endl;
    }
}

template<class T> T Storage::get(T t) { }
