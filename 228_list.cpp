//227 list
#include <iostream>

class Pair
{
    int N;
    double x;
public:
    Pair(int n, double xn)
    {
        N = n;
        x = xn;
    }
    void display()
    {
        std::cout << "\nPair: N = " << N << " x = " << x << "\n";
    }
    Pair& operator --()
    {
        N /= 10;
        x /= 10;
        return *this;
    }
    Pair& operator --(int k)
    {
        Pair temp(0,0.0);
        temp.N =  N + k;
        temp.x = x + k;

        N /= 10;
        x /= 10;
        return temp;
    }
};

int main(int argc, char *argv[])
{
    Pair Z(10,20.2);
    std::cout << "\nObject Z (before):\n";
    Z.display();
    Pair Pref = --Z;
    std::cout << "\nPrefix:\n";
    std::cout << "\nObject Pref:\n";
    Pref.display();
    std::cout << "\nObject Z (after):\n";
    Z.display();
    Pair Postf = Z--;
    std::cout << "\nPostfix:\n";
    std::cout << "\nObject Postf:\n";
    Postf.display();
    std::cout << "\nObject Z (after):\n";
    Z.display();
    return 0;
}
