#pragma once
#ifndef  ComplexLib

#include <iostream>
template <typename _T>
class Complex
{

private:
    _T m_r; ///< member real part of number
    _T m_i; ///< member image part of number

public:
    Complex()
        : m_r(_T())
        , m_i(_T())
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

    const _T real() const
    {
        return real();
    }

    const _T image() const
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
    Complex<_T> conj(const Complex<_T> num)
    {
        return Complex<_T>(num.real(), -num.image());
    }

    Complex<_T>& operator=(const Complex<_T>& num)
    {
        this -> m_r = num.real();
        this -> m_i = num.image();
        return *this;
    }

    Complex<_T>& operator+=(const Complex<_T>& num)
    {
        this -> m_r += num.real();
        this -> m_i += num.image();
        return *this;
    }

    Complex<_T>& operator-=(const Complex<_T>& num)
    {
        this -> m_r -= num.real();
        this -> m_i -= num.image();
        return *this;
    }

    Complex<_T>& operator*=(const Complex<_T>& num)
    {
        this -> m_r -= num.real();
        this -> m_i -= num.image();
        return *this;
    }

    Complex<_T>& operator/=(const Complex<_T>& num)
    {
        _T denominator = num.real() * num.real() + num.image() * num.image();

        _T numerator1 = this->real() * num.real() + this->image() * num.image();
        _T numerator2 = num.real() * this->image() - num.image() * this->real();

        ///< need TODO exception
        if(!denominator)
            return Complex<_T>();

        this -> m_r = numerator1;
        this -> m_i = numerator2;
        return *this;
    }

    friend Complex<_T>& operator+ (Complex<_T> num1, Complex<_T> num2)
    {
        return Complex<_T> (num1 + num2);
    }

    friend Complex<_T>& operator- (Complex<_T> num1, Complex<_T> num2)
    {
        return Complex<_T> (num1 - num2);
    }

    friend Complex<_T>& operator* (Complex<_T> num1, Complex<_T> num2)
    {
        return Complex<_T> (num1 * num2);
    }

    friend Complex<_T>& operator/ (Complex<_T> num1, Complex<_T> num2)
    {
        return Complex<_T> (num1 / num2);
    }

    friend Complex<_T>& operator<< (std::ostream & out, Complex<_T> num)
    {
        return (out << "Re(z) = "  << num.real() << "Im(z) = " << num.image());
    }

    friend Complex<_T>& operator>> (std::istream & in, Complex<_T> num)
    {
        return (in >> num);
    }

    friend bool operator==(const Complex<_T>& c1, const Complex<_T>& c2)
    {
        return ((c1.real() == c2.real()) && (c1.image() == c2.image()));
    }

    friend bool operator!=(const Complex<_T>& c1, const Complex<_T>& c2)
    {
        return (c1 != c2);
    }

    ///< на множестве комплексных чисел нельзя однозначно ввести сравнение чисел,
    ///< поэтому операторы >,>=,<,<= определить не представляется возможным.
    ///<
    ///< 1) Можно ввести вполне упорядоченное множество, но строго математически доказать это нельзя
    ///< 2) Можно ввести частичный порядок, однако и им всё перебрать нельзя
    ///< ВАЖНО!!!
    ///< 3) Можно ввести ТАКИМ ОБРАЗОМ: (https:\\ http://math.hashcode.ru/questions/5030/%D0%BA%D0%BE%D0%BC%D0%BF%D0%BB%D0%B5%D0%BA%D1%81%D0%BD%D1%8B%D0%B5-%D1%87%D0%B8%D1%81%D0%BB%D0%B0-%D1%81%D1%80%D0%B0%D0%B2%D0%BD%D0%B5%D0%BD%D0%B8%D0%B5-%D0%BA%D0%BE%D0%BC%D0%BF%D0%BB%D0%B5%D0%BA%D1%81%D0%BD%D1%8B%D1%85-%D1%87%D0%B8%D1%81%D0%B5%D0%BB)
    ///<    В то же время мы можем ввести на комплексной плоскости
    ///<    порядок, например, так: z≺w⇔(x<u ∨ (x=u , y<v)). Здесь, конечно, 
    ///<    z = x+iy,w = u+iv. Это действительно порядок (т.е. транзитивное
    ///<    асимметричное отношение), и он линеен. Однако при этом комплексная
    ///<    плоскость вовсе не вытягивается в линию. Вернее, такую линию можно
    ///<    себе представить, но она должа состоять из бесконечного числа прямых
    ///<    x = const, "приставленных" друг к другу.
    ///<    Кстати, этот порядок согласован с порядком на вещественной прямой.
    ///<    Впрочем, как и другой, в котором сравнение идет сначала по мнимой
    ///<    части: z≺w⇔(y<v∨(y=v,x<u)).
};
#endif

int main(int argc, char *argv[])
{
    Complex<int> z1(1,1);
    std::cout << z1.real() << " " << z1.image() << std::endl;
    return 0;
}
