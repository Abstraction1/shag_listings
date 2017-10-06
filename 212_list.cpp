//212 list
#include <iostream>

class _3D
{
    double x, y, z;
public:
    _3D();
    _3D(double initX, double initY, double initZ);
    void show()
    {
        std::cout << x << " " << y << " " << z << "\n";
    }
};

int main(int argc, char *argv[])
{
    _3D A (3, 4, 0);
    _3D* pA = &A;
    pA->show();
    return 0;
}

_3D::_3D()
{
    x = y = z;
    std::cout << "\nNo args!\n";
}

_3D::_3D(double initX, double initY, double initZ)
{
    x = initX;
    y = initY;
    z = initZ;
    std::cout << "\nWhis args!!\n";
}
