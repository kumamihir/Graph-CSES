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
const vector<pair<int,int>>direction = {{-1,0},{0,-1},{1,0},{0,1}};
int n,m;
void dfs( vector<vector<char>>&grid,vector<vector<bool>>&vis,int i,int j){
    vis[i][j]=true;
    for(auto &dir : direction){
        int new_i = i+dir.first;
        int new_j = j+dir.second;

        if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && grid[new_i][new_j]=='.' && !vis[new_i][new_j]){
            dfs(grid,vis,new_i,new_j);
        }

    }
}


int32_t main(){
   cin>>n>>m;
   vector<vector<char>> grid(n, vector<char>(m));
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>grid[i][j];
    }
   }
   vector<vector<bool>>vis(n,vector<bool>(m,false));
   int rooms =0;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]=='.' && !vis[i][j]){
            dfs(grid,vis,i,j);
            rooms++;
        }
    }
   }
   cout<<rooms<<endl;

}