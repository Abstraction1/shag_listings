//255_list

#include <iostream>
#include <string.h>
#include <time.h>

class Queue
{
    int* wait;
    int max_queue_length;
    int queue_length;
public:
    Queue(int m);
    ~Queue();
    void add(int c);
    int extract();
    void clear();
    bool isEmpty();
    bool isFull();
    int get_count();
    void show();
};
Queue::Queue(int m)
{
    max_queue_length = m;
    wait = new int[max_queue_length];
    queue_length = 0;
}

Queue::~Queue()
{
    delete[] wait;
}

void Queue::add(int c)
{
    if(!isFull())
    {
        wait[queue_length++] = c;
    }
}

int Queue::extract()
{
    if(!isEmpty())
    {
        int temp = wait[0];
        for (int i = 0; i < queue_length; ++i) {
            wait[i - 1] = wait[i];
        }
        queue_length--;
        return temp;
    }
    else
    {
        return -1;
    }
}

void Queue::clear()
{
    queue_length = 0;
}

bool Queue::isEmpty()
{
    return queue_length == 0;
}

bool Queue::isFull()
{
    return queue_length == max_queue_length;
}

int Queue::get_count()
{
    return queue_length;
}

void Queue::show()
{
    std::cout <<"\n------------------------------------------------------\n";
    for (int i = 0; i < queue_length; ++i) {
        std::cout << wait[i] << " ";
    }
    std::cout <<"\n------------------------------------------------------\n";
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    Queue qu(25);
    for (int i = 0; i < 5; ++i) {
        qu.add(rand()%50);
    }
    qu.show();
    qu.extract();
    qu.show();
    return 0;
}
