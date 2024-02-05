
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>

// using namespace std;

// int main(){
//     int N,M;
//     cin >> N >> M;

//     int a[1001][1001];
//     int dp[1001][1001];

//     for(int i=1; i<=N; i++){
//         for(int j=1; j<=M; j++){
//             cin >> a[i][j];
//         }
//     }

//     for(int i=1; i<=N; i++){
//         for(int j=1; j<=M; j++){
//             dp[i][j] = max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) + a[i][j];
//         }
//     }

//     cout << dp[N][M] << endl;


// }


// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>

// using namespace std;

// int main(){
//     int N,M;
//     cin >> N >> M;

//     int a[1002][1002];
//     int dp[1002][1002];

//     for(int i=1; i<=N; i++){
//         for(int j=1; j<=M; j++){
//             cin >> a[i][j];
//         }
//     }
//     dp[1][1] = a[1][1];
//     for(int i=1; i<=N; i++){
//         for(int j=1; j<=M; j++){
//             if(dp[i+1][j] < dp[i][j] + a[i+1][j]){
//                 dp[i+1][j] = dp[i][j] + a[i+1][j];
//             } 
//             if(dp[i][j+1] < dp[i][j] + a[i][j+1]){
//                 dp[i][j+1] = dp[i][j] + a[i][j+1];
//             } 
//             if(dp[i+1][j+1] < dp[i][j] + a[i+1][j+1]){
//                 dp[i+1][j+1] = dp[i][j] + a[i+1][j+1];
//             } 
//         }
//     }

//     cout << dp[N][M] << endl;


// }


// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>

// using namespace std;

// int go(array<array<int,1001>,1001> &arr,int (&a)[1002][1002], int i, int j){
//     if( i < 1 || j < 1){
//         return 0;
//     }
//     if(arr[i][j] >= 0 ){
//         return arr[i][j];
//     }

//     arr[i][j] = max(go(arr,a,i-1,j),go(arr,a,i,j-1)) + a[i][j];
//     return arr[i][j];
// }

// int main(){
//     int N,M;
//     cin >> N >> M;

//     int a[1002][1002];
    

//     array <array<int,1001>,1001> arr{};
//     for(auto &it : arr){
//         it.fill(-1);
//     }




//     for(int i=1; i<=N; i++){
//         for(int j=1; j<=M; j++){
//             cin >> a[i][j];
//         }
//     }

//     cout << go(arr,a,N,M) << endl;

// }


#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int N,M;

int go(array<array<int,1001>,1001> &arr,int (&a)[1002][1002], int i, int j){
    if( i > N || j > M){
        return 0;
    }
    if(arr[i][j] >= 0 ){
        return arr[i][j];
    }

    arr[i][j] = max(go(arr,a,i+1,j),go(arr,a,i,j+1)) + a[i][j];
    return arr[i][j];
}

int main(){
    
    cin >> N >> M;

    int a[1002][1002];
    

    array <array<int,1001>,1001> arr;
    for(auto &it : arr){
        it.fill(-1);
    }




    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> a[i][j];
        }
    }

    cout << go(arr,a,1,1) << endl;

}
