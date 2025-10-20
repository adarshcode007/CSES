#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>nums(n);
    unordered_map<int,int>freq;

    for(int i=0;i<n;i++){
        cin>>nums[i];
        freq[nums[i]]++;
    }

    ll result = 1;
    for(auto f : freq){
        result = (result * (f.second + 1))%MOD;
    }

    // Exclude empty subsequences
    result = (result - 1 + MOD) % MOD;
    cout<<result<<endl;
    
}