//250 list

#include <iostream>

class Temp
{
    int TEMP;
public:
    Temp()
    {
        TEMP = 25;
    }
    void temp_function()
    {
        std::cout << "TEMP = " << TEMP << "\n\n";
    }
    void temp_set(int T)
    {
        TEMP = T;
    }
};

class MyPtr
{
    Temp* ptr;
public:
    MyPtr(Temp* p = NULL)
    {
        ptr = p;
    }
    operator Temp*()
    {
        return ptr;
    }
    Temp* operator->()
    {
        return ptr;
    }
    MyPtr operator++()
    {
        ptr++;
        return *this;
    }
};

int main(int argc, char *argv[])
{
    Temp* main_ptr = new Temp;
    main_ptr->temp_function();
    MyPtr pTemp(main_ptr);
    pTemp->temp_function();
    Temp* arr_ = new Temp[3];
    for (int i = 0; i < 3; ++i) {
        arr_[i].temp_set(i);
    }
    MyPtr arr_temp = arr_;
    ++arr_temp;
    arr_temp->temp_function();
    delete main_ptr;
    delete[] arr_;
    return 0;
}
