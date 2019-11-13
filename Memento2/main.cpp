# include <iostream>
using namespace std;

class Originator {

    int state;

public:

    Originator();

    class Memento;

    Memento* getMemento();
    void setState(int);
    void dumpState();

    class Memento {

        friend class Originator;

    private:

        int state;
        Originator* org;

    public:

        Memento();
        void restoreState();

    };


};

Originator::Originator(): state(0) {

}

void Originator::setState(int s) {
    state = s;
}

void Originator::dumpState() {
    cout << "State: " << state << endl;
}

Originator::Memento::Memento(): state(0) {

}

Originator::Memento* Originator::getMemento() {
    Originator::Memento* m = new Originator::Memento();
    m->org = this;
    m->state = state;
    return m;
}


void Originator::Memento::restoreState() {

    org->state = state;
}


int main(void) {

    Originator org;
    org.setState(1);
    org.dumpState();

    Originator::Memento* m1 = org.getMemento();

    org.setState(2);
    org.dumpState();

    m1->restoreState();
    org.dumpState();
    delete m1;
}
