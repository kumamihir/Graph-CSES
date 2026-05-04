#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<stack>
#include<queue>
#include<array>
#include<math.h>
#include<map>
#include<unordered_map>
#include<unordered_set>
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int n,m;
vector<vector<int>>graph;
    vector<bool>vis;
void dfs(int n){
    vis[n] = true;
    for(auto &edge : graph[n]){
        if(!vis[edge]){
            dfs(edge);
        }
    }
}

int32_t main(){
    fast_io
    cin>>n>>m;
    graph.resize(n+1);
    vis.assign(n+1,false);
    
    for(int i=0;i<m;i++){
        int u ,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int>rep;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            rep.push_back(i);
            dfs(i);
        }
    }
    int nr = rep.size()-1;
    cout<<nr<<endl;
    for(int i=1;i<rep.size();i++){
        cout<<rep[0]<<" "<<rep[i]<<endl;
    }

    
    
}