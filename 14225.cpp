#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int a[20];
bool c[20*100000];
int n;

void solve(int i, int sum){
    if(i == n){
        c[sum] = true;
        return;
    }
    solve(i+1, sum);
    solve(i+1, sum+a[i]);
}


int main(){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    solve(0,0);
    for(int i=1;; i++){
        if(c[i] == false){
            cout << i << endl;
            break;
        }
    }


}