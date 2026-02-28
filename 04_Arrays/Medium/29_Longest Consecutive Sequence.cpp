# include <bits/stdc++.h>
using namespace std;
int Longest_Consecutive_Sequence(vector <int>& arr){
    int n = arr.size();

    if(n == 0) return 0;

    sort(arr.begin(),arr.end());

    int maxCount = 1;
    int count = 1;

    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i-1]){
            continue; // ignore the duplicates
        }
        else if(arr[i] == arr[i-1] + 1){
            count++;
        }
        else{
            count = 1;
        }
        maxCount = max (maxCount,count);
    }
    return maxCount;
}

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();

    if(n == 0) return 0;

    int longest = 1;
    unordered_set <int> st;

    for(int i = 0; i < n; i++){
        st.insert(nums[i]);
    }

    for(auto it : st){
        if(st.find(it-1) == st.end()){  // if this is true means we does not found smaller element than it so then enter loop ager smaller element mila hai tho do nothing
            int cnt = 1;    // != end() ka matbal hota hai we found // == end() ka matlab hota hai we dont found
            int x = it;
            
            while(st.find(x+1) != st.end()){ // ager x sae greater element mila tho loop mae enter karo 
                x = x+1;
                cnt = cnt + 1;
            }
            longest = max (longest,cnt);
        }
    }
        return longest;
    }
int main(){
    string s;
    getline(cin,s);

    vector <int> arr;

    if(s.front() == '[' && s.back() == ']'){
        s = s.substr(1,s.length()-2);
    }

    string temp;
    stringstream ss(s);

    while(getline(ss,temp,',')){
        int num = stoi(temp);
        arr.push_back(num);
    }

    int ans = Longest_Consecutive_Sequence(arr);
    int ans2 = Longest_Consecutive_Sequence(arr);

    cout << ans << endl;
    cout << ans2 << endl;
    
    return 0;
}