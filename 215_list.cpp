//215 list
#include <iostream>

class Point
{
    double x, y;
public:
    Point(double initX, double initY)
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
    Point AR[2] = {Point(2, 3), Point(4, 5)};
    for (int i = 0; i < 2; ++i) {
        AR[i].show();
    }
    return 0;
}
