
#include <iostream>

#include <vector>

#include <algorithm>

#include <climits>

using namespace std;

  

int main(){
    int n;
    cin >> n;
    int streak = 0;
    vector<int> a(n+1);
    vector<int> b(n+1);
    vector<int> c(n+1);
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }


    for(int i=1; i<=n; i++){
        if(i == 1) {
            b[1] = a[1];
        }
        else if(i == 2){
            b[2] = a[1]+a[2];
        }
        else if( i ==3 ){
            b[3] = max(a[1] + a[3],a[2]+a[3]);
        }
        else{
            b[i] = max(b[i-2]+a[i],b[i-3]+a[i-1]+a[i]);
        }
    }
    cout << b[n] << endl;
    

  

}