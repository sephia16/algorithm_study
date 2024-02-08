// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <climits>
// #include <cstring>

// using namespace std;

// int d[101];
// int a[101];
// int n;

// int main(){
// 	ios_base :: sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

//     cin >> n;
//     d[1] = 1;
//     d[2] = 2;
//     d[3] = 3;
//     a[1] = 1;
//     a[2] = 1;
//     a[3] = 1;
    
//     for(int i=4; i<=100; i++){
//         if(d[i-3]*2 >= d[i-1]+a[i-1]){
//             d[i] = d[i-3]*2;
//             a[i] = d[i-3];
//         }
//         else{
//             d[i] = d[i-1]+a[i-1];
//             a[i] = a[i-1];
//         }
//     }

//     cout << d[n] << endl;

// }

// #include <iostream>
// // #include <vector>
// // #include <algorithm>
// // #include <climits>
// // #include <cstring>

// using namespace std;

// int d[1001];


// int main(){
// 	// ios_base :: sync_with_stdio(false);
// 	// cin.tie(NULL);
// 	// cout.tie(NULL);
//     int n;
//     cin >> n;
//     for(int i=1; i<=n; i++){
//         d[i] = d[i-1]+1;
//         for(int j=1; j<=i-3; j++){
//             long long cur = d[i-j-2]*(j+1);
//             if(d[i] < cur){
//                 d[i] = cur;
//             }
//         }
//     }
    

//     cout << d[n] << endl;
//     return 0;

// }

#include <iostream>
using namespace std;
long long d[1001];
int main() {
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        d[i] = d[i-1] + 1;
        for (int j=1; j<=i-3; j++) {
            long long cur = d[i-j-2]*(j+1);
            if (cur > d[i]) {
                d[i] = cur;
            }
        }
    }
    cout << d[n] << '\n';
    return 0;
}
