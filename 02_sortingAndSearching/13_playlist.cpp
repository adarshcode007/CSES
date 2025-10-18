#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<ll>nums(n);
    for(ll i=0;i<n;i++) cin>>nums[i];

    unordered_map<ll,ll,custom_hash>mp;
    ll maxLen = 0;
    ll i=0;
    
    for(ll j=0;j<n;j++){
        if(mp.find(nums[j]) == mp.end())
        mp.insert({nums[j],j});
        else{
            if(mp[nums[j]] >= i){
                i = mp[nums[j]] + 1;
            }
            mp[nums[j]] = j;
        }
        maxLen = max(maxLen, j-i+1);
    }
    cout<<maxLen<<endl;
}