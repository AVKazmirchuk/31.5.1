#pragma once

#include <iostream>
#include <string>



class Toy
{
private:
    std::string name;
public:
    Toy() : name{ "SomeToy" }
    {
        std::cout << "The object " << name << " was created\n";
    }

    Toy(std::string _name) : name{ _name }
    {
        std::cout << "The object " << name << " was created\n";
    }

    ~Toy()
    {
        std::cout << "The object " << name << " was deleted\n";
    }
};

class shared_ptr_toy
{
private:
    Toy* ptr;
    int* count;

    void initial(const shared_ptr_toy& obj)
    {
        ptr = obj.ptr;
        count = obj.count;
        ++(*count);
    }
public:
    shared_ptr_toy(Toy* _ptr = nullptr) : ptr{ _ptr }
    {
        count = new int;
        if (ptr) *count = 1;
        else *count = 0;
    }

    ~shared_ptr_toy()
    {
        if (--(*count) <= 0)
        {
            delete count;
            delete ptr;
        }
    }

    shared_ptr_toy(const shared_ptr_toy& obj)
    {
        initial(obj);
    }

    shared_ptr_toy& operator=(const shared_ptr_toy& obj)
    {
        if (this == &obj) return *this;

        initial(obj);

        return *this;
    }
};

