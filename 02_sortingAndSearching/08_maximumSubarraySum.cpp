#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    long long sum=0, maxSum = LLONG_MIN;
    for(int i=0;i<n;i++){
        sum += arr[i];
        maxSum = max(maxSum,sum);

        if(sum<0) sum = 0;
    }
    cout<<maxSum<<endl;
}