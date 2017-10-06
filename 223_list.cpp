//223 list
#include <iostream>

class Digit
{
private:
    int dig;
public:
    Digit()
    {
        dig = 0;
    }
    Digit(int iDig)
    {
        dig = iDig;
    }
    void show()
    {
        std::cout << dig << "\n";
    }
    Digit operator +(const Digit& N)
    {
        Digit tmp;
        tmp.dig = dig + N.dig;
        return tmp;
    }
    Digit operator -(const Digit& N)
    {
        Digit tmp;
        tmp.dig = dig - N.dig;
        return tmp;
    }
    Digit operator *(const Digit& N)
    {
        Digit tmp;
        tmp.dig = dig*N.dig;
        return tmp;
    }
    Digit operator %(const Digit& N)
    {
        Digit tmp;
        tmp.dig = dig%N.dig;
        return tmp;
    }

};

int main(int argc, char *argv[])
{
    Digit A(8), B(3);
    Digit C;

    std::cout << "\tDigit A:\n";
    A.show();

    std::cout << "\tDigit B:\n";
    B.show();

    std::cout << "\toperator+:\n";
    C = A + B;
    C.show();

    std::cout << "\toperator-:\n";
    C = A - B;
    C.show();

    std::cout << "\toperator*:\n";
    C = A * B;
    C.show();

    std::cout << "\toperator%:\n";
    C = A % B;
    C.show();

    return 0;
}


