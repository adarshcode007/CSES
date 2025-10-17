#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    set<long long>st;
    long long input;
    for(int i=0;i<n;i++){
        cin>>input;
        st.insert(input);
    }
    cout<<st.size()<<endl;
}