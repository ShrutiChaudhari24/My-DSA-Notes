# include <bits/stdc++.h>
using namespace std;

class Student{
    public:
    // Attribute / Properties
    int id;
    int age;
    string name;
    int nos; // number Of Subjects
    int* CGPA;

    // A constructor is called automatically when an object of a class is created.
    //(ctor) constructor : Default ctor
    Student(){
        cout << "Student Default ctor called" << endl;
    }

    // Parameterised ctor: Parameterised ctor
    Student(int id, int age, string name, int nos, float CGPA){
        cout << "Student Parameterised ctor called" << endl;
        this->id = id;
        this->age = age;
        this->name = name;
        this->nos = nos;
        this->CGPA = new int(CGPA);
    }

     // copy ctor: copy ctor
    Student(const Student &srcobj){ // this is syntax  
        cout << "Student copy ctor called" << endl; // const esliye likha hai taki hum change na kar paye 
        this->id = srcobj.id;
        this->age = srcobj.age;
        this->name = srcobj.name;
        this->nos = srcobj.nos;
    }

    // Behaviour / Methods / Functions
    void study(){
        cout << this->name << " Studying " << endl;
    }

    void sleep(){
        cout << "Sleeping" << endl;
    }

    void bunk(){
        cout << "Bunking" << endl;
    }

    // A destructor is called automatically when an object is destroyed (goes out of scope or is deleted).
    //(dtor) destructor : Default dtor
    ~Student(){
        cout << "Student Default dtor called" << endl;
        delete this->CGPA;
    }

};

int main(){

/*  Student A;
    A.id = 1;
    A.age = 15;
    A.name = "Ranu";
    A.nos = 6;
    A.study();

    Student B;
    B.id = 2;
    B.age = 15;
    B.name = "Rahul";
    B.nos = 7;
    B.bunk();
*/

    Student A(1, 15, "Ranu", 6, 9.0); // Parameterised ctor called
    Student B(2, 13, "Rahul", 6, 8.9);
   
    cout << A.name << " " << A.age << endl;

    A.bunk();
    B.sleep();

    // Copy Constructor
    Student C = A; 
    // or call like this 
    // Student C(A);
    cout << C.name << " " << A.name << endl;

    // Dynamic allocation, or Student pointer;
    Student *E = new Student(1, 17, "Shruti", 8, 9.8);
    cout << E->name << endl;
    cout << E->age << endl;
    E->study();
    delete E; // ye karne pae hi E object ka dtor call hoga nahi tho nahi hoga as memory is allocated dynamically we have to free it by our own

    return 0;
}