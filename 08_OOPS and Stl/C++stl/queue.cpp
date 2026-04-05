#include <iostream>
# include <queue>

using namespace std;

int main(){

    queue <string> q;  //createing a queue of string type

    // inserting elements in queue
    q.push("I");
    q.push("like");
    q.push("to");
    q.push("play");
    q.push("chess");

    cout <<"size before pop := "<< q.size() << endl;

    cout <<"first element : = "<<q.front() << endl;  //o/p := I
    q.pop();  
    cout <<"first element : = "<<q.front() << endl; //o/p := like

    cout <<"size after pop := "<< q.size() << endl;
    return 0;
}