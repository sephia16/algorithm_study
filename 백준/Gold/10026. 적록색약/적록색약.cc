
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <queue>

using namespace std;
int n;
char a[101][101];

int dx[] = {0,-1,1,0};
int dy[] = {1,0,0,-1};

int visited[101][101];
vector<int> area;

void bfs(int i, int j){
    queue<pair<int,int>> q;
    visited[i][j] = area.size()+1;
    q.push(make_pair(i,j));
    int cnt = 0;
    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();

        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(1 <= nx && nx <= n && 1 <= ny && ny <= n){
                if(visited[nx][ny] == -1 && a[nx][ny] == a[x][y]){
                    int num = area.size()+1;
                    visited[nx][ny] = num;
                    q.push(make_pair(nx,ny));
                    cnt++;
                }
            }
        }
    }
    area.push_back(cnt);

}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n;
    
    for(int i=1; i<=n; i++){
        string str;
        cin >> str;
        for(int j=1; j<=n; j++){
            a[i][j] = str[j-1];
        }
    }

    memset(visited, -1, sizeof(visited));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(visited[i][j] == -1){
                bfs(i,j);
            }
        }
    }
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << visited[i][j];
    //     }
    //     cout << endl;
    // }
    int area_size = area.size();

    cout << area_size << " ";
    // int area_size = area.size();
    // for(int i=0; i<area_size; i++){
    //     cout << area[i] << endl;
    // }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(a[i][j] == 'R') a[i][j] = 'G';
        }
    }
    memset(visited,-1,sizeof(visited));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(visited[i][j] == -1){
                bfs(i,j);
            }
        }
    }
    

    cout << area.size()-area_size << endl;




}
