#include"patterns.hpp"

namespace pattern {

    std::vector<std::vector<std::string>> rpatterns = {
        {"std::__cxx11::basic_string<char>", "string"},
        {"std::basic_string<char,std::char_traits<char>,std::allocator<char>>", "string"},
        {"std::map<_Key, _Tp, _Compare, _Alloc>::map", "map"},
        {" {aka ‘string’}", ""},
        {" {aka string}", ""},
    };

    std::vector<std::vector<std::string>> cpatterns = {
        {"note:", "\x1B[36m"},
        {"error:", "\x1B[31m"},
        {"warn:", "\x1B[33m"},
        {"warning:", "\x1B[35m"}
    };

}