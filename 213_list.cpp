//213 list
#include <iostream>

class Point
{
    double x, y;
public:
    Point()
    {
        x = y = 0;
        std::cout << "\nNo args!\n";
    }
    void show()
    {
        std::cout << x << " " << y << "\n";
    }
};

int main(int argc, char *argv[])
{
    Point A;
    A.show();
    Point* pA;
    pA = new Point;
    if(!pA)
    {
        exit(0);
    }
    Point* pB;
    pB = new Point[10];
    for (int i = 0; i < 10; ++i) {
        pB[i].show();
    }
    delete pA;
    delete pB;
    return 0;
}

