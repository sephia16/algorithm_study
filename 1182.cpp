// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int n,m;
// int cnt = 0;
// int a[20];
// void solve(int index, int sum){
//     if(index == n){
//         if(sum == m){
//             cnt++;
//         }
//         return;
//     }
//     solve(index+1,sum+a[index]);
//     solve(index+1,sum);

// }

// int main(){
//     cin >> n >> m;
//     for(int i=0; i<n; i++){
//         cin >> a[i];
//     }
//     solve(0,0);
//     if(m == 0) {cnt--;}
//     cout << cnt << endl;

// }


#include <iostream>
#include <algorithm>
using namespace std;
int a[20];
int n, m;
int res = 0;

void solve(int i, int sum){
    if(i == n){
        if(sum == m){
            res++;
        }
        return;
    }
    solve(i+1,sum+a[i]);
    solve(i+1,sum);
}


int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    solve(0,0);
    if(m == 0) res--;
    cout << res << endl;

}