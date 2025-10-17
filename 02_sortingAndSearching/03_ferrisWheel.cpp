#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin>>n>>x;

    vector<int>weights(n);
    for(int i=0;i<n;i++) cin>>weights[i];

    sort(begin(weights),end(weights));
    int i=0,j=weights.size()-1;
    int ans = 0;
    while(i<j){
        if(weights[i]+weights[j]<=x){
            ans++;
            i++;j--;
        }
        else if(weights[i]+weights[j]>x){
            ans++;
            j--;
        }
    }
    if(i==j) ans++;
    cout<<ans<<endl;
}