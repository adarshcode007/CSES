#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<int>price(n);
    for(int i=0;i<n;i++) cin>>price[i];
    vector<int>cust(m);
    for(int i=0;i<m;i++) cin>>cust[i];

    multiset<int>st;
    for(int i=0;i<n;i++){
        st.insert(price[i]);
    }

    vector<int>ans(m);
    for(int i=0;i<m;i++){
        int temp = cust[i];

        multiset<int>::iterator itr = st.upper_bound(temp);
        if(itr==st.begin()){
            ans[i] = -1;
        } else{
            itr--;
            ans[i] = (*itr);
            st.erase(itr);
        }
    }
    
    for(int i=0;i<m;i++) cout<<ans[i]<<endl;

}