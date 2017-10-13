//253 list

#include <iostream>

long summa (int k,...)
{
    int* pk = &k;
    long sm = 0;
    while(*pk)
    {
        sm += *(pk++);
    }
    return sm;
}

int main(int argc, char *argv[])
{
    std::cout << summa(4,6,0);
    summa(1,2,3,4,5,6,0);
    summa(1,2,0,4,5,6,0);

    return 0;
}

