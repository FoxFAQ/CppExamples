#include <iostream>
#include <vector>
#include <map>

using namespace std;

//Реализация паттерна Ptototype на основе обобщенного конструктора
//В виде обобщенного конструктора на основе прототипов, когда в полиморфном базовом классе Prototype
//определяется статический метод, предназначенный для создания объектов.
//При этом в качестве параметра в этот метод должен передаваться идентификатор типа создаваемого объекта.

// Идентификаторы всех родов войск
enum Warrior_ID { Infantryman_ID, Archer_ID, Horseman_ID };

class Warrior;  // Опережающее объявление
typedef map<Warrior_ID, Warrior*> Registry;

// Реестр прототипов определен в виде Singleton Мэйерса
Registry& getRegistry()
{
    static Registry _instance;
    return _instance;
}

// Единственное назначение этого класса - помощь в выборе нужного
// конструктора при создании прототипов
class Dummy { };

// Полиморфный базовый класс. Здесь также определен статический
// обобщенный конструктор для создания боевых единиц всех родов войск
class Warrior
{
public:
    virtual Warrior* clone() = 0;
    virtual void info() = 0;
    virtual ~Warrior() {}
    // Параметризированный статический метод для создания воинов
    // всех родов войск
    static Warrior* createWarrior( Warrior_ID id ) {
        Registry& r = getRegistry();
        if (r.find(id) != r.end())
            return r[id]->clone();
        return 0;
    }
protected:
    // Добавление прототипа в множество прототипов
    static void addPrototype( Warrior_ID id, Warrior * prototype ) {
        Registry& r = getRegistry();
        r[id] = prototype;
    }
    // Удаление прототипа из множества прототипов
    static void removePrototype( Warrior_ID id ) {
        Registry& r = getRegistry();
        r.erase( r.find( id));
    }
};


// В производных классах различных родов войск в виде статических
// членов-данных определяются соответствующие прототипы
class Infantryman: public Warrior
{
public:
    Warrior* clone() {
        return new Infantryman( *this);
    }
    void info() {
        cout << "Infantryman" << endl;
    }
private:
    Infantryman( Dummy ) {
        Warrior::addPrototype( Infantryman_ID, this);
    }
    Infantryman() {}
    static Infantryman prototype;
};

class Archer: public Warrior
{
public:
    Warrior* clone() {
        return new Archer( *this);
    }
    void info() {
        cout << "Archer" << endl;
    }
private:
    Archer(Dummy) {
        addPrototype( Archer_ID, this);
    }
    Archer() {}
    static Archer prototype;
};

class Horseman: public Warrior
{
public:
    Warrior* clone() {
        return new Horseman( *this);
    }
    void info() {
        cout << "Horseman" << endl;
    }
private:
    Horseman(Dummy) {
        addPrototype( Horseman_ID, this);
    }
    Horseman() {}
    static Horseman prototype;
};


Infantryman Infantryman::prototype = Infantryman( Dummy());
Archer Archer::prototype = Archer( Dummy());
Horseman Horseman::prototype = Horseman( Dummy());


int main()
{
    vector<Warrior*> v;
    v.push_back( Warrior::createWarrior( Infantryman_ID));
    v.push_back( Warrior::createWarrior( Archer_ID));
    v.push_back( Warrior::createWarrior( Horseman_ID));

    for(int i=0; i<v.size(); i++)
        v[i]->info();

    //Для приведенной реализации паттерна Prototype можно отметить следующие особенности:

    //Создавать новых воинов можно только при помощи обобщенного конструктора.
    //Их непосредственное создание невозможно, так как соответствующие конструкторы объявлены со спецификатором доступа private.

    //Отсутствует недостаток реализации на базе обобщенного конструктора для паттерна Factory Method,
    //а именно базовый класс Warrior ничего не знает о своих подклассах.
}
