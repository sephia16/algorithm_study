#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int d[2000][2000];
int a[2000];

int go(int i,int j){
    if(i == j){
        return 1;
    }
    else if(i+1 == j){
        if (a[i] == a[j]){
            return 1;
        }
        else{
            return 0;
        }
    } 
    if(d[i][j] != -1){
        return d[i][j];
    }
    if (a[i] != a[j]) return d[i][j] = 0;
    else{
        return d[i][j] = go(i+1,j-1);
    }
}

int main(){
    // memset(d,-1,sizeof(d));
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    for(int i=0; i<2000; i++){
        for(int j=0; j<2000; j++){
            d[i][j] = -1;
        }
    }

    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int m;
    cin >> m;
    int s, e;
    for(int i=0; i<m; i++){
        cin >> s >> e;
        cout << go(s-1,e-1) << "\n";

    }

    // for(int i=0; i<m; i++){
    //     cout << go(b[i].first,b[i].second) << "\n";
    // }
    

}