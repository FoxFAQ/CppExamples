#include <iostream>

using namespace std;

class BaseClass
{
public:
    BaseClass() {}
    int publicV_ = 1; //INHERITED
    void publicFunc() {publicV_ = 2; protectedV_ = 3; privateV_ = 4; cout << publicV_ << protectedV_ << privateV_ << endl;} //OVERRIDEN METHOD
protected:
    int protectedV_ = 1; //INHERITED
    void protectedFunc() {publicV_ = 3; protectedV_ = 4; privateV_ = 5; cout << publicV_ << protectedV_ << privateV_ << endl;} //INHERITED
private:
    int privateV_ = 1; //NOT INHERITED
    void privateFunc() {publicV_ = 5; protectedV_ = 6; privateV_ = 7; cout << publicV_ << protectedV_ << privateV_ << endl;} //NOT INHERITED
};

class derivedPublic : public BaseClass
{
public:
    derivedPublic() {}
    void testDerivedPublic() {publicV_ = 100; protectedV_ = 100; /*privateV_ = 100; C2248*/ cout << publicV_ << protectedV_ /*<< privateV_ */<< endl; publicFunc(); protectedFunc(); /*privateFunc();*/}//SAME
    friend void test(derivedPublic& derP);

    void publicFunc() {publicV_ = 2; protectedV_ = 3; /*privateV_ = 4;*/ cout << publicV_ << protectedV_ << /*privateV_ <<*/ endl;}//OVERRIDING METHOD

protected:
    void testDerivedProtected() {publicV_ = 100; protectedV_ = 100; /*privateV_ = 100; C2248*/ cout << publicV_ << protectedV_ /*<< privateV_ */ << endl; publicFunc(); protectedFunc(); /*privateFunc();*/}//SAME
private:
    void testDerivedPrivate() {publicV_ = 100; protectedV_ = 100; /*privateV_ = 100; C2248*/ cout << publicV_ << protectedV_ /*<< privateV_ */ << endl; publicFunc(); protectedFunc(); /*privateFunc();*/}//SAME
};

void test(derivedPublic& derP)
{//Same visibility as a function inside a class like testDerivedPublic() etc, in all cases of inheritance
    derP.publicV_ = 1;
    derP.protectedV_ = 1;
//    derP.privateV_ = 1;//C2248
}

class derivedProtected : protected BaseClass
{
public:
    derivedProtected() {}
    void testDerivedPublic() {publicV_ = 100; protectedV_ = 100; /*privateV_ = 100; C2248*/ cout << publicV_ << protectedV_ /*<< privateV_ */<< endl; publicFunc(); protectedFunc(); /*privateFunc();*/}//SAME
protected:
    void testDerivedProtected() {publicV_ = 100; protectedV_ = 100; /*privateV_ = 100; C2248*/ cout << publicV_ << protectedV_ /*<< privateV_ */ << endl; publicFunc(); protectedFunc(); /*privateFunc();*/}//SAME
private:
    void testDerivedPrivate() {publicV_ = 100; protectedV_ = 100; /*privateV_ = 100; C2248*/ cout << publicV_ << protectedV_ /*<< privateV_ */ << endl; publicFunc(); protectedFunc(); /*privateFunc();*/}//SAME
};

class derivedPrivate : private BaseClass
{
public:
    derivedPrivate() {}
    void testDerivedPublic() {publicV_ = 100; protectedV_ = 100; /*privateV_ = 100; C2248*/ cout << publicV_ << protectedV_ /*<< privateV_ */<< endl; publicFunc(); protectedFunc(); /*privateFunc();*/}//SAME
protected:
    void testDerivedProtected() {publicV_ = 100; protectedV_ = 100; /*privateV_ = 100; C2248*/ cout << publicV_ << protectedV_ /*<< privateV_ */ << endl; publicFunc(); protectedFunc(); /*privateFunc();*/}//SAME
private:
    void testDerivedPrivate() {publicV_ = 100; protectedV_ = 100; /*privateV_ = 100; C2248*/ cout << publicV_ << protectedV_ /*<< privateV_ */ << endl; publicFunc(); protectedFunc(); /*privateFunc();*/}//SAME
};

///////////////////////////////////////////////////////////////////////////

class der2fromProtected : public derivedProtected
{
public:
    der2fromProtected() {}
    void testDerivedPublic() {publicV_ = 100; protectedV_ = 100; /*privateV_ = 100; C2248*/ cout << publicV_ << protectedV_ /*<< privateV_ */<< endl; publicFunc(); protectedFunc(); /*privateFunc();*/}//SAME
protected:
    void testDerivedProtected() {publicV_ = 100; protectedV_ = 100; /*privateV_ = 100; C2248*/ cout << publicV_ << protectedV_ /*<< privateV_ */ << endl; publicFunc(); protectedFunc(); /*privateFunc();*/}//SAME
private:
    void testDerivedPrivate() {publicV_ = 100; protectedV_ = 100; /*privateV_ = 100; C2248*/ cout << publicV_ << protectedV_ /*<< privateV_ */ << endl; publicFunc(); protectedFunc(); /*privateFunc();*/}//SAME
};

class der2FromPrivate : public derivedPrivate
{
public:
    der2FromPrivate() {}

    // PUBLIC AND PROTECTED became Private in derivedPrivate and now they are NOT INHERITED

//    void testDerivedPublic() {publicV_ = 100; protectedV_ = 100; /*privateV_ = 100; C2248*/ cout << publicV_ << protectedV_ /*<< privateV_ */<< endl; publicFunc(); protectedFunc(); /*privateFunc();*/}//SAME
//protected:
//    void testDerivedProtected() {publicV_ = 100; protectedV_ = 100; /*privateV_ = 100; C2248*/ cout << publicV_ << protectedV_ /*<< privateV_ */ << endl; publicFunc(); protectedFunc(); /*privateFunc();*/}//SAME
//private:
//    void testDerivedPrivate() {publicV_ = 100; protectedV_ = 100; /*privateV_ = 100; C2248*/ cout << publicV_ << protectedV_ /*<< privateV_ */ << endl; publicFunc(); protectedFunc(); /*privateFunc();*/}//SAME
};

int main()
{
    cout << "Hello World!" << endl;

    /*
     *
     *
     * Base class visibility	Derived class visibility
            Public derivation	Protected derivation	Private derivation
Private →   Not inherited       Not inherited           Not inherited
Protected → Protected           Protected               Private
Public →    Public              Protected               Private

*/
    derivedPublic derPub;
    derPub.publicFunc(); // Base function changes all the stuff possible
//    derPub.protectedFunc();//C2248
//    derPub.privateFunc();//C2248

    derPub.publicV_ = 11;
//    derPub.protectedV_ = 11;//C2248
//    derPub.privateV_ = 11;//C2248

    derPub.testDerivedPublic();
//    derPub.testDerivedProtected();//C2248
//    derPub.testDerivedPrivate();//C2248
/////////////////////////////////////////////////////////////////////////

    derivedProtected derProt; //public stuff of BaseClass became protected!
//    derProt.publicFunc();//C2247: 'BaseClass::publicFunc' not accessible because 'derivedProtected' uses 'protected' to inherit from 'BaseClass'
//    derProt.protectedFunc();//C2248
//    derProt.privateFunc();//C2248

//    derProt.publicV_ = 11;//C2247: 'BaseClass::publicV_' not accessible because 'derivedProtected' uses 'protected' to inherit from 'BaseClass'
//    derProt.protectedV_ = 11;//C2248
//    derProt.privateV_ = 11;//C2248

    derProt.testDerivedPublic();
//    derProt.testDerivedProtected();//C2248
//    derProt.testDerivedPrivate();//C2248
/////////////////////////////////////////////////////////////////////////

    derivedPrivate derPriv; //public stuff of BaseClass became private! SAME AS derProt for the first inheritance
//    derPriv.publicFunc();//C2247: 'BaseClass::publicFunc' not accessible because 'derivedProtected' uses 'private' to inherit from 'BaseClass'
//    derPriv.protectedFunc();//C2248
//    derPriv.privateFunc();//C2248

//    derPriv.publicV_ = 11;//C2247: 'BaseClass::publicV_' not accessible because 'derivedProtected' uses 'private' to inherit from 'BaseClass'
//    derPriv.protectedV_ = 11;//C2248
//    derPriv.privateV_ = 11;//C2248

    derPriv.testDerivedPublic();
//    derPriv.testDerivedProtected();//C2248
//    derPriv.testDerivedPrivate();//C2248
    return 0;
}
