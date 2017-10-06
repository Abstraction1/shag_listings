//225 list
#include <iostream>

class Number
{
private:
    int num;
public:
    Number(int iNum)
    {
        num = iNum;
    }

    void show()
    {
        std::cout << num << "\n";
    }
};

class Digit
{
private:
    int dig;
public:
    Digit(int iDig)
    {
        dig = iDig;
    }

    void show()
    {
        std::cout << dig << "\n";
    }

    operator int()
    {
        return dig;
    }

    operator Number()
    {
        return Number(dig);
    }

};

int main(int argc, char *argv[])
{
    Digit A(5);
    std::cout << "In Digit A:\n";
    A.show();
    int a = A;
    std::cout << "In int a:\n";
    std::cout << a << "\n";

    Digit B(3);
    std::cout << "In digit B:\n";
    B.show();

    Number b(0);
    std::cout <<"In number b (before):\n";
    b.show();

    b = B;
    std::cout <<"In Number b (after):\n";
    b.show();
    return 0;
}

