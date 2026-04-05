# include <iostream>
#include <deque>
using namespace std;

// dec or deque is a data structure in which we can insert and delete elements from front and back as well
int main(){
    deque <int> d;  //Creating the deque

    d.push_back(1);  //piche sae 1 dala
    d.push_front(12);  //front sae 12 dala

  // print karwa kae dheaktae hai deque ko
   for(int i:d){
    cout << i <<" ";
  }cout << endl;

//   d.pop_back();  //piche sae 1 dala tha tho 1 hat jayega
//   for(int i:d){
//     cout << i <<" ";
//   }cout << endl;

//   d.pop_front(); //aagae sae 12 hat jayega

// if we want to frint element at first index
cout << "Print first index element := " <<d.at(1) << endl;  //o/p: = 12 

cout << "front " <<d.front() << endl;  //front element := 12
cout <<"back " <<d.back() << endl;  //back element := 1

cout << "Empty  or not := " <<d.empty() <<endl;  //this is not empty so it will return 0

cout <<"before erase " <<d.size() <<endl;
d.erase(d.begin(),d.begin()+1); //this is use to delete first element from deque
cout <<"after erase " <<d.size() <<endl;

for(int i:d){
  cout <<i<<endl;
}
    return 0;
}