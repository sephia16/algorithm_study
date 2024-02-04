
#include <iostream>

#include <vector>

#include <algorithm>

#include <climits>

using namespace std;

  

int main(){

  int n;
  cin >> n;
  vector<vector<int>> a(n,vector<int>(3));
  for(int i=0; i<n; i++){
    for(int j=0; j<3; j++){
        cin >> a[i][j];
    }
  }
  vector<vector<int>> b(n,vector<int>(3));
  for(int i=0; i<n; i++){
    if(i == 0){
        for(int j=0; j<3; j++){
        b[i][j] = a[i][j];
        }
    }
    else{
        for(int j=0; j<3; j++){
            if(j==0){
                b[i][0] = min(b[i-1][1],b[i-1][2]) + a[i][0];
            }
            else if(j==1){
                b[i][1] = min(b[i-1][0],b[i-1][2]) + a[i][1];
            }
            else{
                b[i][2] = min(b[i-1][0],b[i-1][1]) + a[i][2];
            }
        }
    }
  }
  int min = *min_element(b[n-1].begin(),b[n-1].end());
  cout << min << endl;


}