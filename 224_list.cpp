//224 list
#include <iostream>

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
};

int main(int argc, char *argv[])
{
    Digit A(5);
    A.show();
    Digit B(3.7);
    B.show();
    return 0;
}



