
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int a[11];
int d[11];
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n;
    cin >> n;
    
    
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i=4; i<=11; i++){
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }

    for(int i=0; i<n; i++){
        int m;
        cin >> m;
        cout << d[m] << endl;        
    }


}