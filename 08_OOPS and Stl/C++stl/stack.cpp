// stack => last in first out
#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack <string> s;  //creating a stack of string

    s.push("Hello");
    s.push("everone");
    s.push("Shruti");
    s.push("is here");

    cout <<"Top Element -> " << s.top() << endl;   //o/p := is here
 
    s.pop();  //deleting the element //yaha subsae phele subsae upper "top" ka element delete hoga 
  
    cout <<"Top Element -> " << s.top() << endl; //abb ager hum fir sae subsae top ka element dheake tho //o/p := Shruti

    // to check weather the stack is empty or not
    cout << "Empty or not : = " <<s.empty() << endl; 

}