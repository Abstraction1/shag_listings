//246 list
#include <iostream>

class Flag
{
    bool flag;
    friend Flag& operator !(Flag& f);
public:
    Flag(bool iF)
    {
        flag = iF;
    }
    void display()
    {
        if(flag)
        {
            std::cout << "\nTRUE\n";
        }
        else
        {
            std::cout << "\nFALSE\n";
        }
    }
};

Flag& operator !(Flag& f)
{
    f.flag = !f.flag;
    return f;
}

int main(int argc, char *argv[])
{
    Flag A(true);
    A.display();
    A = !A;
    A.display();
    return 0;
}
