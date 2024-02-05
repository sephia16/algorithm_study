
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    int N,M;
    cin >> N >> M;

    int a[1001][1001];
    int dp[1001][1001];

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> a[i][j];
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            dp[i][j] = max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) + a[i][j];
        }
    }

    cout << dp[N][M] << endl;


}