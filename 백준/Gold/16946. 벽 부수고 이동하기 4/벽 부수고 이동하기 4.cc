// #include <iostream>
// #include <vector>
// #include <string>
// #include <queue>
// #include <set>
// #include <tuple>
// using namespace std;

// int n,m;
// int a[1001][1001];
// int group[1001][1001];
// string str;

// int dx[] = {0,0,-1,1};
// int dy[] = {1,-1,0,0};


// bool visited[1001][1001];
// vector<int> group_size;

// void bfs(int sx, int sy){
//     queue<pair<int,int>> q;
//     int g = group_size.size();
//     q.push(make_pair(sx,sy));
//     visited[sx][sy] = true;
//     group[sx][sy] =  g;
//     int cnt = 1;
//     while(!q.empty()){
//         int x,y;
//         tie(x,y) = q.front();
//         q.pop();
//         for(int k=0; k<4; k++){
//             int nx = x+dx[k];
//             int ny = y+dy[k];
//             if(1<= nx && nx <=n && 1<= ny && ny <=m){
//                 if(visited[nx][ny] == false && a[nx][ny] == 0){
//                     q.push(make_pair(nx,ny));
//                     visited[nx][ny] = true;
//                     group[nx][ny] = g;
//                     cnt += 1;
//                 }
//             }
//         }

//     }
//     group_size.push_back(cnt);
// }

// int main(){
//     cin >> n >> m;
//     for(int i=1; i<=n; i++){
//             cin >> str;
//         for(int j=1; j<=m; j++){
//             a[i][j] = str[j] - '0';
//         }
//     }
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=m; j++){
//             if(a[i][j] == 0 && visited[i][j] == false){
//                 bfs(i,j);
//             }
//         }
//     }
    
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=m; j++){
//             if(a[i][j] == 0){
//                 cout << 0;
//             }
//             else{
//                 set<int> near;
//                 for(int k=0; k<4; k++){
//                     int nx = i+dx[k];
//                     int ny = j+dy[k];
//                     if(1<= nx && nx <= n && 1<= ny && ny <= m){
//                         near.insert(group[nx][ny]);
//                     }
//                 }
//                 int ans = 1;
//                 for(int g : near){
//                 ans += group_size[g];
//             }
//             cout << ans%10;
//             }
//         }
//         cout << endl;
//     }





// }

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <tuple>
using namespace std;
int n, m;
int a[1000][1000];
bool check[1000][1000];
int group[1000][1000];
vector<int> group_size;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void bfs(int sx, int sy) {
    int g = group_size.size();
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    check[sx][sy] = true;
    group[sx][sy] = g;
    int cnt = 1;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (a[nx][ny] == 0 && check[nx][ny] == false) {
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = true;
                    group[nx][ny] = g;
                    cnt += 1;
                }
            }
        }
    }
    group_size.push_back(cnt);
}
int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<m; j++) {
            a[i][j] = s[j] - '0';
            check[i][j] = false;
            group[i][j] = -1;
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 0 && check[i][j] == false) {
                bfs(i, j);
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 0) {
                cout << 0;
            } else {
                set<int> near;
                for (int k=0; k<4; k++) {
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if (0 <= x && x < n && 0 <= y && y < m) {
                        if (a[x][y] == 0) {
                            near.insert(group[x][y]);
                        }
                    }
                }
                int ans = 1;
                for (int g : near) {
                    ans += group_size[g];
                }
                cout << ans%10;
            }
        }
        cout << '\n';
    }
    return 0;
}