//257_list

#include <iostream>
#include <string.h>

struct  element
{
    char data;
    element* next;
};

class list
{
    element* head;
    element* tail;
    int count;
public:
    list();
    ~list();
    void add(char data);
    void del();
    void del_all();
    void print();
    int get_count();
};

list::list()
{
    head = tail = NULL;
    count = 0;
}

list::~list()
{
    del_all();
}

void list::add(char data)
{
    element* temp = new element;
    temp->data = data;
    temp->next = NULL;
    if(head!=NULL)
    {
        tail->next = temp;
        tail = temp;
    }
    else
    {
        head = tail = temp;
    }
}

void list::del()
{
    element* temp = head;
    head = head->next;
    delete temp;
}

void list::del_all()
{
    while (head != 0) {
        del();
    }
}

void list::print()
{
    element* temp = head;
    while(temp != 0)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n\n";
}

int list::get_count()
{
    return count;
}

int main(int argc, char *argv[])
{
    list lst;
    char s[] = "Hello, world !!! \n";
    std::cout << s << "\n\n";
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        lst.add(s[i]);
    }
    lst.print();
    lst.del();
    lst.del();
    lst.del();
    lst.print();
    return 0;
}

