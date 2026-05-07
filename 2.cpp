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

// directions fixed (U, L, D, R)
const vector<pair<int,int>>direction = {{-1,0},{0,-1},{1,0},{0,1}};
const vector<char>directions = {'U','L','D','R'};

vector<char>path;

bool bfs( vector<vector<char>>&grid,vector<vector<bool>>&vis,int i,int j){
    // empty (unused)
    return false;
}

int32_t main(){
    fast_io;

    //input idr lena h m and n ka 
    int n,m;
    cin>>n>>m;

    vector<string>grid(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }

    //ye 2 vec h jo visited track krnege and second vala prevdir ko stor krega and use ans construction ke lie later use krnege !
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    vector<vector<char>>prevdir(n,vector<char>(m,0));

    //ab 'A' and 'B' ko locate krna h grid pr coz hum vhi r,c se apna bfs strt krnege;
    pair<int,int>start,target;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='A'){
                start = {i,j};
            }else if(grid[i][j]=='B'){
                target = {i,j};
            }
        }
    }

    //now ab a and b mil gye and hume strt and end pos mil gyi h so now ab bfs start krnege from a
    queue<pair<int,int>>pq;
    vis[start.first][start.second] = true;
    pq.push(start);

    bool found = false;

    while(!pq.empty()){
        auto temp = pq.front();
        int i = temp.first;
        int j = temp.second;
        pq.pop();

        for(int k=0;k<4;k++){
            int new_i = i+direction[k].first;
            int new_j = j+direction[k].second;

            if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && grid[new_i][new_j]!='#' && !vis[new_i][new_j]){
                vis[new_i][new_j] = true;
                prevdir[new_i][new_j] = directions[k];
                pq.push({new_i,new_j});

                if(make_pair(new_i,new_j)==target){
                    found = true;
                    break;
                }
            }
        }
        if(found) break;
    }

    if(!vis[target.first][target.second]){
        cout<<"NO"<<endl;
        return 0;
    }

    //ab yha ans ya path ko contruct krna h ki chota rasta konsa h ;
    string path;
    pair<int,int>curr = target;

    while(curr!=start){
        char dir = prevdir[curr.first][curr.second];
        path.push_back(dir);

        int idx = find(directions.begin(),directions.end(),dir)-directions.begin();

        curr.first -= direction[idx].first;
        curr.second -= direction[idx].second;
    }

    reverse(path.begin(),path.end());

    cout<<"YES"<<endl;
    cout<<path.size()<<endl;
    cout<<path<<endl;
}
