#include <iostream>
#include <thread>
#include <memory>
#include <vector>

class Base {
public:
    virtual void show() {
        std::cout << "Base show" << std::endl;
    }
};

class Derived : public Base {
private:
    virtual void show() override {
        std::cout << "Derived show" << std::endl;
    }
};

void testSwap() {
    std::vector<int> v1{ 1, 3, 5, 7 };
    std::vector<int> v2{ 2, 4, 6, 8 };

    std::cout << std::hex << &v1 << std::endl;
    std::cout << std::hex << &v2 << std::endl;

    std::swap(v1, v2);

    std::cout << std::hex << &v1 << std::endl;
    std::cout << std::hex << &v2 << std::endl;

}

int main(int argc, char** argv) {
    testSwap();
    return 0;
}