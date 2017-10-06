//214 list
#include <iostream>

class Point
{
    double x, y;
public:
    Point(double initX = 1, double initY = 1)
    {
        x = initX;
        y = initY;
        std::cout << "\nWhis args\n";
    }
    void show()
    {
        std::cout << x << " " << y << "\n";
    }
};

int main(int argc, char *argv[])
{
    Point A(2,3);
    A.show();
    Point* pA;
    pA = new Point(4, 5);
    if(!pA)
    {
        exit(0);
    }
    pA->show();
    Point* pB;
    pB = new Point[10];
    if(!pB)
    {
        exit(0);
    }
    for (int i = 0; i < 10; ++i)
    {
        pB[i].show();
    }
    delete pA;
    delete[] pB;
    return 0;
}

