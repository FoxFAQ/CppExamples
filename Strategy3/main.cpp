#include <iostream>

struct Strategy_1
{
    void use(){ std::cout << "Strategy_1" << std::endl; }
};

struct Strategy_2
{
    void use(){ std::cout << "Strategy_2" << std::endl; }
};

struct Strategy_3
{
    void use(){ std::cout << "Strategy_3" << std::endl; }
};

template <class Operation>
struct Client: public Operation
{
    void useStrategy()
    {
        this->use();
    }
};

int main (int /*argc*/, char* /*argv*/[])
{
    Client<Strategy_1> customClient1;
    customClient1.useStrategy();

    Client<Strategy_2> customClient2;
    customClient2.useStrategy();

    Client<Strategy_3> customClient3;
    customClient3.useStrategy();

    return 0;
}
