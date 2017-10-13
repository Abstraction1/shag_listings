//259_list

#include <iostream>

struct elem
{
    int data;
    elem* next;
    elem* prev;
};

class list
{
    elem* head;
    elem* tail;
    int count;
public:
    list();
    list(const list&);
    ~list();

    int get_count();
    elem* get_elem(int);
    void del_all();
    void del(int pos = 0);
    void insert(int pos = 0);
    void add_tail(int n);
    void add_head(int n);
    void print();
    void print(int pos);

    list& operator =(const list&);
    list operator +(const list&);
    bool operator ==(const list&);
    bool operator !=(const list&);
    bool operator <=(const list&);
    bool operator >=(const list&);
    bool operator <(const list&);
    bool operator >(const list&);
    list operator -();
};

list::list()
{
    head = tail = NULL;
    count = 0;
}

list::list(const list &l)
{
    head = tail = NULL;
    count = 0;

    elem* temp = l.head;
    while (temp != 0) {
        add_tail(temp->data);
        temp = temp->next;
    }
}

list::~list()
{
    del_all();
}

int list::get_count()
{
    return count;
}

elem *list::get_elem(int pos)
{
    elem* temp = head;

    if(pos < 1 || pos > count) {
        std::cout << "Incorrect position !!!\n";
        return 0;
    }

    int i = 1;

    while (i < pos && temp != 0) {
        temp = temp->next;
        i++;
    }

    if (temp == 0) {
        return 0;
    } else {
        return temp;
    }
}

void list::del_all()
{
    while (count != 0) {
        del(1);
    }
}

void list::del(int pos)
{
    if (pos == 0) {
        std::cout << "Input position: ";
        std::cin >> pos;
    }
    if (pos < 1 || pos > count) {
        std::cout << "Incorrect position !!!\n";
        return;
    }

    int i = 1;
    elem* del = head;

    while (i < pos) {
        del = del->next;
        i++;
    }

    elem* prev_del = del->prev;
    elem* after_del = del->next;

    if(prev_del != 0 && count != 1) {
        prev_del->next = after_del;
    }
    if (after_del != 0 &&  count != 1) {
        after_del->prev = prev_del;
    }
    if (pos == 1) {
        head = after_del;
    }
    if (pos == count) {
        tail = prev_del;
    }

    delete del;

    count--;
}

void list::insert(int pos)
{
    if (pos == 0) {
        std::cout << "Input position: ";
        std::cin >> pos;
    }
    if (pos <  1 || pos > count + 1) {
        std::cout << "Incorrect position !!!\n";
        return;
    }
    if (pos == count + 1) {
        int data;
        std::cout << "Input new number: ";
        std::cin >> data;
        add_tail(data);
        return;
    } else if (pos == 1) {
        int data;
        std::cout << "Input new number: ";
        std::cin >> data;
        add_head(data);
        return;
    }

    int i = 1;
    elem* ins = head;

    while (i < pos) {
        ins = ins->next;
        i++;
    }

    elem* prev_ins = ins->prev;
    elem* temp = new elem;

    std::cout << "Input new number: ";
    std::cin >> temp->data;

    if (prev_ins != 0 && count != 1) {
        prev_ins->next = temp;
    }

    temp->next = ins;
    temp->prev = prev_ins;
    ins->prev = temp;

    count++;
}

void list::add_tail(int n)
{
    elem* temp = new elem;
    temp->next = 0;
    temp->data = n;
    temp->prev = tail;

    if (tail != 0) {
        tail->next = temp;
    }
    if(count == 0) {
        head = tail = temp;
    } else {
        tail = temp;
    }

    count++;
}

void list::add_head(int n)
{
    elem* temp = new elem;
    temp->prev = 0;
    temp->data = n;
    temp->next = head;

    if (head != 0) {
        head->prev = temp;
    }
    if (count == 0) {
        head->prev = temp;
    } else {
        head = temp;
    }
    count++;
}

void list::print()
{
    if (count != 0) {
        elem* temp = head;
        std::cout << "( ";
        while (temp->next != 0) {
            std::cout << temp->data << ", ";
            temp = temp->next;
        }
        std::cout << temp->data << " )]n";
    }
}

void list::print(int pos)
{
    if (pos < 1 || pos > count) {
        std::cout << "Incorrect position !!!\n";
        return;
    }

    elem* temp;

    if (pos <= count / 2) {
        temp = head;
        int i = 1;

        while (i < pos) {
            temp = temp->next;
            i++;
        }
    } else {
        temp = tail;
        int i = 1;

        while (i <= count - pos) {
            temp = temp->prev;
            i++;
        }
    }
    std::cout << pos << " element: ";
    std::cout << temp->data << std::endl;
}

list &list::operator =(const list &l)
{
    if (this == &l) {
        return *this;
    }

    this->~list();
    elem* temp = l.head;

    while (temp != 0) {
        add_tail(temp->data);
        temp = temp->next;
    }

    return *this;
}

list list::operator +(const list &l)
{
    list result(*this);
    elem* temp = l.head;

    while (temp != 0) {
        result.add_tail(temp->data);
        temp = temp->next;
    }

    return result;
}

bool list::operator ==(const list &l)
{
    if(count != l.count)
    {
        return false;
    }

    elem* t1;
    elem* t2;

    t1 = head;
    t2 = l.head;

    while (t1 != 0) {
        if (t1->data != t2->data) {
            return false;
        }
        t1 = t1->next;
        t2 = t2->next;
    }
    return true;
}

bool list::operator !=(const list &l)
{
    return !(*this == l);
}

bool list::operator <=(const list &l)
{
    if(count < l.count)
    {
        return true;
    }
    if (*this == l) {
        return true;
    }
    return false;
}

bool list::operator >=(const list &l)
{
    if(count > l.count)
    {
        return true;
    }
    if(*this == l)
    {
        return true;
    }
    return false;
}

bool list::operator <(const list &l)
{
    if (count <  l.count) {
        return true;
    }
    return false;
}

bool list::operator >(const list &l)
{
    if(count < l.count)
    {
        return true;
    }
    return false;
}

list list::operator -()
{
    list result;
    elem* temp = head;

    while (temp != 0) {
        result.add_head(temp->data);
        temp = temp->next;
    }

    return result;
}

int main(int argc, char *argv[])
{
    list l;
    const int n = 10;
    int a[n] = {0,1,2,3,4,5,6,7,8,9};

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            l.add_head(a[i]);
        } else {
            l.add_tail(a[i]);
        }
    }

    std::cout << "List l:\n";
    l.print();
    std::cout << std::endl;;

    l.insert();
    std::cout << "List l:\n";
    l.print();

    l.print(2);
    l.print(8);

    list t;

    t = l;
    std::cout << "List t:\n";
    t.print();
    std::cout << "List Sum:\n";
    list sum = -l + t;
    sum.print();
    return 0;
}
