# include <bits/stdc++.h>
using namespace std;

class abc{
    public:
    /* static */ int x, y;

    abc() : x(0), y(0){}

    static void print() /*const*/{
        // this
        /*cout << this->x << " " << this->y << endl;*/

        // No this pointer accessiable
        printf("I am in Static %s\n", __FUNCTION__);
    }
};


int main(){
    /*
    abc obj1 = {1,2};
    abc obj2 = {4,5};
    */

    abc obj1;
    obj1.x = 1;
    obj1.y = 2;
    obj1.print();
    abc obj2;
    obj2.x = 10;
    obj2.y = 20;
    obj2.print();

    obj1.print();
    obj2.print();



    return 0;
}