#include <iostream>

using namespace std;

class OperatorsClass
{
public:
    int value;
    OperatorsClass() : value(0) {}
    OperatorsClass(int val) : value(val) {}
    OperatorsClass operator+(OperatorsClass& oClass)
    {
        OperatorsClass temp;
        temp.value = value + oClass.value;
        cout << &temp << " " << temp.value << endl;
        return temp;
    }
};

int main()
{
    cout << "Hello World!" << endl;

    OperatorsClass a(11);
    OperatorsClass b(12);
    OperatorsClass c;

    c = a+b;
    cout << &c << " " << c.value << endl;
    return 0;
}
