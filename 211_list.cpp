//211 list
#include <iostream>

class _3D
{
    double x, y, z;
public:
    _3D();
    _3D(double initX, double initY, double initZ);
};

_3D::_3D()
{
    x = y = z;
    std::cout << "\nNo arguments!!!\n";
}

_3D::_3D(double initX, double initY, double initZ)
{
    x = initX;
    y = initY;
    z = initZ;
    std::cout << "\nWhis Arguments!!!\n";
}

int main(int argc, char *argv[])
{
    _3D A;
    _3D B(3, 4, 0);
    return 0;
}

