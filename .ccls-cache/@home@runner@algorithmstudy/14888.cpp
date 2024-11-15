// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;


// int calcuation(vector<int> &a, vector<int> &b){
//     int n = a.size();
//     int temp = a[0];

//     for(int i=1; i<n; i++){
//         if(b[i-1] == 0){
//             temp = temp + a[i];
//         }
//         else if(b[i-1] == 1) {
//             temp = temp - a[i];
//         }
//         else if(b[i-1] == 2){
//             temp = temp * a[i];
//         }
//         else {
//             temp = temp / a[i];
//         }
//      }
//     return temp;
// }

// int main(){
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i=0; i<n; i++){
//         cin >> a[i];
//     }

//     vector<int> b;
//     for(int i=0; i<4; i++){
//         int temp;
//         cin >> temp;
//         for(int k=0; k<temp; k++){
//             b.push_back(i);
//         }
//     }

//     sort(b.begin(), b.end());
//     vector<int> res;

//     do{
//         int temp = calcuation(a,b);
//         res.push_back(temp);
//     }while(next_permutation(b.begin(),b.end()));

//     auto it = minmax_element(res.begin(),res.end());

//     cout << *it.second << "\n";
//     cout << *it.first << "\n";







// }


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc(vector<int> &a, vector<int> &b){
    int n = a.size();
    int res = a[0];

    for(int i=1; i<n; i++){
        if(b[i-1] == 0){
            res = res + a[i];
        }
        else if(b[i-1] == 1){
            res = res - a[i];
        }
        else if(b[i-1] == 2){
            res *= a[i];
        }
        else {
            res /= a[i];
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    vector<int> b;

    for(int i=0; i<4; i++){
        int cnt;
        cin >> cnt;

        for(int j=0; j<cnt; j++){
            b.push_back(i);
        }
    }

    sort(b.begin(),b.end());
    vector<int> result;

    do{
        int temp = calc(a,b);
        result.push_back(temp);
    }while(next_permutation(b.begin(),b.end()));

    int max = *max_element(result.begin(),result.end());
    int min = *min_element(result.begin(),result.end());

    cout << max << endl << min << endl;

}

