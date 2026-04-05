#include <iostream>
#include<vector>

using namespace std;

int main(){
    vector <int> v ;
    cout <<"capacity -> " << v.capacity() <<endl;  //o/p = capacity -> 0

    // if we want to insert element in vector we have a function called push_back
    v.push_back(1);
    cout <<"capacity -> " << v.capacity() <<endl;  //o/p = capacity -> 1

    v.push_back(2);
    cout <<"capacity -> " << v.capacity() <<endl;  //o/p = capacity -> 2

    v.push_back(3);
    cout <<"capacity -> " << v.capacity() <<endl;  //o/p = capacity -> 4 //capacity batata hai kitne element kae liye space assign hoya pada hai 
    cout <<"size -> " << v.size() <<endl;  //o/p = size -> 3 //size batata hai kitne element pade hai

    cout <<"element at 2nd index is " <<v.at(2) << endl;

    // first and last element
    cout <<"front -> " <<v.front() <<endl;
    cout <<"back -> " <<v.back() <<endl;


    // pop_back function //jesae push_back sae hum element insert karte haii pop_back sae delete karte hai
    cout <<"before pop" <<endl;
    for(int i:v){
        cout <<i<<" ";
    } cout << endl;
   
    v.pop_back();

    cout <<"after pop" <<endl;
    for (int i:v)
    {
        cout << i <<" ";
    }
    
    cout <<"before clear size " <<v.size() <<endl;
    v.clear();    //clear is used to remove all the elements in vector
    cout << "after clear size " <<v.size() << endl;  //size change hoga
    cout << "after clear capacity " <<v.capacity() << endl;  //capacity remains the same

    // initialization of vector
    vector <int> a(5,1);  //vector a type is int size is 5 and all 5 elements are initialize by 1   //ager 1 nahi likha hota tho sare elements 0 sae default initialize ho jate
    cout <<"print a " << endl;
    for (int i:a){
        cout <<i<<" ";
    }cout << endl;

    // ager humey copy karna hai vector a kisi naye vector jis ka name hello hai uss mae
    vector <int> hello(a);
    for (int i:hello){
        cout << i << " ";
    }cout << endl;
    return 0;
}