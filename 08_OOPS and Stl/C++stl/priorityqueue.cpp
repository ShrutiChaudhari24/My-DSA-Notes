# include <iostream>
#include <queue>
using namespace std;

int main(){
    // max heap banane ka tarika
    priority_queue <int> maximum; //jab hum easae initialize karte hai tho ye jo hamera banta hai ye based hota hai max heap pae
    // matlab ab jab bhi hum element fetch karenge nikalenge tho vo element greatest hoga jo elements ess kae ander pade hai un mae sae

    // min heap banae ka tarika
    priority_queue <int, vector <int>, greater<int>> minimum;

    maximum.push(10);
    maximum.push(11);
    maximum.push(12);
    maximum.push(13);

    cout <<"size ->" <<maximum.size()<<endl;

    int n = maximum.size();
    for(int i = 0; i<n; i++){
        cout << maximum.top()<<" ";
        maximum.pop();
    }cout << endl;

    minimum.push(10);
    minimum.push(11);
    minimum.push(12);
    minimum.push(13);

    int m = minimum.size();
    for(int i=0; i<m; i++ ){
        cout << minimum.top() << " ";
        minimum.pop();
    }cout << endl;

    cout << "Khali hai kya bhai ?? --> " << minimum.empty() << endl; //o/p:=1 means it is empty 
    return 0;
}
