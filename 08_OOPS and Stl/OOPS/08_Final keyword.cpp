// final keyword is used in two main contexts:
// 1) prevents Class inheritance := if any class is marked as final they no other class can inherit from it
// 2) preventing virtual function overriding := the final specifer can also be used with virtual functions to prevent them from overridden in derived class

# include <bits/stdc++.h>
using namespace std;

// 1)
/*class A final{
    public: 
    int data;
};

class B: public A{ // a 'final' class type cannot be used as a base class
    int a; 
};
// error: cannot derive from 'final' base 'A' in derived type 'B'
*/

// 2)
/*class Shape{
    public:
    // virtual nahi likha hota tho eary binding ho jati aur generic draw method call ho jata but virtual likh dene sae hum nae compiler ko kahe diya ki ye virtual matlab ess ko seriously mat lo runtime pae dheak lena abhi ess ko compile time pae consider mat karo
    virtual void draw() final{
        cout << "Generic Drawing......" << endl;
    }
};

class Circle: public Shape{
    public:
        void draw() { // cannot override 'final' function "Shape::draw"
            cout << "Circle Drawing....." << endl;
        }


};

// error: overriding final function 'virtual void Shape::draw()'
//      virtual void draw() final{
                //   ^~~~
*/

int main(){
    /*Shape *s = new Shape;
    
    Circle *c = new Circle();
    c->draw();
*/
    return 0;
}