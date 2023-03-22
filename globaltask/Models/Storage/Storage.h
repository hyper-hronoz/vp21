#pragma once


class Storage
{
private: 
    Storage() {}
    Storage( const Storage&);  
    Storage& operator=( Storage& );

public:
    static Storage& getInstance() {
        static Storage instance;
        return instance;
    }    

    template<class T> void save(T* t);
    template<class T> T* get(T t);
};
