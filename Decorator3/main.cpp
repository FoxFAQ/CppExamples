#include <iostream>

using namespace std;

#include <iostream>
using namespace std;

// 1. " Наименьший общий знаменатель"
class Widget
{
  public:
    virtual void draw() = 0;
};

// 3. Основной класс, использующий отношение "является"
class TextField: public Widget
{
    int width, height;
  public:
    TextField(int w, int h)
    {
        width = w;
        height = h;
    }

    /*virtual*/
    void draw()
    {
        cout << "TextField: " << width << ", " << height << '\n';
    }
};

// 2. Базовый класс второго уровня
class Decorator: public Widget  // 3. использует отношение "является"
{
    Widget *wid; // 4. отношение "имеет"
  public:
    Decorator(Widget *w)
    {
        wid = w;
    }

    /*virtual*/
    void draw()
    {
        wid->draw(); // 5. делегирование
    }
};

// 6. Дополнительное декорирование
class BorderDecorator: public Decorator
{
  public:
    BorderDecorator(Widget *w): Decorator(w){}

    /*virtual*/
    void draw()
    {
        // 7. Делегирование базовому классу и
        Decorator::draw();
        // 7. реализация дополнительной функциональности
        cout << "   BorderDecorator" << '\n';
    }
};

// 6. Дополнительное декорирование
class ScrollDecorator: public Decorator
{
  public:
    ScrollDecorator(Widget *w): Decorator(w){}

    /*virtual*/
    void draw()
    {
        // 7. Delegate to base class and add extra stuff
        Decorator::draw();
        cout << "   ScrollDecorator" << '\n';
    }
};

int main()
{
  // 8. Клиент ответственен за конфигурирование нужной функциональности
  Widget *aWidget = new BorderDecorator(
                      new BorderDecorator(
                        new ScrollDecorator
                          (new TextField(80, 24))));
  aWidget->draw();
}
