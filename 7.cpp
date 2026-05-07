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
#include<climits>

#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

const vector<char>dir = {'U','D','R','L'};
const vector<int>Dx = {-1,1,0,0};
const vector<int>Dy = {0,0,1,-1};

int32_t main(){
    fast_io

    int n,m;
    cin>>n>>m;

    vector<string>grid(n);

    for(int i=0;i<n;i++){
        cin>>grid[i];
    }

    vector<vector<int>>m_t(n,vector<int>(m,LLONG_MAX));
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    vector<vector<char>>parent(n,vector<char>(m));
    vector<vector<int>>dist(n,vector<int>(m,0));

    //bfs yha se har monster pr lgega multisource bfs jise hum time dek lenge har monster ka and fir apne safe cell pr jaenge

    queue<pair<int,int>>q;

    //phle grid pr jakr jbhi monster mile use queue me daldo uske cordinate jo and uska time like jo m_t h use 0 do jaise on the very first monster 0 time me hoga

    pair<int,int>start;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(grid[i][j]=='M'){
                q.push({i,j});
                m_t[i][j]=0;
            }

            if(grid[i][j]=='A'){
                start = {i,j};
            }
        }
    }

    while(!q.empty()){

        auto [x,y]=q.front();
        q.pop();

        for(int d=0;d<4;d++){

            int nx = x+Dx[d];
            int ny = y+Dy[d];

            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!='#' && m_t[nx][ny]>m_t[x][y]+1){

                m_t[nx][ny] = m_t[x][y]+1;
                q.push({nx,ny});
            }
        }
    }

    //now ab hum safe cell ke bfs lagenge A se 

    pair<int,int>escapeCell={-1,-1};

    q.push(start);
    vis[start.first][start.second]=true;

    while(!q.empty()){

        auto [x,y]=q.front();
        q.pop();

        //agr boundary pr phuch gye toh escape hogya

        if(x==0 || x==n-1 || y==0 || y==m-1){
            escapeCell = {x,y};
            break;
        }

        for(int d=0;d<4;d++){

            int nx = x+Dx[d];
            int ny = y+Dy[d];

            //monster se phle phuchna zruri h

            if(nx>=0 && nx<n && ny>=0 && ny<m &&
               grid[nx][ny]!='#' &&
               !vis[nx][ny] &&
               dist[x][y]+1 < m_t[nx][ny]){

                vis[nx][ny] = true;

                dist[nx][ny] = dist[x][y]+1;

                parent[nx][ny] = dir[d];

                q.push({nx,ny});
            }
        }
    }

    if(escapeCell.first==-1){
        cout<<"NO"<<endl;
        return 0;
    }

    //path reconstruct krnege idr parent ele se

    string path;

    pair<int,int>curr=escapeCell;

    while(curr!=start){

        char dirr = parent[curr.first][curr.second];

        path.push_back(dirr);

        int idx = find(dir.begin(),dir.end(),dirr)-dir.begin();

        curr.first -= Dx[idx];
        curr.second -= Dy[idx];
    }

    reverse(path.begin(),path.end());

    cout<<"YES"<<endl;
    cout<<path.size()<<endl;
    cout<<path<<endl;

    return 0;
}