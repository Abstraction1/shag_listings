//221 list
#include <iostream>
#include <string.h>

class Personal
{
public:
    Personal(char* p, char* n, int a)
    {
        name = new char[strlen(n) + 1];
        if(!name)
        {
            std::cout << "Error!!!";
            exit(0);
        }
        picture_data = new char[strlen(n) + 1];
        if(!picture_data)
        {
            std::cout << "Error!!!";
            exit(0);
        }
        strcpy(picture_data, p);
        strcpy(name, n);
        age=a;
    }
    const char* Name() const
    {
        return name;
    }
    int Age ()const
    {
        return age;
    }
    const char* Picture() const
    {
        return picture_data;
    }
    void set_name(const char* n)
    {
        strcpy(name, n);
    }
    void set_age(int a)
    {
        age = a;
    }
    void set_picture(const char* p)
    {
        strcpy(picture_data, p);
    }
private:
    char* picture_data;
    char* name;
    int age;
};

int main(int argc, char *argv[])
{
    Personal A("C:\\Image\\","Ivan", 23);
    std::cout << "Name: " << A.Name() << "\n\n";
    std::cout << "Age: " << A.Age() << "\n\n";
    std::cout << "Path for picture: " << A.Picture() << "\n\n";
    A.set_picture("C:\\Test\\");
    A.set_name("Leonid");
    A.set_age(90);
    std::cout << "Name: " << A.Name() << "\n\n";
    std::cout << "Age: " << A.Age() << "\n\n";
    std::cout << "Path for picture: " << A.Picture() << "\n\n";

    return 0;
}

