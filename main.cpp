#pragma once
#ifndef  ComplexLib

#include <iostream>

class Complex
{
private:
    typedef double _T;

private:
    _T m_r; ///< member real part of number
    _T m_i; ///< member image part of number

public:
    Complex()
        : m_r(_T(0))
        , m_i(_T(0))
    {}

    Complex(const _T a, const _T b)
        : m_r(a)
        , m_i(b)
    {}

    Complex(const Complex& complNum)
        : m_r(complNum.m_r)
        , m_i(complNum.m_i)
    {}

    ~Complex() {}

    constexpr _T real() const
    {
        return real();
    }

    constexpr _T image() const
    {
        return image();
    }

    _T& real()
    {
        return m_r;
    }

    _T& image()
    {
        return m_i;
    }

    ///< для алгебраической формы
    const Complex& conj(const Complex& num)
    {
        return Complex(num.real(), -num.image());
    }

    Complex& operator=(const Complex& num)
    {
        this -> m_r = num.real();
        this -> m_i = num.image();
        return *this;
    }

    Complex& operator+=(const Complex& num)
    {
        this -> m_r += num.real();
        this -> m_i += num.image();
        return *this;
    }

    Complex& operator-=(const Complex& num)
    {
        this -> m_r -= num.real();
        this -> m_i -= num.image();
        return *this;
    }

    Complex& operator*=(const Complex& num)
    {
        this -> m_r -= num.real();
        this -> m_i -= num.image();
        return *this;
    }

    Complex& operator/=(const Complex& num)
    {
        _T denominator = num.real() * num.real() + num.image() * num.image();

        _T numerator1 = this->real() * num.real() + this->image() * num.image();
        _T numerator2 = num.real() * this->image() - num.image() * this->real();

        ///< need TODO exception
//        if(!denominator)
//            return Complex();

        this -> m_r = numerator1;
        this -> m_i = numerator2;
        return *this;
    }

    friend const Complex& operator+ (Complex num1, Complex num2)
    {
        return Complex(num1 + num2);
    }

    friend const Complex& operator- (Complex num1, Complex num2)
    {
        return Complex(num1 - num2);
    }

    friend const Complex& operator* (Complex num1, Complex num2)
    {
        return Complex(num1 * num2);
    }

    friend const Complex& operator/ (Complex num1, Complex num2)
    {
        return Complex (num1 / num2);
    }

    friend const Complex& operator<< (std::ostream & out, Complex num)
    {
        return (out << num);
    }

    friend const Complex& operator>> (std::istream & in, Complex num)
    {
        return (in >> num);
    }

    friend bool operator==(const Complex& c1, const Complex& c2)
    {
        return ((c1.real() == c2.real()) && (c1.image() == c2.image()));
    }

    friend bool operator!=(const Complex& c1, const Complex& c2)
    {
        return (c1 != c2);
    }

    friend bool operator<(const Complex& c1, const Complex& c2)
    {
        return (c1.real() < c2.real() && c1.image() < c2.image());
    }

    ///< на множестве комплексных чисел нельзя однозначно ввести сравнение чисел,
    ///< поэтому операторы <,<=,>,>= определить не представляется возможным.
    ///<
    ///< 1) Можно ввести вполне упорядоченное множество, но всюду на множестве строго математически доказать это нельзя
    ///< 2) Можно ввести частичный порядок, однако и им всё перебрать нельзя
    ///< ВАЖНО!!!
    ///< 3) Можно ввести ТАКИМ ОБРАЗОМ: (https:\\ http://math.hashcode.ru/questions/5030/%D0%BA%D0%BE%D0%BC%D0%BF%D0%BB%D0%B5%D0%BA%D1%81%D0%BD%D1%8B%D0%B5-%D1%87%D0%B8%D1%81%D0%BB%D0%B0-%D1%81%D1%80%D0%B0%D0%B2%D0%BD%D0%B5%D0%BD%D0%B8%D0%B5-%D0%BA%D0%BE%D0%BC%D0%BF%D0%BB%D0%B5%D0%BA%D1%81%D0%BD%D1%8B%D1%85-%D1%87%D0%B8%D1%81%D0%B5%D0%BB)
    ///<    В то же время мы можем ввести на комплексной плоскости
    ///<    порядок, например, так: z ≺ w⇔(x < u∨(x = u,y < v)). Здесь, конечно,
    ///<    z = x + iy,w = u + iv. Это действительно порядок (т.е. транзитивное
    ///<    асимметричное отношение), и он линеен. Однако при этом комплексная
    ///<    плоскость вовсе не вытягивается в линию. Вернее, такую линию можно
    ///<    себе представить, но она должа состоять из бесконечного числа прямых
    ///<    x = const, "приставленных" друг к другу.
    ///<    Кстати, этот порядок согласован с порядком на вещественной прямой.
    ///<    Впрочем, как и другой, в котором сравнение идет сначала по мнимой
    ///<    части: z ≺ w ⇔ (y < v ∨ (y = v,x < u)).


};
#endif

int main(int argc, char *argv[])
{
    Complex z1(1,1);
    std::cout << z1.real() << " " << z1.image() << std::endl;
    return 0;
}
