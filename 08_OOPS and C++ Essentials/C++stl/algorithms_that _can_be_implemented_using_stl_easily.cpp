#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
    vector <int> v;

    // binary search ki condition hoti thi ki sorted order mae hone chiye tho hum sorted order mae dalenge
    v.push_back(1);
    v.push_back(6);
    v.push_back(8);
    v.push_back(10);
    v.push_back(12);

    // humey ess pae binary search lagana hai
    // lets say humey fing karna hai weather 6 is present or not
    cout <<binary_search(v.begin(),v.end(),6)<<endl; //finding 6  //o/p := 1
    cout <<binary_search(v.begin(),v.end(),5)<<endl;   //o/p := 0

    // abb ager humey ye jo element present hai uss ka iterator humey return karo taki hum waha sae traverse kar paye

    // if we want to find lower bound
    cout << "lower Bound -> "<< lower_bound(v.begin(),v.end(),10)-v.begin() <<endl; //ye humey iterator return karta hai

    // if we want to find upper bound
    cout << "upper Bound -> "<< upper_bound(v.begin(),v.end(),10)-v.begin() <<endl; //ye humey iterator return karta hai

    // if we want to find min and max
    int a = 3;
    int b = 5; 
    cout << max(a,b) << endl;
    cout << min(a,b) << endl;

    // if we want to swap
    swap(a,b);
    cout <<"a "<<  a << endl; //phele 3 tha swap karne kae baad 5 ho jayega

   // if we want to reverse
   string abcd = "ABCDE";
   reverse(abcd.begin(),abcd.end());
   cout <<"string -> " << abcd << endl;

  // if we want to rotate
  rotate(v.begin(), v.begin()+1, v.end());   
  cout << "after rotate = " << endl;
  for(int i : v){
    cout << i << " ";
  }cout << endl;

//   if we want to sort 
// ye jo sort hai ye based hai intri sort pae intro sort banta hai 3 sorting algorithm kae combination sae
// 1)quick sort 2)heap sort 3)insertion sort
sort(v.begin(),v.end());
for(int i : v){
    cout << i << " ";  //after sorting
  }cout << endl;
  return 0;
}