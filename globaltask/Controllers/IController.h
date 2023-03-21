#pragma once

template<class VIEW>
class IController {
 protected:
     VIEW* view;

 public:
    virtual void run() = 0;

    template<class T> T* getInstance() {
        return dynamic_cast<T*>(this);
    }

    ~IController() {
        // delete view;
    }
};
