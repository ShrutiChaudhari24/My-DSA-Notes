# include <bits/stdc++.h>
using namespace std;

class Base{
    public:
    // 'virtual' is not allowed
    /*virtual*/ Base(){
        cout << "Base ctor\n";
    }

    virtual ~Base(){
        cout << "Base dtor\n";
    }
};

class Derived: public Base{
    public:
    Derived(){
        cout << "Derived ctor\n";
    }

    ~Derived(){
        cout << "Derived dtor\n";
    }
};

int main(){
    Base *b = new Derived();
    delete b;
    return 0;
}

// ctor cannot be virtual dtor can be