#include <iostream>

using namespace std;

class FriendlyClass;

class AnotherFriendlyClass
{
public:
    AnotherFriendlyClass() {}
private:
    double privateFloat = 1.12345;

    friend void coutTwoClasses(AnotherFriendlyClass& objAFC, FriendlyClass& objF);
};

class FriendlyClass
{
public:
    FriendlyClass() : privateInt(0) {}

private:
    int privateInt = -100;

    friend void incrementPrivate(FriendlyClass& objF);

    friend void coutTwoClasses(AnotherFriendlyClass& objAFC, FriendlyClass& objF);
};

void incrementPrivate(FriendlyClass& objF)
{
    cout << objF.privateInt << " " << objF.privateInt++ << endl;
}

void coutTwoClasses(AnotherFriendlyClass& objAFC, FriendlyClass& objF)
{
    cout << objF.privateInt << " " << objAFC.privateFloat << endl;
}

int main()
{
    cout << "Hello World!" << endl;
    FriendlyClass objectF;
    AnotherFriendlyClass objectAFC;

    incrementPrivate(objectF);
    coutTwoClasses(objectAFC, objectF);

    return 0;
}
