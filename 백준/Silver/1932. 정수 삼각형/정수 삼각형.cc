
#include <iostream>

#include <vector>

#include <algorithm>

#include <climits>

using namespace std;
int n;
int sum = 0;

  

int main(){

    cin >> n;
    vector<vector<int>> a(n+1, vector<int>(n+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++)
            cin >> a[i][j];
    }
    vector<vector<int>> b(n+1, vector<int>(n+1));
    b[1][1] = a[1][1];

    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){

            if(j==1){
                b[i][j] = b[i-1][j] + a[i][j];
            }
            else if(j == i){
                b[i][j] = b[i-1][j-1] + a[i][j];
            }
            else{
            b[i][j] = max(b[i-1][j],b[i-1][j-1]) + a[i][j];
            }
        }
    }
    // for(int i=1; i<=n; i++){
    //     cout << b[n+1][i] << endl;
    // }
    int max = *max_element(b[n].begin(),b[n].end());
    cout << max << endl;



    
}
        

  
