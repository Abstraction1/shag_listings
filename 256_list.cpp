//256_list

#include <iostream>
#include <string.h>
#include <time.h>

class queue_ring
{
    int* wait;
    int max_queue_length;
    int queue_length;
public:
    queue_ring(int m);
    ~queue_ring();
    void add(int c);
    bool extract();
    void clear();
    bool isEmpty();
    bool isFull();
    int get_count();
    void show();
};

queue_ring::queue_ring(int m)
{
    max_queue_length = m;
    wait = new int[max_queue_length];
    queue_length = 0;
}

queue_ring::~queue_ring()
{
    delete[]wait;
}

void queue_ring::add(int c)
{
    if(!isFull())
    {
        wait[queue_length++] = c;
    }
}

bool queue_ring::extract()
{
    if(!isEmpty())
    {
        int temp = wait[0];
        for (int i = 0; i < queue_length; ++i) {
            wait[i - 1] = wait[i];
        }
        wait[queue_length - 1] = temp;
        return 1;
    }
    else
    {
        return 0;
    }
}

void queue_ring::clear()
{
    queue_length = 0;
}

bool queue_ring::isEmpty()
{
    return queue_length == 0;
}

bool queue_ring::isFull()
{
    return queue_length == max_queue_length;
}

int queue_ring::get_count()
{
    return queue_length;
}

void queue_ring::show()
{
    std::cout << "\n------------------------------------\n";
    for (int i = 0; i < queue_length; ++i) {
        std::cout << wait[i] << " ";
    }
    std::cout << "\n------------------------------------\n";
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    queue_ring qur(25);
    for (int i = 0; i < 5; ++i) {
        qur.add(rand()%50);
    }
    qur.show();
    qur.extract();
    qur.show();
    return 0;
}
