#include <bits/stdc++.h>
using namespace std;

class Dog {
public:
    string* name;

    Dog(string n) {
        name = new string(n);
    }

    void show() {
        cout << *name << endl;
    }
};

int main() {
    Dog d1("Tommy");
    Dog d2 = d1;   // shallow copy

    *d2.name = "Max";  // changes d1 as well
    d1.show();         // Output: Max
}
