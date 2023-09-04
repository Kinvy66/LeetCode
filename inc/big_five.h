/**
* @file big_five.cpp
* @brief 三/五法则
* @author Kinvy
* @email Kinvy66@163.com
* @date 2023-08-01
*/
#ifndef BIG_FIVE_H
#define BIG_FIVE_H
#include <iostream>

namespace kinvy {

class complex;
complex& __doapl (complex* lhs, const complex& rhs);
complex& __doami (complex* lhs, const complex& rhs);
complex& __doaml (complex* lhs, const complex& rhs);

class complex {
friend complex& __doapl (complex *, const complex&);
friend complex& __doami (complex *, const complex&);
friend complex& __doaml (complex *, const complex&);
public:
    /**
     * @brief 默认构造
     */
    complex(int a = 0, int b = 0)
        : re(a)
        , im(b){
        std::cout << "complex(int a = 0, int b = 0)" << std::endl;
    }

    /**
     * @brief 拷贝构造
     * @param rhs
     */
    complex(const complex& rhs)
        : re(rhs.re)
        , im(rhs.im){
        std::cout << "complex(const complex& rhs)" << std::endl;
    }

    /**
     * @brief 拷贝赋值
     * @param rhs
     * @note 没有指针和引用的class,其默认的拷贝赋值函数就是进行如下的操作
     */
    complex& operator=(const complex& rhs) {
        std::cout << "operator=(&)" << std::endl;
        re = rhs.re;
        im = rhs.im;
        return *this;
    }

    /**
     * @brief
     * @param rhs
     * @return
     */
    complex& operator=(const complex&& rhs) noexcept  {
        std::cout << "operator=(&&)" << std::endl;
        if (this != &rhs) {
            re = rhs.re;
            im = rhs.im;
        }
        return *this;
    }

    ~complex()  = default;

    /**
     * @brief 加法运算
     * @param rhs
     */
    complex& operator+(const complex& rhs) {
        return __doapl(this, rhs);
    }

    /**
     * @brief 减法运算
     * @param rhs
     */
    complex& operator-(const complex& rhs) {
        return __doami(this, rhs);
    }

    /**
     * @brief 乘法运算
     * @param rhs
     */
    complex& operator*(const complex& rhs) {
        return __doaml(this, rhs);
    }

    int real() const { return re; }
    int imag() const { return im; }

private:
    int re;
    int im;
};

complex&
__doapl (complex* lhs, const complex& rhs) {
    lhs->re += rhs.re;
    lhs->im += rhs.im;
    return *lhs;
}

complex& __doami (complex* lhs, const complex& rhs) {
    lhs->re -= rhs.re;
    lhs->im -= rhs.im;
    return *lhs;
}
complex& __doaml (complex* lhs, const complex& rhs) {
    lhs->re = lhs->re * rhs.re - lhs->im * rhs.im;
    lhs->im = lhs->re * rhs.im + lhs->im * rhs.re;
    return *lhs;
}



std::ostream& operator<<(std::ostream& os, const complex& number) {
    os << number.real() << ((number.imag() > 0 ) ? "+" : "")
        << number.imag()
        << "i";
    return os;
}

}

#endif
