//243 list
#include <iostream>
#include <malloc.h>

class SomeClass
{
private:
    int some;
public:
    void* operator new(size_t size, char* str = "New");
    void operator delete(void* ptr);
    void* operator new[](size_t fullsize, char* str = "New");
    void operator delete[](void* ptr);
};

    int main(int argc, char *argv[])
    {
        SomeClass* p = new SomeClass;
        SomeClass* pt = new SomeClass[3];
        delete p;
        delete[] pt;
        return 0;
    }


    void *SomeClass::operator new(size_t size, char *str)
    {
        std::cout << "\n" << str << "\n";
        void* ptr = malloc(size);
        if(!ptr)
        {
            std::cout << "\nError memory new!!!\n";
        }
        else
        {
            std::cout << "\nMemory new - OK!!!\n";
        }
        return ptr;
    }

    void SomeClass::operator delete(void *ptr)
    {
        free(ptr);
        std::cout <<"\nDelete Memory\n";
    }

    void *SomeClass::operator new[](size_t fullsize, char *str)
    {
        std::cout << "\n" << str << "\n";
        void* ptr = malloc(fullsize);
        if(!ptr)
        {
            std::cout << "\nError memory new!!!\n";
        }
        else
        {
            std::cout << "\nMemory new - OK!!!\n";
        }
        return ptr;
    }

    void SomeClass::operator delete[](void *ptr)
    {
        free(ptr);
        std::cout << "\nDelete[] memory!!\n";
    }
