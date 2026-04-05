# include <bits/stdc++.h>
using namespace std;

class A{
    private:
    int x;

    public:
    A(int _val):x (_val){};

    int getX() const {return x;}
    void setX(int _val){x = _val;}

    friend class B; // ye likhne sae hum A kae private members ko bhi access kar sakte hai directly
};

class B{
    public:
    void print(const A &a){
        // cout << a.getX() << endl;
        cout << a.x << endl;  // as B is friend of A we can directly access private data members and methods of A
    }
};
int main(){
    A a(5);
    B b;
    b.print(a);

    return 0;
}