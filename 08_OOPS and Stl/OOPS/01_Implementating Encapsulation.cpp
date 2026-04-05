// Encapsulation means:
// Wrapping data (variables) and methods (functions) into a single unit (class) and restricting direct access to some of the data.

// 🔐 In Simple Words
// Encapsulation = Data Hiding + Controlled Access

// You:
// Keep variables private
// Provide access using public methods (getters/setters)

// perfect encapsulation means -> all the data members and member functions are marked as private and we can only access them using getters and setters only

# include <bits/stdc++.h>
using namespace std;

class Student{
    public:
        int id;
        string name;
        int nos;
        
    private:
        int age;
        float* CGPA;

    // Note: all the constructor must always be public
    // Note : Destructor bhi public hona chiye 
    public:
        // A constructor is called automatically when an object of a class is created.
        //(ctor) constructor : Default ctor
        Student(){
            cout << "Student Default ctor called" << endl;
        }

        // Parameterised ctor: Parameterised ctor
        Student(int id, int age, string name, int nos, float CGPA){
            cout << "Student Parameterised  ctor called" << endl;
            this->id = id;
            this->age = age;
            this->name = name;
            this->nos = nos;
            this->CGPA = new float(CGPA);
        }

        // copy ctor: copy ctor
        Student(const Student &srcobj){ // this is syntax
            cout << "Student copy ctor called" << endl;
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

        // A destructor is called automatically when an object is destroyed (goes out of scope or is deleted).
        //(dtor) destructor : Default dtor
        ~Student(){
            cout << "Student Default dtor called" << endl;
            delete this->CGPA;
        }

    private:
        void bunk(){
            cout << "Bunking" << endl;
        }

    public: // getters and setters are used to communicate in perfect encapsulated environment
        void setGpa(float a){
            // layer of authentication
            *this->CGPA = a;
        }

        float getGpa() const{
            return *this->CGPA;
        }

        void setage(int age){
            this->age = age;
        }

        int getAge(int age) {
            return this->age;
        }



};



int main(){
    Student A(1,15,"Ranu",5,9.02);
    
    // cout << A.age; // member "Student::age" (declared at line 11) is inaccessible because it is marked as private so it is hidden outside class 
    // A.bunk(); // function "Student::bunk" (declared at line 58) is inaccessible

    cout << A.getGpa() << endl;
    A.setGpa(8.73);
    cout << A.getGpa() << endl;


    return 0;
}