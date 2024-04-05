//
// Created by LL06p on 2024/4/4.
//
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000+5;
vector<int> G[maxn];
int n,k;
int leaf = 0;
void dfs(int u,int fa){
    bool flag = true;
    for(auto v : G[u]){
        if(v==fa) continue;
        dfs(v,u);
        flag = false;
    }
    if(flag) leaf++;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(0,-1);
    int ans = 0;
//    cout<<leaf<<endl;
    if(leaf==1){
        //All
        ans = k;
    }
    else{
        if(k%leaf==0){
            ans = 2 * (k/leaf);
        }
        else{
            ans = 2 * (k / leaf);
            int res = k % leaf;
            int t = min(2,res);
            ans += t;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
