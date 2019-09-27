#include <iostream>
#include <memory>

class IComponent {
public:
    virtual void operation() = 0;
    virtual ~IComponent(){}
};

class Component : public IComponent {
public:
    virtual void operation() {
        std::cout<<"World!"<<std::endl;
    }
};

class DecoratorOne : public IComponent {
    std::shared_ptr<IComponent> m_component;

public:
    DecoratorOne(IComponent* component): m_component(component) {}

    virtual void operation() {
        std::cout << ", ";
        m_component->operation();
    }
};

class DecoratorTwo : public IComponent {
    std::shared_ptr<IComponent> m_component;

public:
    DecoratorTwo(IComponent* component): m_component(component) {}

    virtual void operation() {
        std::cout << "Hello";
        m_component->operation();
    }
};

int main() {
    DecoratorTwo obj(new DecoratorOne(new Component()));
    obj.operation(); // prints "Hello, World!\n"

    return 0;
}
