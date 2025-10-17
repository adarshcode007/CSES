#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<pair<int,int>>times;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        times.push_back({a,b});
    }

    vector<pair<int,char>>t;
    for(auto it: times){
        t.push_back({it.first,'a'});
        t.push_back({it.second,'d'});
    }

    sort(begin(t),end(t));

    // for(auto it: t){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }

    int ans=0;
    int cur=0;
    for(auto it: t){
        if(it.second=='a') cur++;
        else cur--;
        ans = max(ans,cur);
    }
    cout<<ans<<endl;

}