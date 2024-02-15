
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <queue>
using namespace std;
int dist[10001];
bool check[10001];
char how[10001];
int from[10001];




int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        
        memset(dist,0,sizeof(dist));
        memset(check,false,sizeof(check));
        memset(how,0,sizeof(how));
        memset(from,0,sizeof(from));

        check[n] = true;
        from[n] = -1;

        
        queue<int> q;
        q.push(n);

        while(!q.empty()){
            int now = q.front();
            q.pop();

            int next = (now*2) % 10000;
            if(check[next] == false){
                dist[next] = dist[now] + 1;
                check[next] = true;
                how[next] = 'D';
                from[next] = now;
                q.push(next);
            }

            next = now-1;
            if(next == -1){
                next = 9999;
            }
            if(check[next] == false){
                dist[next] = dist[now] + 1;
                check[next] = true;
                how[next] = 'S';
                from[next] = now;
                q.push(next);

            }

            next = (now % 1000) * 10 + now /1000;
            if(check[next] == false){
                dist[next] = dist[now] + 1;
                check[next] = true;
                how[next] = 'L';
                from[next] = now;
                q.push(next);

            }
            next = (now%10)*1000 + (now/10);
            if(check[next] == false){
                dist[next] = dist[now] + 1;
                check[next] = true;
                how[next] = 'R';
                from[next] = now;
                q.push(next);
            }

        }

        string ans = "";
        while(m != n){
        ans += how[m];
        m = from[m];
        }

        reverse(ans.begin(),ans.end());

        cout << ans << endl;
    }

}
