//218 list
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

int main(int argc, char *argv[])
{
    ClassName c1;
    ClassName c2 = c1;
    return 0;
}
