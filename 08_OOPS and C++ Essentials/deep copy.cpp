#include <bits/stdc++.h>
using namespace std;

class Dog {
public:
    string* name;

    Dog(string n) {
        name = new string(n);
    }

    // Deep copy constructor
    Dog(const Dog &d) {
        name = new string(*d.name);
    }

    void show() {
        cout << *name << endl;
    }
};

int main() {
    Dog d1("Tommy");
    Dog d2 = d1;  // deep copy

    *d2.name = "Max";
    d1.show();    // Output: Tommy
}
