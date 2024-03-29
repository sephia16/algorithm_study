
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>
// #include <cstring>
// #include <queue>
// #include <tuple>
// int n,m,k;
// int a[1001][1001];
// int d[1001][1001][11];
// int dx[] = {0,0,-1,1};
// int dy[] = {1,-1,0,0};

// using namespace std;

// int main(){
// 	ios_base :: sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

//     cin >> n >> m >> k;
//     for(int i=1; i<=n; i++){
//         string str;
//         cin >> str;
//         for(int j=1; j<=m; j++){
//             a[i][j] = str[j-1]-'0';
//         }
//     }

//     d[1][1][0] = 1;
//     queue<tuple<int,int,int>> q;
//     q.push(make_tuple(1,1,0));
    
//     while(!q.empty()){
//         int x,y,z;
//         tie(x,y,z) = q.front();
//         q.pop();

//         for(int k=0; k<4; k++){
//             int nx = x+dx[k];
//             int ny = y+dy[k];
            
//             if(1 <= nx && nx <= n&& 1  <= ny && ny <= m){
//                 if(a[nx][ny] == 0 && d[nx][ny][z] == 0){
//                     d[nx][ny][z] = d[x][y][z] + 1;
//                     q.push(make_tuple(nx,ny,z));
//                 }
//                 else if(z+1 <= k && a[nx][ny] == 1 && d[nx][ny][z+1] == 0){
//                     d[nx][ny][z+1] = d[x][y][z] + 1;
//                     q.push(make_tuple(nx,ny,z+1));
//                 }
//             }
            
//         }
//     }

//     int ans = -1;
//     for(int i=0; i<=k; i++){
//         if(d[n][m][i] == 0){
//             continue;
//         }
//         if(ans == -1){
//             ans = d[n][m][i];
//         }
//         else if(ans > d[n][m][i]){
//             ans = d[n][m][i];
//         }
//     }

//     cout << ans << endl;
    

// }


#include <iostream>
#include <queue>
#include <cstdio>
#include <tuple>
#include <cstring>
using namespace std;
int a[1000][1000];
int d[1000][1000][11];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
    int n, m, l;
    scanf("%d %d %d",&n,&m, &l);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%1d",&a[i][j]);
        }
    }
    queue<tuple<int,int,int>> q;
    d[0][0][0] = 1;
    q.push(make_tuple(0,0,0));
    while (!q.empty()) {
        int x, y, z;
        tie(x,y,z) = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (a[nx][ny] == 0 && d[nx][ny][z] == 0) {
                d[nx][ny][z] = d[x][y][z] + 1;
                q.push(make_tuple(nx,ny,z));
            }
            if (z+1 <= l && a[nx][ny] == 1 && d[nx][ny][z+1] == 0) {
                d[nx][ny][z+1] = d[x][y][z] + 1;
                q.push(make_tuple(nx,ny,z+1));
            }
        }
    }
    int ans = -1;
    for (int i=0; i<=l; i++) {
        if (d[n-1][m-1][i] == 0) continue;
        if (ans == -1) {
            ans = d[n-1][m-1][i];
        } else if (ans > d[n-1][m-1][i]) {
            ans = d[n-1][m-1][i];
        }
    }
    cout << ans << '\n';
    return 0;
}


