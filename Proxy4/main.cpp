#include <iostream>

using namespace std;

/**
 * "Subject"
 */
class IMath
{
public:
    virtual double add(double, double) = 0;
    virtual double sub(double, double) = 0;
    virtual double mul(double, double) = 0;
    virtual double div(double, double) = 0;
};

/**
 * "Real Subject"
 */
class Math : public IMath
{
public:
    virtual double add(double x, double y)
    {
        return x + y;
    }

    virtual double sub(double x, double y)
    {
        return x - y;
    }

    virtual double mul(double x, double y)
    {
        return x * y;
    }

    virtual double div(double x, double y)
    {
        return x / y;
    }
};

/**
 * "Proxy Object"
 */
class MathProxy : public IMath
{
public:
    MathProxy()
    {
        math = new Math();
    }
    virtual ~MathProxy()
    {
        delete math;
    }
    virtual double add(double x, double y)
    {
        return math->add(x, y);
    }

    virtual double sub(double x, double y)
    {
        return math->sub(x, y);
    }

    virtual double mul(double x, double y)
    {
        return math->mul(x, y);
    }

    virtual double div(double x, double y)
    {
        return math->div(x, y);
    }

private:
    IMath *math;
};

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    // Create math proxy
    IMath *proxy = new MathProxy();

    // Do the math
    cout << "4 + 2 = " << proxy->add(4, 2) << endl;
    cout << "4 - 2 = " << proxy->sub(4, 2) << endl;
    cout << "4 * 2 = " << proxy->mul(4, 2) << endl;
    cout << "4 / 2 = " << proxy->div(4, 2) << endl;

    delete proxy;
    return 0;
}
