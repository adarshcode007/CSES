#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    queue<ll>q;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    bool flag = false;

    while(!q.empty()){
        int ele = q.front();
        q.pop();
        if(flag){
            cout<<ele<<" ";
        }
        else{
            q.push(ele);
        }
        flag = !flag;
    }
}