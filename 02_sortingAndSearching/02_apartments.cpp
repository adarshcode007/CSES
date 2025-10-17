#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m,k;
    cin>>n>>m>>k;

    vector<int>demand(n);
    for(int i=0;i<n;i++) cin>>demand[i];
    vector<int>aval(m);
    for(int i=0;i<m;i++) cin>>aval[i];

    sort(begin(demand),end(demand));
    sort(begin(aval),end(aval));

    int i=0,j=0;
    int ans = 0;
    while(i<n && j<m){
        if(aval[j]>=demand[i]-k && aval[j]<=demand[i]+k){
            ans++;
            i++; j++;
        }
        else if(aval[j]<demand[i]-k){
            j++;
        }else i++;
    }

    cout<<ans<<endl;
}