
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>

// using namespace std;

// int main(){
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i=0; i<n; i++){
//         cin >> a[i];
//     }
//     vector<int> dp(n,-1);
//     dp[0] = 0;
//     for(int i=1; i<n; i++){
//         for(int j=0; j<i; j++){
//             if(dp[j] != -1 && i-j <= a[j]){
//                 if(dp[i] == -1 || dp[i] > dp[j] +1){
//                     dp[i] = dp[j] + 1;
//                 }
//             }
//         }
//     }
//     cout << dp[n-1] << endl;

// }


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<int> dp(n,-1);
    
    dp[0] = 0;

    for(int i=0; i<n; i++){
        if(dp[i] == -1) continue;
        for(int j=i+1; j<=i+a[i]; j++){
            if(j >= n) break;
            if(dp[j] == -1 || dp[j] > dp[i] +1){
                dp[j] = dp[i] +1;
            } 
        }
    }
    cout << dp[n-1] << endl;

}


