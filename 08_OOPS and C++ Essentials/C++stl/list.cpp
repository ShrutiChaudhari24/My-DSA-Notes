# include <iostream>
# include <list>

using namespace std;
int main(){
    
    list <int> l;  //creating a list (declaration of list) 

    l.push_back(10);
    l.push_front(20);

    for(int i:l){
        cout << i <<" ";
    }cout << endl;

    l.erase(l.begin());
    cout << "After erase " ;

    for(int i:l){
        cout << i <<" ";
    }

    cout <<"size of list := "<<l.size() << endl;

    // if we want to copy our list to new list
    list <int> nayi_list(l);
    for (int i:nayi_list)
    {
       cout <<"nayi_lisy ka element " << i <<" ";
    }cout << endl;
    
    l.pop_back();
    for(int i:l){
        cout << i <<" ";
    }cout << endl;

    list <int> list2(5,100);  //list of 5 elements and all are initialized by 100
    cout <<"printing list2 ";
    for(int i:list2){
        cout << i <<" ";
    }cout << endl;
    return 0;
}
