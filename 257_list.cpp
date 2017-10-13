//257_list

#include <iostream>
#include <string.h>
#include <time.h>

class QueuePriority
{
    int* wait;
    int* pri;
    int max_queue_length;
    int queue_length;
public:
    QueuePriority(int m);
    ~QueuePriority();
    void add(int c, int p);
    int extract();
    void clear();
    bool isEmpty();
    bool isFull();
    int get_count();
    void show();
};


QueuePriority::QueuePriority(int m)
{
    max_queue_length = m;
    wait = new int[max_queue_length];
    pri = new int[max_queue_length];
    queue_length = 0;
}

QueuePriority::~QueuePriority()
{
    delete[]wait;
    delete[]pri;
}

void QueuePriority::add(int c, int p)
{
    if(!isFull())
    {
        wait[queue_length] = c;
        pri[queue_length] = p;
        queue_length++;
    }
}

int QueuePriority::extract()
{
    if(!isEmpty())
    {
        int max_pri = pri[0];
        int pos_max_pri = 0;
        for (int i = 1; i < queue_length; ++i) {
            if(max_pri < pri[i])
            {
                max_pri = pri[i];
                pos_max_pri = i;
            }
        }
        int temp1 = wait[pos_max_pri];
        int temp2 = pri[pos_max_pri];

        for (int i = pos_max_pri; i < queue_length - 1; ++i) {
            wait[i] = wait[i + 1];
            pri[i] = pri[i + 1];
        }
        queue_length--;
        return temp1;
    }
    else
    {
        return -1;
    }
}

void QueuePriority::clear()
{
    queue_length = 0;
}

bool QueuePriority::isEmpty()
{
    return queue_length == 0;
}

bool QueuePriority::isFull()
{
    return queue_length == max_queue_length;
}

int QueuePriority::get_count()
{
    return queue_length;
}

void QueuePriority::show()
{
    std::cout << "\n-------------------------\n";
    for (int i = 0; i < queue_length; ++i) {
        std::cout << wait[i] << " - " << pri[i] << "\n\n";
    }
    std::cout << "\n-------------------------\n";
}

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QueuePriority qup(25);
    for (int i = 0; i < 5; ++i) {
        qup.add(rand()%100,rand()%12);
    }
    qup.show();
    qup.extract();
    qup.show();
    return 0;
}
