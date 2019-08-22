#include <iostream>

using namespace std;

class OnlyOne
{
public:
        static OnlyOne& Instance()
        {//thread safe in C++11 and later
                static OnlyOne theSingleInstance;
                return theSingleInstance;
        }
private:
        OnlyOne(){}
        OnlyOne(const OnlyOne& root) = delete;
        OnlyOne& operator=(const OnlyOne&) = delete;
};

class Singleton
{
protected:
    static Singleton* _self;
    Singleton() {}
    virtual ~Singleton() {}

public:
    static Singleton* Instance()
    {
        if(!_self)
        {//not thread safe
            _self = new Singleton();
        }
        return _self;
    }

    static bool DeleteInstance()
    {
        if(_self)
        {
            delete _self;
            _self = 0;
            return true;
        }
        return false;
    }
};

Singleton* Singleton::_self = 0;


int main()
{
    Singleton *p1 = Singleton::Instance();

    OnlyOne::Instance();

    cout << "Hello World!" << endl;
    return 0;
}
