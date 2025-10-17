#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];

    sort(begin(coins),end(coins));
    long long reachableSum=0;
    for(int i=0;i<n;i++){
        if(reachableSum+1<coins[i]){
            cout<<reachableSum+1<<endl;
            return 0;
        }
        else{
            reachableSum += coins[i];
        }
    }
    cout<<reachableSum+1<<endl;
}