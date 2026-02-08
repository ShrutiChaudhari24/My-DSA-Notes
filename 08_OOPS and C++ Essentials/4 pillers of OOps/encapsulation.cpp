// // ❌ Without Encapsulation (Bad Practice)
// class Dog {
// public:
//     int age;   // anyone can change directly
// };

// int main() {
//     Dog d;
//     d.age = -5;   // invalid but allowed ❌
// }


// ✅ With Encapsulation (Correct Way) 
#include <bits/stdc++.h>
using namespace std;

class Dog {   // variables or data of a class are hidden from any other class and can be accessed only through any member function of that respective class and in encapsulation the data in a class is hidden from other classes which is also known as data hiding .so it provided thes security by wrapping the data 
private:
    int age;   // hidden data

public:   // using getters and setters (members functions)  
    void setAge(int a) {
        if(a > 0)
            age = a;
    }

    int getAge() {
        return age;
    }
};

int main() {
    Dog d;
    d.setAge(3);
    cout << d.getAge();  // Output: 3
}
