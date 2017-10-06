//219 list
#include <iostream>

class ClassName
{
public:
    ClassName()
    {
        std::cout << "ClassName!!!\n";
    }

    ClassName(ClassName& obj)
    {
        std::cout << "Copy ClassName!!!\n";
    }

    ~ClassName()
    {
        std::cout << "~ClassName!!!\n";
    }
};

void f(ClassName o)
{
    std::cout << "Function f!!!\n";
}

ClassName r()
{
    ClassName o;
    std::cout << "Function r!!!\n";
    return o;
}

int main(int argc, char *argv[])
{
    ClassName c1;
    ClassName c2 = c1;
    ClassName a;
    f(a);
    r();
    return 0;
}
