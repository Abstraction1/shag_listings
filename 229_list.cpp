//229 list
#include <iostream>

class A
{
    int a[10];
    int size;
public:
    A()
    {
        size = 10;
        for (int i = 0; i < 10; ++i)
        {
            a[i] = i + 1;
        }
    }
    int& operator [](int j)
    {
        return a[j];
    }
    int get_size() const
    {
        return size;
    }
};

int main(int argc, char *argv[])
{
    int i, j;
    A object;
    for (int i = 0; i < object.get_size(); ++i)
    {
        std::cout << object[i] << " ";
    }
    A array[3];
    std::cout << "\nArray of objects:\n ";
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < object.get_size(); ++j)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n\n";

    }
    return 0;
}

