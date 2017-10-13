//249 list

#include <iostream>
class Banana;
class Apple
{
public:
    void F_apple(Banana ob);
};
class Banana
{
    int x;
    int y;
public:
    Banana()
    {
        x = y = 777;
    }
    friend Apple;
};
void Apple::F_apple(Banana ob)
{
    std::cout << ob.x << "\n";
    std::cout << ob.y << "\n";
}

int main(int argc, char *argv[])
{
    Banana b;
    Apple a;
    a.F_apple(b);
    return 0;
}
