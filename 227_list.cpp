//226 list

#include <iostream>

class Digit
{
    int N;
public:
    Digit(int n)
    {
        N = n;
    }
    void display()
    {
        std::cout <<"\nDigit: N = " << N << "\n";
    }
    Digit& operator --()
    {
        N /= 10;
        return *this;
    }
};

int main(int argc, char *argv[])
{
    Digit Z(100);
    std::cout << "\nObject Z (before): \n";
    Z.display();
    Digit Pref=--Z;
    std::cout << "\nPrefix:\n";
    std::cout << "\nObject Pref: \n";
    Pref.display();
    std::cout << "\nObject Z (after): \n";
    Z.display();

    Digit Postf=Z--;
    std::cout << "\nPostfix: \n";
    std::cout << "\nObject Postf: \n";
    Postf.display();
    std::cout << "\nObject Z (after): \n";
    Z.display();
    return 0;

}

