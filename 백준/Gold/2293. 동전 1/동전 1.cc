
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;
int n,k;

int d[10001];
int a[101];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    
    d[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=1; j<=k; j++){
            if(j-a[i]>= 0){
                d[j] += d[j-a[i]];
            }
        }
    }

    cout << d[k] << endl;

}

