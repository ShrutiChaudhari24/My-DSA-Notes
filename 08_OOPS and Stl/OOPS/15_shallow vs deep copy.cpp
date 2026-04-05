#include <bits/stdc++.h>
using namespace std;

class abc{
    public:
    int x;
    int *y;

    abc(int _x, int _y):x(_x), y(new int(_y)){}

    // default dumb copy constructor: it does SHALLOW COPY
    /*
    abc(const abc &obj){
        x = obj.x;
        y = obj.y;
    }
    */

    // SMART DEEP COPY
    abc (const abc &obj){
        x = obj.x;
        y = new int(*obj.y);
    } 

    void print () const
    {
        printf("x:%d\nPTR Y:%p\nContent of Y (*y):%d\n\n", x, y, *y);
    }
    
    ~abc(){
        delete y;
    }
};


int main(){
    abc a{1,2};
    a.print();

    // abc b(a);
    abc b = a; // call hota hai, COPY Constructor
    b.print();

    *b.y = 20;
    cout << "Printing b\n";
    b.print();

    cout << "Printing a\n";
    a.print();

    // delete a; double free of object this is a message we get that's why shallow copy is very problematic
    


    return 0;
}