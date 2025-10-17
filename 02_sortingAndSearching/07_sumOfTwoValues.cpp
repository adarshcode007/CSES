#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;
    
    vector<pair<int,int>>nums;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        nums.push_back({a,i+1});
    }

    sort(begin(nums),end(nums));

    int i=0,j=n-1;
    while(i<j){
        int first = nums[i].first;
        int second = nums[j].first;
        if(first+second==x){
            cout<<nums[i].second<<" "<<nums[j].second<<endl;
            return 0;
        }
        else if(first+second<x){
            i++;
        } else j--;
    }
    cout<<"IMPOSSIBLE"<<endl;
}