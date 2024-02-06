
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int n,s,m;
int a[51];
int d[101][1001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    memset(d,0,sizeof(d));

    cin >> n >> s >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    d[0][s] = 1;
    for(int i=0; i<=n-1; i++){
        for(int j=0; j<=m; j++){
            if(d[i][j] == 0) {
                continue;
            }
            if(j-a[i+1] >= 0 ){
                d[i+1][j-a[i+1]] = 1;
            }
            if(j+a[i+1] <= m){
                d[i+1][j+a[i+1]] = 1;
            }
        }
    }
    int ans = -1;
    for(int i=0; i<=m; i++){
        if(d[n][i] == 1) {
            ans = i;
        }
    }
    cout << ans << endl;

}