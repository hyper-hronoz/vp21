#pragma once

class Storage {
 public:
    template<class T> void save(T t);

    template<class T> T get(T t);
};
