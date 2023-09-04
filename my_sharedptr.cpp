/**
* @file my_sharedptr.cpp
* @brief 
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-01
*/
#include <iostream>

namespace kinvy {

template<typename T>
class shared_ptr {
public:
    shared_ptr() : ptr(nullptr) {

    }
    shared_ptr(const shared_ptr<T>& rhs) {
        ptr = new (T);
    }

private:
    T* ptr;
};

}

int main(int argc, char** argv) {
    int a = 42;
    return 0;
}

