# include <bits/stdc++.h>
using namespace std;

class Dog{
    public:

    // this are the properties/attributes -> data members
    string breed;
    string size;
    int age;
    string colour;

    // this  are the behaviors/methods -> member functions
    void eat(){
        cout << "Dog eats dog food" << endl;
    }

    void sleep(){
        cout << "Dog sleeps" << endl;
    }

    void sit(){
        cout << "Dog sits" << endl;
    }

    void run(){
        cout << "Dog Runs" << endl;
    }

};

int main(){
    Dog D1;

    D1.breed = "Labrador";
    cout <<  D1.breed << endl;
    D1.age = 5;
    cout << D1.age << endl;

    D1.eat();
    D1.sleep();

    return 0;
}