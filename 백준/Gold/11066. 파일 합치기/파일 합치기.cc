
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int a[501];
int d[501][501];
int t,k;

int go(int i,int j){
    if(i==j){
        return 0;
    }
    if(d[i][j] != -1){
        return d[i][j];
    }
    int ans = d[i][j];
    int sum = 0;

    for(int k=i; k<=j; k++){
        sum += a[k];
    }
    for(int k=i; k<j; k++){
        int temp = go(i,k) + go(k+1,j) + sum;
        if(ans == -1 || temp < ans){
            d[i][j] = temp;
            ans = temp;
        }
    }
    return ans;
}


int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    // 
    

    cin >> t;
    while(t--){
        memset(d,-1,sizeof(d));
        int n;
        cin >> n;
        for(int i = 1; i<=n; i++){
            cin >> a[i];
        }
        cout << go(1,n) << endl;
    }


}
