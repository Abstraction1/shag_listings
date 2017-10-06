//242 list
#include <iostream>
class MyPoint
{
    int X;
    int Y;
public:
    MyPoint()
    {
        X = 0;
        Y = 0;
    }
    void operator()(int x, int y)
    {
        X = x;
        Y = y;
    }
    void show()
    {
        std::cout << X << " " << Y << "\n\n";
    }
};

int main(int argc, char *argv[])
{
    MyPoint p;
    p.show();
    p(2,3);
    p.show();
    return 0;
}

