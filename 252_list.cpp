//252 list

#include <iostream>
void summa(int k, ...)
{
    int* pk = &k;
    long sm = 0;
    for(;k;k--)
    {
        sm += *(++pk);
    }
}
int main(int argc, char *argv[])
{
    summa(2,4,6);
    summa(6,1,2,3,4,5,6);

    return 0;
}
