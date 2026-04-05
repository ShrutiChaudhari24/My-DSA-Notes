# include<iostream>
#include <array>
using namespace std;

int main (){
    
    // basic array
    int basicArray [5] = {1,2,3,4,5};
    
    // STL wala array
    array <int ,4> a ={1,2,3,4};
    // ager humey size nikalna hai stl array ka tho easae nikalta hai
    int size = a.size(); 

    for(int i=0; i<size; i++){
        cout << a[i] << endl;  //easae square bracket ka use karkae bhi access kar sakte stl array ko
    }

    cout << "Element at 2nd index " << a.at(2) <<endl;
    cout <<"Empty or not->" <<a.empty() <<endl;   //returns 0 or 1 (bool type)

    // we can find first and last element
    cout <<"First element ->"<<a.front() <<endl;
    cout <<"last element ->"<<a.back() <<endl;
    return 0;
}