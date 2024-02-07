
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;


int d[61][61][61];

int go(int i,int j, int k){
    if(i<0){
        return go(0,j,k);
    }
    if(j<0){
        return go(i,0,k);
    }
    if(k<0){
        return go(i,j,0);
    }
    if(i==0 && j==0 && k==0){
        return 0;
    }
    if(d[i][j][k] != -1){
        return d[i][j][k];
    }
    int ans = INT_MAX;
    vector<int> temp = {9,3,1};
    do{
        if(ans > go(i-temp[0],j-temp[1],k-temp[2]) )
        ans= go(i-temp[0],j-temp[1],k-temp[2]);
        
    }while(prev_permutation(temp.begin(),temp.end()));
    ans += 1;
    return d[i][j][k] = ans;
    







}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


    memset(d,-1,sizeof(d));

    int n;
    cin >> n;
    int scv[3] = {0,0,0};
    for(int i=0; i<n; i++){
        cin >> scv[i];
    }
    cout << go(scv[0],scv[1],scv[2]) << endl;
}