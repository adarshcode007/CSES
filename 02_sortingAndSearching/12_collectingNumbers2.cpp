#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<int>values(n);
    for(int i=0;i<n;i++) cin>>values[i];

    values.insert(values.begin(),0);
    vector<pair<int,int>>swaps;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        swaps.push_back({a,b});
    }

    vector<int>res;
    vector<int>position(n+1);
    for(int i=1;i<=n;i++){
        position[values[i]] = i;
    }

    int count=1;
    for(int i=1;i<n;i++){
        count += (position[i] > position[i+1]);
    }

    set<pair<int,int>>updatedPairs;
    for(int i=0;i<m;i++){
        int l = swaps[i].first, r = swaps[i].second;

        if(values[l]+1<=n) updatedPairs.insert({values[l],values[l]+1});
        if(values[l]-1>=1) updatedPairs.insert({values[l]-1,values[l]});
        if(values[r]+1<=n) updatedPairs.insert({values[r],values[r]+1});
        if(values[r]-1>=1) updatedPairs.insert({values[r]-1,values[r]});

        for(auto swapped: updatedPairs)
        count -= position[swapped.first] > position[swapped.second];

        swap(values[l],values[r]);
        position[values[l]] = l;
        position[values[r]] = r;

        for(auto swapped: updatedPairs)
        count += position[swapped.first] > position[swapped.second];

        res.push_back(count);
        updatedPairs.clear();
    }

    for(auto i: res){
        cout<<i<<endl;
    }
}