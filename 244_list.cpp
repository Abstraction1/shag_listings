//244 list

#include <iostream>

class rect
{
    int width;
    int height;
    char symb;
    friend void friend_put(rect* r, char s);

public:
    rect(int w, int h, char s)
    {
        width = w;
        height = h;
        symb = s;
    }

    void display()
    {
        std::cout <<"\n\n";
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                std::cout << symb;
            }
            std::cout << "\n\n";
        }
        std::cout << "\n\n";
    }
};

void friend_put(rect *r, char s)
{
    r->symb = s;
}
int main(int argc, char *argv[])
{
    rect A(5,3,'A');
    rect B(3,5,'B');
    A.display();
    B.display();
    friend_put(&A, 'a');
    friend_put(&B,'b');
    A.display();
    B.display();
    return 0;
}
