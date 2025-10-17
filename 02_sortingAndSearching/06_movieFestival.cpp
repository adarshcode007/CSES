#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    
    vector<pair<int,int>>movies(n);
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        movies[i] = {a,b};
    }

    sort(begin(movies),end(movies),[](const pair<int,int>&p1, const pair<int,int>&p2){
        return p1.second < p2.second;
    });

    int timeElapsed=0, moviesWatched=0;
    for(int i=0;i<n;i++){
        if(movies[i].first>=timeElapsed){
            moviesWatched++;
            timeElapsed = movies[i].second;
        }
    }
    cout<<moviesWatched<<endl;

}