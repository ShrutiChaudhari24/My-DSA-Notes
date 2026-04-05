# include <bits/stdc++.h>
using namespace std;

class Shape{
    public:
    // virtual nahi likha hota tho eary binding ho jati aur generic draw method call ho jata but virtual likh dene sae hum nae compiler ko kahe diya ki ye virtual matlab ess ko seriously mat lo runtime pae dheak lena abhi ess ko compile time pae consider mat karo
    void draw(){
        cout << "Generic Drawing......" << endl;
    }
};

class Circle: public Shape{
    public:
        void draw() {
            cout << "Circle Drawing....." << endl;
        }


};

class Rectangle: public Shape{
    public:
        void draw() { // ye override keyword sae hota kuch nahi hai this is just to show that this function override the base class function 
            cout << "Rectangle Drawing....." << endl;
        }
};

class Triangle: public Shape{
    public:
        void draw() {
            cout << "Triangle Drawing....." << endl;
        }
};

void ShapeDrawing (Shape *s){
    s->draw(); // draw is polymorphic

}

int main(){
    // Circle c; // ye stack pae bana hi object is created statically
    // // c.draw();
    // Rectangle r; // ye stack pae bana hi object is created statically
    // // r.draw();
    
    // // Shape *s = &c; // upcasting -> parent class ka pointer child class ko hold kar raha hai
    // ShapeDrawing(&c);
    // ShapeDrawing(&r);
    
    // Triangle* t = new Triangle(); // ye heap pae bana huya hai object is created dynamically
    // ShapeDrawing(t);

    // without virtual keyword

    Shape *s = new Shape();
    s->draw();

    // upcasting -> Child ka object bana kae parent mae store karna
    Shape *s3 = new Circle();
    s3->draw();

    Circle *c = new Circle();
    c->draw();

    // DownCasting -> parent ka object bana kae child mae store karna
    Shape * s2 = new Shape();
    Circle *c2 = (Circle *)s2;
    c2->draw();




    return 0;
}