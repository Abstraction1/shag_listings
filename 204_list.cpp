//204 list
#include <iostream>

class Create_and_destroy
{
public:
    Create_and_destroy(int value)
    {
        data = value;
        std::cout << "Object " << data << " constructor" << std::endl;
    }
    ~Create_and_destroy()
    {
        std::cout << "Object " << data << " destructor" << std::endl;
    }
private:
    int data;
};

int main(int argc, char *argv[])
{
    Create_and_destroy one(1);
    Create_and_destroy two(2);
    return 0;
}
