#include <iostream>

using namespace std;

//class Gazillion
//{
//  public:
//    Gazillion()
//    {
//        m_value_one = s_num / Y;
//        m_value_two = s_num % Y;
//        ++s_num;
//    }
//    void report()
//    {
//        cout << m_value_one << m_value_two << ' ';
//    }
//    static int X, Y;
//  private:
//    int m_value_one;
//    int m_value_two;
//    static int s_num;
//};

//int Gazillion::X = 6, Gazillion::Y = 10, Gazillion::s_num = 0;

//int main()
//{
//  Gazillion matrix[Gazillion::X][Gazillion::Y];
//  for (int i = 0; i < Gazillion::X; ++i)
//  {
//    for (int j = 0; j < Gazillion::Y; ++j)
//      matrix[i][j].report();
//    cout << '\n';
//  }
//}

////////////////////////////////////////////BECOMES
class Gazillion
{
public:
    Gazillion(int value_one)
    {
        m_value_one = value_one;
        cout << "ctor: " << m_value_one << '\n';
    }
    ~Gazillion()
    {
        cout << m_value_one << ' ';
    }
    void report(int value_two)
    {
        cout << m_value_one << value_two << ' ';
    }
private:
    int m_value_one;
};

class Factory
{
public:
    static Gazillion *get_fly(int in)
    {
        if (!s_pool[in])
            s_pool[in] = new Gazillion(in);
        return s_pool[in];
    }
    static void clean_up()
    {
        cout << "dtors: ";
        for (int i = 0; i < X; ++i)
            if (s_pool[i])
                delete s_pool[i];
        cout << '\n';
    }
    static int X, Y;
private:
    static Gazillion *s_pool[];
};

int Factory::X = 6, Factory::Y = 10;
Gazillion *Factory::s_pool[] =
{
    0, 0, 0, 0, 0, 0
};

int main()
{
    for (int i = 0; i < Factory::X; ++i)
    {
        for (int j = 0; j < Factory::Y; ++j)
            Factory::get_fly(i)->report(j);
        cout << '\n';
    }
    Factory::clean_up();
}
