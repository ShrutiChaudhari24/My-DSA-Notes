// syntax of derived class
// class DerivedClass : accessSpecifier BaseClass{
//     // Class members
// };

# include <bits/stdc++.h>
using namespace std;

class Vehicle{
    private:
    string name;

    public:
    string model;
    int noOfTyres;

    // as name is a private data member we cannot inherit it in public mode so we have to use getter/setter
    string getName(){
        return this->name;
    }

    Vehicle(string _name, string _model, int _noOfTyres){
        cout << "I am inside Vehicle ctor" << endl;
        this->name = _name;
        this->model = _model;
        this->noOfTyres = _noOfTyres; 
    }

    // protected:  // protected karne pae derived class kae liye tho ye chije accessiable rahengi per main mae hum unhe access nahi kar sakte
    void start_engine(){
        cout << "Engine is starting " << getName() << " " << model << endl;
    }

    void stop_engine(){
        cout << "Engine is stopping " << getName() << " " << model << endl;
    }

    ~Vehicle(){
        cout << "I am inside Vehicle dtor" << endl;
    }
};

class Car: public Vehicle{
    public: 
    int noOfDoors;
    string transmissionType;

    Car (string _name, string _model, int _noOfTyres, int _noOfDoores,string _transmissionType) : Vehicle(_name, _model, _noOfTyres)
    {   
        cout << "I am inside Car ctor" << endl;
        this->noOfDoors = _noOfDoores;
        this->transmissionType  = _transmissionType;
    }

    void startAC(){
        cout << "AC has started of " << getName() << endl;
    }

    ~Car(){
        cout << "I am inside Car dtor" << endl;
    }
};

class MotorCycle: public Vehicle{
    protected:
        string handleBarStyle;
        string suspensionType;
    public:
        MotorCycle(string _name, string _model, int _noOfTyres,string _handleBarStyle, string _suspensionType):Vehicle(_name, _model, _noOfTyres)
        {   cout << "Motorcycle ctor called" << endl;
            this->handleBarStyle =  _handleBarStyle;
            this->suspensionType = _suspensionType;
        }

        void wheelie(){
            cout << "wheelie kar rahi hai " << getName() << endl;
        }

        ~MotorCycle(){
        cout << "I am inside Car dtor" << endl;
    }
};


int main(){

    Car A("Maruti 800", "LXI", 4, 4, "Mauual");
   // A.start_engine(); // function "Vehicle::start_engine" (declared at line 30) is inaccessible ||  protected chije inherit tho hoti hai per vo main mae access nahi ki ja sakti
    A.startAC();
   // A.stop_engine(); // function "Vehicle::start_engine" (declared at line 30) is inaccessible
    
   MotorCycle M ("BMW", "VXI", 2, "U", "Hard");
   M.start_engine();
    return 0;
}