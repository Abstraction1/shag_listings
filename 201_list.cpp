#include <iostream>

class Test
{
    int one;
public:
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

int main()
{
    Test obj;
    obj.initial(2, 5);
    obj.show();
    return 0;
}
