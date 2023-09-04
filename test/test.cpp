/**
* @file test.cpp
* @brief 
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-01
*/

#include <iostream>
#include "../inc/big_five.h"

int main(int argc, char** argv) {
    kinvy::complex n1 = 10;
    kinvy::complex n2 = n1;
    n2 = kinvy::complex(1);
    auto sum = n1 + n1 ;
    std::cout << sum << std::endl;
    return 0;
}