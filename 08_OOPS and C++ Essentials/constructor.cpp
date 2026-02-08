// ✅ What is a Constructor?

// A constructor is a special member function of a class that:

// Has the same name as the class

// Has no return type

// Is automatically called when an object is created

// Used to initialize data members

#include <bits/stdc++.h>
using namespace std;

class Dog {
public:
    string breed;
    int age;

    // Constructor
    Dog(string b, int a) {
        breed = b;
        age = a;
    }

    void display() {
        cout << breed << " " << age << endl;
    }
};

int main() {
    // 🔹 How is Constructor Called?
    Dog d1("Labrador", 3);   // Constructor called here  // 👉 Automatically when object is created:
    d1.display();
}

// What is a Default Constructor?

// A default constructor is a constructor that:
// Takes no parameters
// Is automatically called when an object is created without arguments
// Initializes data members with default values
