#include <iostream>
#include <map>
using namespace std;

int main(){
    map <int,string> m;

    m[1] = "Shruti";
    m[2] ="Chess";
    m[13] ="sports";    //ye insert karne ka ek tarika hai

    m.insert({5,"chota_bheem"});  //insert karne ka dusra tarika

     for(auto i:m){
        cout << i.first<<" "<< i.second <<endl;
    }

    // count is of bool type it can return 1 if the vaue is present else return 0 if the value is not present
    cout <<"finding 13 -> "<<m.count(13)<<endl;
    cout <<"finding 13 -> "<<m.count(-13)<<endl;

    cout << "befor erase" << endl;
    for(auto i:m){
        cout << i.first<<" "<< i.second <<endl;
    }
    m.erase(13);
    cout <<"after erase" << endl;
    for(auto i:m){
        cout << i.first<<" "<< i.second <<endl;
    }

    // find
    auto it = m.find(5);

    for(auto i=it; i!=m.end(); i++ ){
        cout <<(*i).first <<endl;
    }
    return 0;
}