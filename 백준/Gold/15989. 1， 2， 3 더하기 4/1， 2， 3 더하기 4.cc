
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int a[10001];
int d[10001];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    d[1] = 1;
    d[2] = 2;
    d[3] = 3;
    d[4] = 4;
    d[5] = 5;

    a[0] = 1;
    a[1] = 0;
    a[2] = 1;
    a[3] = 1;
    a[4] = 1;
    a[5] = 1;

    for(int i=6; i<=10000; i++){
        a[i] = a[i-6]+1;
        d[i] = d[i-1] + a[i];
    }

    int n;
    cin >>n;
    for(int i=0; i<n; i++){
        int m;
        cin >> m;
        cout << d[m] << endl;
    }
    
}