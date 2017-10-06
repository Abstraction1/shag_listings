//245 list
#include <iostream>

class line_;
class point_
{
    float x, y;
public:
    point_(float xn = 0, float yn = 0)
    {
        x = xn;
        y = yn;
    }
    friend float uclon(point_, line_);
};
class line_
{
    float A, B, C;
public:
    line_(float a, float b, float c)
    {
        A = a;
        B = b;
        C = c;
    }
    friend float uclon(point_, line_);
};
float uclon(point_ p, line_ l)
{
    return l.A * p.x + l.B * p.y + l.C;
}
int main(int argc, char *argv[])
{
    point_ P(16.0, 12.3);
    line_ L(10.0, -24.3, 24.0);
    std::cout <<"\n Result" << uclon(P,L) << "\n\n";
    return 0;
}
