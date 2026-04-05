# include <bits/stdc++.h>
using namespace std;

int x = 2; // global variable

void func (){
    int x = 60;
    cout << x << endl;
    :: x = 40;
    cout << ::x << endl;
}

int main(){
    x = 20;
    int x = 4; // local to main() 
    cout << x << endl; // yaha local x print hoga
    cout << ::x << endl; // if we want to access global x we have to use :: access specifier operator 
    
    {
        int x = 50;
        cout << x << endl;

        // their is no way to access the local x of main ie local variable
        // but global variable we can access
        cout << ::x << endl; // global is accessiable anywhere
    }

    func ();
    return 0;

    
}

// jo most local hota hai uss ko jyada priority milti hai