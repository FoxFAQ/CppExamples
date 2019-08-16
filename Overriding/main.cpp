#include <iostream>

class Animal {
public:
    void /*невиртуальный*/ move() {
        std::cout << "This animal moves in some way" << std::endl;
    }
    virtual void eat() {
        std::cout << "Animal eat something!" << std::endl;
    }
    virtual ~Animal(){} // деструктор
};

class Wolf : public Animal {
public:
    void move() {
        std::cout << "Wolf walks" << std::endl;
    }
    void eat(void) { // метод eat переопределён и тоже является виртуальным
        std::cout << "Wolf eats meat!" << std::endl;
    }
};

int main() {
    Animal* zoo[] = {new Wolf(), new Animal()};
    for(Animal* a:zoo) {
        a->move();
        a->eat();
        delete a; // Так как деструктор виртуальный, для каждого
                  // объекта вызовется деструктор его класса
    }
    return 0;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
/*
struct Rectangle {
    Rectangle() {}
    virtual void VirtualPrint() const {std::cout << "BASE class overriden virtual VirtualPrint func " << std::endl;}
    void Print() const {std::cout << "BASE class PRINT func " << std::endl;}
    virtual void PrintFinal() const final {std::cout << "BASE class PRINT func " << std::endl;} // a method that is declared final in the super class cannot be overridden
};

struct Box : public Rectangle {
    Box() {} //a method can be declared OVERRIDE to make the compiler check that it overrides a method in the base class.
    void VirtualPrint() const override {std::cout << "Overriding DERIVED class VirtualPrint func " << std::endl;}
    void Print() const /*override*/ /* {std::cout << "DERIVED class PRINT func " << std::endl;}//only virtual methods can be overriden C3668
//    void PrintFinal() const override {std::cout << "DERIVED class PRINT func " << std::endl;} //C3248 final can't be overriden
};

int main(int argc, char** argv) {
    Rectangle rectangle;
    rectangle.VirtualPrint();std::cout << std::endl;//SHOWS BASE since it was never Derived class that was recasted

    Box box;
    // The pointer to the most overridden method in the vtable in on Box::print,
    // but this call does not illustrate overriding.
    box.VirtualPrint();//SHOWS DERIVED
    box.Rectangle::VirtualPrint();//SHOWS BASE

    // This call illustrates overriding.
    Rectangle& recTest = static_cast<Rectangle&>(box);
    recTest.VirtualPrint();//SHOWS DERIVED even recTest is Rectangle& it still calls Box::VirtualPrint() because it's overriding method
    recTest.Rectangle::VirtualPrint(); std::cout << std::endl;//SHOWS BASE
//////////////////////////////////////////////////////////////////////////////////////
    box.Print();//SHOWS DERIVED
    box.Rectangle::Print();//SHOWS BASE
    recTest.Print();//SHOWS BASE
    recTest.Rectangle::Print();//SHOWS BASE
}
*/

//--------------------------------------------------------------------------------------------------------------------------------------------------------

/*
struct Base
{
    virtual void foo();
};

struct A : Base
{
    void foo() final; // Base::foo is overridden and A::foo is the final override
    void bar() final; // Error: non-virtual function cannot be overridden or be final
};

struct B final : A // struct B is final
{
    void foo() override; // Error: foo cannot be overridden as it's final in A
};

struct C : B // Error: B is final
{
};
*/
