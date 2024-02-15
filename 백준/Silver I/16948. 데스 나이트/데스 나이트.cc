
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <queue>

int dx[] = {-2,-2,0,0,2,2};
int dy[] = {1,-1,2,-2,1,-1};

int d[200][200];

int n;
int sx,sy,ex,ey;
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n;
    
    cin >> sx >> sy >> ex >> ey;
    memset(d,-1,sizeof(d));
    d[sx][sy] = 0;
    queue<pair<int,int>> q;

    q.push(make_pair(sx,sy));

    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();

        for(int i=0; i<6; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && nx < n && ny >= 0 && ny < n){
            if(d[nx][ny] == -1){
                d[nx][ny] = d[x][y] +1;
                q.push(make_pair(nx,ny));
            }
        }
    }

}
    cout << d[ex][ey] << endl;

}