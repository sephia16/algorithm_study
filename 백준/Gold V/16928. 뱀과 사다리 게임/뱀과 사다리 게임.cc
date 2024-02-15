
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <queue>
using namespace std;
int d[101];
int a[101];
int n, m;


int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n >> m;

    for(int i=1; i<=100; i++){
        d[i] = -1;
        a[i] = i;
    }

    while(n--){
        int x, y;
        cin >> x >> y;
        a[x] = y;
    }

    while(m--){
        int x, y;

        cin >> x >> y;
        a[x] = y;
    }

    queue<int> q;
    d[1] = 0;
    q.push(1);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=1; i<=6; i++){
            int y = x+i;
            if(y>100){
                continue;
            }
            y = a[y];
            if(d[y] == -1){
                d[y] = d[x]+1;
                q.push(y);
            }
        }
    }

    cout << d[100] << endl;
}
