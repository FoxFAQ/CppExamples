#include <iostream>

using namespace std;

template <typename T>
class templateClass
{
    T first_, second_;
public:
    templateClass(T first, T second) : first_(first), second_(second) {}
    T bigger();
};

template<>
class templateClass<char>
{
    char first_, second_;
public:
    templateClass(char first, char second) : first_(first), second_(second) {cout << "called char" << endl;}
    char bigger();
};

template<typename T>
inline T templateClass<T>::bigger() {return first_>second_?first_:second_;}

template<>
inline bool templateClass<bool>::bigger() {return first_|second_;}

inline char templateClass<char>::bigger() {return first_|second_;}//not exactly bigger here

template <typename T1, typename T2>
T1 smaller(T1 var1, T2 var2) {return  var1<var2?var1:var2;}

int main()
{
    cout << "Hello World!" << endl;

    cout << smaller(1.01, 2) << endl;
    templateClass<double> z1(7, 12);
    cout << z1.bigger() << endl;
    templateClass<char> charT(1,2);
    cout << charT.bigger() << endl;
    return 0;
}
