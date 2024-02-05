#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> T(n+1),P(n+1);
    vector<int> d(n+50);
    
    for(int i=0; i<n; i++){
        cin >> T[i] >> P[i];
    }

    for(int i=0; i<n; i++){
        
        d[i+T[i]] = max(d[i+T[i]],d[i]+P[i]);
        d[i+1]= max(d[i+1],d[i]);
        
    }

    cout << d[n] << endl;

}