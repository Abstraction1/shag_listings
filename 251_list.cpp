//251 list
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
        std::cout <<"TEMP = " << TEMP << "\n\n";
    }
    void temp_set(int T)
    {
        TEMP = T;
    }
};

class SmartPointer
{
    Temp* ptr;
    int count_copy;
public:
    SmartPointer(Temp* p = NULL)
    {
        count_copy = 0;
        ptr = p;
    }
    SmartPointer(const SmartPointer& obj)
    {
        ptr = obj.ptr;
        count_copy++;
    }
    SmartPointer operator=(const SmartPointer& obj)
    {
        ptr = obj.ptr;
        ptr = obj.ptr;
        count_copy++;
        return *this;
    }
    ~SmartPointer()
    {
        if(ptr!=NULL && count_copy == 0)
        {
            std::cout <<"\n~Delete Object\n";
            delete[] ptr;
        }
        else
        {
            count_copy--;
            std::cout << "/n~Delete Copy\n";
        }
    }
    Temp* operator ->()
    {
        return ptr;
    }
};

int main(int argc, char *argv[])
{
    Temp* main_ptr = new Temp;
    SmartPointer PTR(main_ptr);
    PTR->temp_set(100);
    PTR->temp_function();
    SmartPointer PTR2=PTR;
    return 0;
}
