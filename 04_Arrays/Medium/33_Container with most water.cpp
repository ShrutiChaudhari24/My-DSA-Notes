# include <bits/stdc++.h>
using namespace std;
int maxArea(vector<int>& height){ // TC := O(N square) brute force approch
    int n = height.size();
    int maxArea = 0;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){

            int width = j - i;
            int height_ = min(height[i],height[j]);
            int area =  width * height_ ;

            maxArea =  max(maxArea, area);
        }
    }
    return maxArea;
}

int maxArea2(vector<int>& height){ // TC := O(N) optimal approch
   int n = height.size();
   int left = 0;
   int right = n-1;
   
   int maxWater = 0;
   int currWater = 0;

   while(left < right){
        int w = right - left;

        int ht = min(height[left],height[right]);

        currWater = w * ht;

        maxWater = max(maxWater, currWater);

        if(height[left] < height[right]){
            left++;
        }else{
            right--;
        }
   }
   return maxWater;
}
int main(){
    string s;
    getline(cin,s);

    if(s.front() == '[' &&  s.back() == ']'){
        s = s.substr(1, s.length()-2);
    }

    vector <int> height;

    string temp;
    stringstream ss(s);

    while(getline(ss,temp,',')){
        int num = stoi(temp);
        height.push_back(num);
    }

    // int maxWaterStored = maxArea(height);
    int maxWater = maxArea2(height);

    // cout << maxWaterStored << endl;
    cout << maxWater << endl;
    return 0;
}