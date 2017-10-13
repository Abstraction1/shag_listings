//254_list
#include <iostream>
#include <string.h>
#include <time.h>

class Stack
{
    enum
    {
        EMPTY = -1,
        FULL = 20
    };
    int st[FULL + 1];
    int top;
public:
    Stack();
    void push(int c);
    char pop();
    void clear();
    bool isEmpty();
    bool isFull();
    int get_count();
};

Stack::Stack()
{
    top = EMPTY;
}

void Stack::push(int c)
{
    if(!isFull())
    {
        st[++top] = c;
    }
}

char Stack::pop()
{
    if(!isEmpty())
    {
        return st[top--];
    }
    else
    {
        return 0;
    }
}

void Stack::clear()
{
    top = EMPTY;
}

bool Stack::isEmpty()
{
    return top == EMPTY;
}

bool Stack::isFull()
{
    return top + 1;
}


int main()
{
    srand(time(NULL));
    Stack st;
    int c = 0;
    while (!st.isFull()) {
        c = rand()% 4 + 2;
        st.push(c);
    }
    while (c = st.pop()) {
        std::cout << c << "_";
    }
    std::cout << "\n\n";
    return 0;
}
