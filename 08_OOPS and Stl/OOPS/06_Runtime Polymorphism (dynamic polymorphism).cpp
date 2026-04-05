# include <bits/stdc++.h>
using namespace std;

class Shape{
    public:
    // virtual nahi likha hota tho eary binding ho jati aur generic draw method call ho jata but virtual likh dene sae hum nae compiler ko kahe diya ki ye virtual matlab ess ko seriously mat lo runtime pae dheak lena abhi ess ko compile time pae consider mat karo
    virtual void draw(){
        cout << "Generic Drawing......" << endl;
    }
};

class Circle: public Shape{
    public:
        void draw() override {
            cout << "Circle Drawing....." << endl;
        }


};

class Rectangle: public Shape{
    public:
        void draw() override{ // ye override keyword sae hota kuch nahi hai this is just to show that this function override the base class function 
            cout << "Rectangle Drawing....." << endl;
        }
};

class Triangle: public Shape{
    public:
        void draw() override{
            cout << "Triangle Drawing....." << endl;
        }
};

void ShapeDrawing (Shape *s){
    s->draw(); // draw is polymorphic

}

int main(){
    Circle c; // ye stack pae bana hi object is created statically
    // c.draw();
    Rectangle r; // ye stack pae bana hi object is created statically
    // r.draw();
    
    // Shape *s = &c; // upcasting -> parent class ka pointer child class ko hold kar raha hai
    ShapeDrawing(&c);
    ShapeDrawing(&r);
    
    Triangle* t = new Triangle(); // ye heap pae bana huya hai object is created dynamically
    ShapeDrawing(t);


    return 0;
}