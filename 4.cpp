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

int32_t main(){
    fast_io
    vector<vector<int>>graph;
    vector<bool>vis;
    vector<int>parent;
    int n,m;
    cin>>n>>m;
    graph.resize(n+1);
    vis.assign(n+1,false);
    parent.assign(n+1,-1);

    //idr adj list bnanai h 
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    //bfs start krna h idr se
    queue<int>q;
    q.push(1); // kynki hme bola h ki n ki value 1 hog uelovi ke lie
    vis[1]=true;
    bool found = false;
    while(!q.empty() && !found){
        int u=q.front();
        q.pop();
        for(auto &edge : graph[u]){
            if(!vis[edge]){
                vis[edge] = true;
                parent[edge] = u;
                q.push(edge);
            }
            if(edge == n) {
                found = true;
                break;
            }

        }
    }
    if(!found){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;

    }
    vector<int>path;
     int curr = n;
    while(curr!=-1){
       path.push_back(curr);
       curr = parent[curr];

    }
    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;
    for(int node : path){
        cout<<node<<" ";
    }
    cout<<endl;
    return 0;

    
    return 0;
}