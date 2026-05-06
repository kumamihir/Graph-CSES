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
vector<vector<int>>graph;
    vector<int>parent;
    vector<bool>vis;
    int cyclestart = -1,cycle_end;

bool dfs(int node,int par){
    vis[node]=true;
    for(int nbr : graph[node]){
        if(nbr == par) continue;
        if(vis[nbr]){
            cyclestart=nbr;
            cycle_end =node;
            return true;
        }else{
            parent[nbr] = node;
            if(dfs(nbr,node)) return true;

        }
    }
    return false;

}

int32_t main(){
    fast_io
    int n,m;
    cin>>n>>m;
    vis.assign(n+1,false);
    parent.assign(n+1,-1);
    graph.resize(n+1);
    

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i] && dfs(i,-1)){
            break;
        }
    }

    if(cyclestart==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        vector<int>cycle;
        cycle.push_back(cyclestart);
        int curr = cycle_end;
        while (curr!=cyclestart)
        {
            cycle.push_back(curr);
            curr = parent[curr];
        }
        cycle.push_back(cyclestart);
        reverse(cycle.begin(),cycle.end());
        cout<<cycle.size()<<endl;
        for(int node : cycle){
            cout<<node<<" ";
        }
        cout<<endl;
        
    }



    
    return 0;
}