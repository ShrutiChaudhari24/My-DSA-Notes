#if  !defined(BIRD_H)
#define BIRD_H

#include <bits/stdc++.h>
using namespace std;

class Bird{
    public:
    virtual void eat() = 0;
    virtual void fly() = 0;
    // classes that inherits this class
    // has to implement pure virtual function
};

class sparrow: public Bird{
    public:
    void eat(){
        cout << "sparrow is eating\n";
    }
    void fly(){
        cout << "sparrow is flying\n";
    }
};

class eagle: public Bird{
    public:
    void eat(){
        cout << "Eagle is eating\n";
    }
    void fly(){
        cout << "Eagle is flying\n";
    }
};

class pigeon: public Bird{
    public:
    void eat(){
        cout << "pigeon is eating\n";
    }
    void fly(){
        cout << "pigeon is flying\n";
    }
};

#endif // BIRD_H