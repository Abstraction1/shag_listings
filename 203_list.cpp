#include <iostream>

class Point
{
    int x, y;
public:
    Point(int x0, int y0)
    {
        x = x0;
        y = y0;
    }

    void show_point()
    {
        std::cout << "\nx = " << x;
        std::cout << "\ny = " << y;
    }
};

int main(int argc, char *argv[])
{
    Point A(1, 3);
    A.show_point();
    return 0;
}
