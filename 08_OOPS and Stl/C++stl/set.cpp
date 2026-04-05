# include <iostream>
#include <set>
using namespace std;

int main(){
    set <int> s;
    s.insert(5);
    s.insert(5);   //kitne bhi bar 5 dal doo ek hi bar aayega
    s.insert(5);
    s.insert(5);
    s.insert(1);  //ess ki insert ki timp complexity O(log n) hoti hai
    s.insert(6);
    s.insert(0);

    for(auto i : s){
        cout << i <<endl;  //sorted order mae print honge
    }cout << endl;

    set <int> ::iterator it = s.begin();
    it++;

    s.erase(it);
    for(auto i:s){
       cout << i << endl;
    }

    cout <<" 5 is present or not " <<s.count(5) <<endl; // count () batata hai ki ye element hai ya nahi hai

    set <int> ::iterator itr = s.find(5); //find is used to find the iterator 
    cout << "value present at itr -> "<< *it <<endl;

    for(auto it = itr; it!=s.end();it++){
        cout << *it << " ";
    }cout << endl;

    // unordered set aur set mae ye difference hai ki set mae elements sorted order mae hote hai aur unordered set mae randomly jab hum un ko fetch kare tab
    // insert,find,count,erase en charo method ki complexity O(n) hai
    // size,begin,end,empty en ki O(1) hai
}
