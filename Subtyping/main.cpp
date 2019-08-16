#include <iostream>

using namespace std;

class A {
 public:
  void DoSomethingALike() const {}
};

class B : public A {
 public:
  void DoSomethingBLike() const {}
};

void UseAnA(const A& a) {
  a.DoSomethingALike();
}

void SomeFunc() {
  B b;
  UseAnA(b);  // b can be substituted for an A.
}

int main()
{
    cout << "Hello World!" << endl;
    SomeFunc();
    return 0;
}
