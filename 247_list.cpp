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
        Y = iY;
    }
    void show()
    {
        std::cout << "\n+++++++++++++++++++++++++\n";
        std::cout << "X = " << X <<"\tY = " << Y;
        std::cout << "\n+++++++++++++++++++++++++\n";
    }
    Point& operator+(int d)
    {
        Point P(0,0);
        P.X = X + d;
        P.Y = Y + d;
        return P;
    }
    int get_x() const
    {
        return X;
    }
    int get_y() const
    {
        return Y;
    }
    void set_x(int iX)
    {
        X = iX;
    }
    void set_y(int iY)
    {
        Y = iY;
    }
};

Point&operator+(int d, Point& Z)
{
    Point P(0,0);
    P.set_x(d + Z.get_x());
    P.set_y(d + Z.get_y());
    return P;
}

int main(int argc, char *argv[])
{
    Point A(3, 2);
    A.show();

    Point B = A + 5;
    B.show();

    Point C = 2 + A;
    C.show();

    return 0;
}

