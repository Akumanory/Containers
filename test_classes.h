#include <string>

class Test_Class {
public:
    Test_Class() {}
    Test_Class(int test_int, 
             int test_int2)
            : test_int(test_int)
            , test_int2(test_int2)
        {}

    ~Test_Class() noexcept {}

    int test_int;
    int test_int2;
};