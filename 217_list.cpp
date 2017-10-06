//217 list
#include <iostream>

class ClassName
{
public:
    ClassName()
    {
        std::cout << "ClassName!!!\n";
    }
    ~ClassName()
    {
        std::cout << "~ClassName!!!\n";
    }

};

void f (ClassName o)
{
    std::cout << "Function f!!!\n";
}

int main(int argc, char *argv[])
{
    ClassName c1;
    f(c1);
    return 0;
}
