#ifndef  ComplexLib
template <typename _T>
class Complex
{

private:
    _T m_r; ///< member real part of number
    _T m_i; ///< member real image of number

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
};
#endif

int main(int argc, char *argv[])
{
    return 0;
}
