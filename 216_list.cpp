//216 list
#include <iostream>
#include <cstring>

class Student
{
    char name[50];
    char surname[50];
    int age;
public:
    Student(char name[], char surname[], int age)
    {
        strcpy(this->name, name);
        strcpy(this->surname, surname);
        this->age = age;
    }
    void show()
    {
        std::cout <<"\nNAME - " << this->name;
        std::cout <<"\nSURNAME - " << this->surname;
        std::cout <<"\nAGE - " << this->age;
        std::cout <<"\n\n";
    }
};

int main(int argc, char *argv[])
{
    Student A("Ivan", "Sidoroff", 25);
    A.show();
    return 0;
}
