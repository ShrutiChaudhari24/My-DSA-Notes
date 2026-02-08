#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
    virtual void sound() = 0;   // pure virtual function
};

class Dog : public Animal {
public:
    void sound() {
        cout << "Dog barks" << endl;
    }
};

int main() {
    Animal* a = new Dog();
    a->sound();   // Output: Dog barks
}
