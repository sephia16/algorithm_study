// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// vector<int> lotto;

// void select(vector<int> &a, int index, int cnt){
//     if(cnt == 6){
//         for(int n : lotto){
//             cout << n << " ";
//         }
//         cout << "\n";
//         return;
//     }
//     int len = a.size();
//     if(index == len){
//         return;
//     }
//     lotto.push_back(a[index]);
//     select(a,index+1,cnt+1);
//     lotto.pop_back();
//     select(a,index+1,cnt);
// }




// int main(){
//     while(true){
//         int n;
//         cin >> n;
//         if(n == 0) {
//             break;
//         }
//         vector<int> a(n);
//         for(int i=0; i<n; i++){
//             cin >> a[i];
//         }
//         select(a,0,0);
//         cout << endl;


//     }

// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> lotto;

void solve(vector<int> &a, int index, int cnt){
    if(cnt == 6){
        for(int n : lotto){
            cout << n << " ";
        }
        cout << "\n";
        return;
    }
    int len = a.size();
    if(index == len) return;
    lotto.push_back(a[index]);
    solve(a,index+1,cnt+1);
    lotto.pop_back();
    solve(a,index+1,cnt);
}

int main(){
    while(true){
    int n;
    cin >> n;
    if(n == 0) {break;}
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    solve(a,0,0);
    cout << endl;

    }

}