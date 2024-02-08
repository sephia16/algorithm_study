
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;
int a[501][3];
long long d[501][501];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=2; j++){
            cin >> a[i][j];
        }
    }


    for (int i = n; i >= 1; i--) { 
        for (int j = i + 1; j <= n; j++) { 
            d[i][j] = LLONG_MAX;
            for (int k = i; k < j; k++) {
                long long cost = d[i][k] + d[k + 1][j] + a[i][1] * a[k][2] * a[j][2];
                if(cost < d[i][j]){
                    d[i][j] = cost;
                }
            }
        }
    }
    cout << d[1][n] << endl;
 }
    


