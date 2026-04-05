# include <bits/stdc++.h>
using namespace std;

#define PI 3.24159465 // this is macro 
// macro use karne sae redability increase ho jati hai ye preprocessing step mae jaha PI likha hai waha 3.14 chipka dega aur ye koi space bhi nahi leta 
#define MAX(x,y) (x>y ? x : y);

float circleArea(float r){
    //return 3.14 * r *r;
    return PI * r *r;
}

float circlPerimeter(float r){
    //return 3.14 * r *r;
    return 2 * PI * r;
}

void fun2(){
    int x = 6;
    int y = 17;
    int z =  MAX(x,y); 
    cout << z << endl;
}

void fun(){
    int a = 16;
    int b = 121;
    int c =  MAX(a,b); 
    cout << c << endl;
}


int main(){
    cout << circleArea(65.4) << endl;
    cout << circlPerimeter(65.4) << endl;
    fun2();
    fun();
    return 0;
}