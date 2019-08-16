#include <iostream>

class A {
public:
    virtual int foo() {
        return 1;
    }
};

class B : public virtual A {};

class C : public virtual A {};

class D : public B, public C {};

int main () {
    D d;
    std::cout << d.foo() << std::endl; //error: C2385: ambiguous access of 'foo' IF virtual is not used
    //If Class B and Class C don't have virtual inheritance then D::C:A::foo() != D::B::A::foo()
    //but now since it's virtual then D::C == D::B for the foo()
    return 0;
}
