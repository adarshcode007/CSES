#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(begin(arr),end(arr));
    int median = arr[n/2];
    long long ans = 0;
    for(int i=0;i<n;i++){
        ans += abs(median-arr[i]);
    }
    cout<<ans<<endl;
}