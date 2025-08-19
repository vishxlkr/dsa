#include<bits/stdc++.h>

using namespace std;
#define pp pair<int,int>
#define ll long long int

int n , m;
vector<vector<char>> grid;      // input grid
vector<vector<int>> visited;    // to mark visited
vector<vector<pp>> parent;      // to mark parent of any cell in order to get the path at the end
vector<vector<char>> move_dir;
bool found = false;

bool isValid(int x , int y){
    if(x<0 or y<0 or x>=n or y>=m or grid[x][y]=='#' or visited[x][y]==1) return false;
    return true;
}

int dx[] = {1,-1,0,0};      // D , U R L
int dy[] = {0,0,1,-1};
char dir[] = {'D','U','R','L'};


void bfs(pp start, pp end ){
    visited.resize(n,vector<int>(m,0)); //0 means not visited , 1 means visited
    parent.resize(n,vector<pp>(m,{-1,-1}));        // parent
    move_dir.resize(n,vector<char>(m,0));      // store direction

    queue<pp> qu;
    qu.push(start);

    visited[start.first][start.second] = 1; // mark source visited




    while(not qu.empty()){
        pp curr = qu.front(); qu.pop();
        int x = curr.first;
        int y = curr.second;

        if(make_pair(x,y)==end){
            found = true;
            break;
        }

        for(int t =  0 ; t<4;t++){
            int nx = x+dx[t];            // next x
            int ny = y+dy[t];           // next y
            if(isValid(nx,ny)){
                qu.push({nx,ny});
                visited[nx][ny]=1;      // mark visited when pushing into queue
                parent[nx][ny] = make_pair(x, y);
                move_dir[nx][ny]= dir[t];
            }
        }

    }


}


int main(){

    cin>>n>>m;

    grid.clear();
    grid.resize(n,vector<char>(m));

     pp start ;
     pp end ;

    //taking input
    for(int i =0 ; i < n; i++){
        for(int j = 0;  j <m;j++){
            char temp;
            cin>>temp;
            if(temp=='A') start = {i,j};
            if(temp=='B') end = {i,j};
            grid[i][j]=temp;
        }
    }




    bfs( start ,  end);

    if(not found) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;

        vector<char> path ;         //to print path
        pp current = end;      // starting from end to going to start
        while(current != start){
            path.push_back(move_dir[current.first][current.second]);    // push the path stored in movedir
            current = parent[current.first][current.second];            // current  = parent of current
        }

        reverse(path.begin(),path.end());       // path is stored in reverse direction -> so reverse it again

        cout<<path.size()<<endl;
        for(int i =0 ; i <path.size();i++){
            cout<<path[i];
        }



    }

    

    return 0;
}