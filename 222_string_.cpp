//222 string_

#include <iostream>
#include <string.h>

class string_
{
private:
    char* S;
    int len;
public:
    string_();

    string_(char* s);

    string_(const string_& s);

    ~string_()
    {
        delete[] S;
    }

    void Sort(string_ s[], int n);

    const char* get_str() const
    {
        return S;
    }

    void set_str()
    {
        if(S!=NULL)
        {
            delete[]S;
        }
        char a[256];
        std::cin.getline(a, 256);
        len = strlen(a) + 1;
        S = new char[len];
        strcpy(S, a);
    }

    void set_str_2(char* str)
    {
        if(S!=NULL)
        {
            delete[]S;
        }
        len = strlen(str) + 1;
        S = new char[len];
        strcpy(S, str);
    }
};

string_::string_()
{
    S = NULL;
    len = 0;
}

string_::string_(char *s)
{
    len = strlen(s);
    S = new char[len + 1];
    strcpy(S,s);
}

string_::string_(const string_ &s)
{
    len = s.len;
    S = new char[len + 1];
    strcpy(S, s.S);
}

void string_::Sort(string_ s[], int n)
{
    string_ tmp;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = n - 1; j > i; --j)
        {
            if (strcmp(s[j].S, s[j - 1].S) < 0)
            {
                tmp.set_str_2(s[j].S);
                s[j].set_str_2(s[j - 1].S);
                s[j - 1].set_str_2(tmp.S);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int n, i;
    std::cout << "Input the number of string s:\t";
    std::cin >>n;
    if(n < 0)
    {
        std::cout << "Error number:\t" << n << std::endl;
        return 0;
    }
    char c[2];
    std::cin.getline(c, 2);
    string_* s = new string_[n];

    for (int i = 0; i < n; ++i)
    {
        s[i].set_str();
    }
    s->Sort(s, n);

    for (i = 0; i < n; ++i)
    {
        std::cout << "\n" << s[i].get_str() << "\n";
    }
    delete [] s;
    return 0;
}


