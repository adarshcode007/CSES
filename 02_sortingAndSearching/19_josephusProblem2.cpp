#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;

    vector<vector<int>>arr;
    int root = sqrt(n);
    int row = 0, col = 0, count = 0;

    vector<int>vec;
    for(int i=1;i<=n;i++){
        if(count>root){
            count = 0;
            arr.push_back(vec);
            vec.clear();
        }
        vec.push_back(i);
        count++;
    }
    if(!vec.empty()) arr.push_back(vec);

    for(int i=0;i<n;i++){
        int j = k%(n-i);

        // make jumps till we reach the positions of the element to be removed
        while(j){
            if(col+j < arr[row].size()){
                col += j;
                j = 0;
            }
            else{
                j -= arr[row].size()-col;
                col = 0;
                row++;
            }
            if(row>=arr.size()) row = 0;
        }

        // while the current row has lesser columns, move to the next row
        while(arr[row].size()<=col){
            col = 0;
            row++;
            if(row>=arr.size()) row = 0;
        }
        cout<<arr[row][col]<<" ";
        if(i!=n-1){
            arr[row].erase(arr[row].begin() + col);
            while(arr[row].size()<=col){
                col = 0;
                row++;
                if(row>=arr.size()) row = 0;
            }
        }
    }
}