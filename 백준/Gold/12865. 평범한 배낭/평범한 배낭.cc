
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int n,k;
int b[101];
int d[101][100001];
int w[101];
int v[101];




int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    memset(d,0,sizeof(d));

    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> w[i] >> v[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            d[i][j] = d[i-1][j];
            if(j-w[i]>=0){
            d[i][j] = max(d[i][j],d[i-1][j-w[i]]+v[i]);
            }
        }
    }
    cout << d[n][k] << endl;
    
    


}