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
    
    vector<int>color;
    int n,m;

    bool bfs(int st){
        queue<int>q;
        q.push(st);
        color[st]=1;
         while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int &edge : graph[u]){
                    if(color[edge]==-1){
                        color[edge] = 3 - color[u];//switch krna h 1 and 2 me
                        q.push(edge);
                    }else if(color[edge]==color[u]){
                        return false;
                    }
                }
                
            }
            return true;
    }


int32_t main(){
    fast_io
    cin>>n>>m;
    graph.resize(n+1);
    
    color.assign(n+1,-1);
    


    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        if(color[i]==-1){
           if(!bfs(i)){
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
           }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<color[i]<<" ";
    }
    cout<<endl;
  
    
    
    return 0;
}