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

    int x,n;
    cin>>x>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    set<pair<int,int>>ranges;
    ranges.insert({0,x});
    multiset<ll>ranges_lengths;
    ranges_lengths.insert(x);

    for(int i=0;i<n;i++){
        int pos = nums[i];
        auto it = ranges.upper_bound({pos,0});
        it--;

        int start = it->first;
        int end = it->second;
        ranges.erase(it);
        ranges_lengths.erase(ranges_lengths.find(end-start));

        ranges.insert({start,pos});
        ranges.insert({pos,end});
        ranges_lengths.insert(pos-start);
        ranges_lengths.insert(end-pos);
        cout<<*ranges_lengths.rbegin()<<" ";
    }
}