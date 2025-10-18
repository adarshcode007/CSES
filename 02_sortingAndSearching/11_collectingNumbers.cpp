#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[nums[i]] = i;
    }

    long long ans=1;
    for(int i=1;i<n;i++){
        if(mp[i+1]<mp[i]) ans++;
    }
    cout<<ans<<endl;

}