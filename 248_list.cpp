//246 list

#include <iostream>

class Point
{
    int X;
    int Y;
public:
    Point(int iX, int iY)
    {
        X = iX;
        Y - iY;
    }
    friend std::istream& operator >>(std::istream& is, Point& P);
    friend std::ostream& operator <<(std::ostream& os, const Point& P);
};

std::istream& operator >>(std::istream& is, Point& P)
{
    std::cout << "Set X\t";
    is >> P.X;
    std::cout << "Set Y\t";
    is >> P.Y;
    return is;
}

std::ostream& operator << (std::ostream& os, const Point& P)
{
    os << "X = " << P.X << '\t';
    os << "Y = " << P.Y << '\n';
}

int main(int argc, char *argv[])
{
    Point A(0,0);
    std::cin >> A;
    std::cout << A;
    Point B(0,0);
    std::cin >> A >> B;
    std::cout << A << B;
    return 0;
}

