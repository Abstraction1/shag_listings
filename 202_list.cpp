#include <iostream>

class Test
{
    int one;
public:
    Test()
    {
        one = 0;
        two - 0;
    }
    void initial(int o, int t)
    {
        one = o;
        two = t;
    }

    void show()
    {
        std::cout << "\n\n" << one << "\t" << two << "\n\n";
    }


    int two;
};

int main(int argc, char *argv[])
{
    Test obj;
    obj.show();
    obj.initial(2, 5);
    obj.show();

    return 0;
}
