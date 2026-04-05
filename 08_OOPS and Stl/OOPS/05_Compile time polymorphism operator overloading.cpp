// In c++ when operators are overloaded, they executed user defined function whenever used, allowing for customized behaviour
# include <bits/stdc++.h>
using namespace std;
class Complex {
    public:
        int real;
        int imag;

        Complex(){ // this is default constructor // this is not a valid complex number
            real = imag = -1;
        }

        Complex(int r, int i){ // parameterized ctor
            this->real = r;
            this->imag = i; 
        };

        // syntax of operator overloading
        // return Type operator <op> (args){
        //     // kam of function
        //     return<>
        // }
        Complex operator + (const Complex &B){  // + operator ko already bhot sare kam aate hai hum uss sae aur ek kam karwan chte hai hum chate hai ki vo ess tarah bhi behave kare
            // this -> A instance
            Complex temp; // ans variable 
            temp.real = this->real + B.real;
            temp.imag = this->imag + B.imag;
            return temp; // return type is complex
        }

        Complex operator - (const Complex &B){  
            Complex temp; // ans variable 
            temp.real = this->real - B.real;
            temp.imag = this->imag - B.imag;
            return temp; // return type is complex
        }

        Complex operator * (const Complex &B){  
            Complex temp; // ans variable 
            temp.real = this->real * B.real;
            temp.imag = this->imag * B.imag;
            return temp; // return type is complex
        }

        Complex operator / (const Complex &B){  
            // this -> A instance
            Complex temp; // ans variable 
            temp.real = this->real / B.real;
            temp.imag = this->imag / B.imag;
            return temp; // return type is complex
        }

        bool operator == (const Complex &B){  
            // this -> A instance
            bool temp = true; // ans variable 
            if(this->real == B.real && this->imag == B.imag){
                return true;
            }else{
                return false;
            }
            
            return temp; // return type is complex
        }

        void print(){ // this function is used to show the complex number
            printf("[%d + %di]\n", this->real, this->imag);
        }
};
int main(){
    Complex A(2, 3);
    A.print();
    Complex B(2, 5);
    B.print();

    Complex C = A + B; // A + ye ek function call kar raha hai ye argument lae kae ja raha hai B ko 
    C.print();

    Complex D = A - B;
    D.print(); 

    Complex E = A * B;
    E.print(); 

    Complex F = A / B;
    F.print(); 

    // implementing the operator overloading to check weather the two complex numbers are equal are not
    cout << (A == B ? "true" : "false");

    return 0;
}