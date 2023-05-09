#pragma once
#include <string>

namespace MM {
    class MyMenuItems
    {
    private:
        std::string header;
        typedef int (*Func)();
        Func func;
    public:
        std::string getHeader();
        void setHeader(std::string header);
        MyMenuItems();
        MyMenuItems(std::string header, Func func);
        int getFunc();
    };
};
