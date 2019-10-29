#include <iostream>

using namespace std;

template <class T>
struct Base
{
    void interface()
    {
        // ...
        { cout << "interface" << endl; }
        static_cast<T*>(this)->implementation();
        // ...
    }

    static void static_func()
    {
        // ...
        { cout << "static_func" << endl; }
        T::static_sub_func();
        // ...
    }
};

struct Derived : Base<Derived>
{
    void implementation() { cout << "Derived implementation" << endl; }
    static void static_sub_func() { cout << "Derived static_sub_func" << endl; }
};

int main()
{
    Derived d;
    Base<Derived> b;

    d.implementation();
    d.static_sub_func();
    b.static_func();
    b.interface();

    return 0;
}
