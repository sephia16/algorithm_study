// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <map>
// #include <cmath>
// using namespace std;

// char ascii[256];

// int calculate(vector<string> &a, vector<char> &letters, vector<int> &d){
//     int m = letters.size();
//     int sum = 0;

//     for(int i=0; i<m; i++){
//         ascii[letters[i]] = d[i];
//     }
//     for(string s : a){
//         int now = 0;
//         for(char x : s){
//             now = 10*now + ascii[x];
//         }
//         sum += now;
//     }
//     return sum;

// }


// int main() {
//     int n;
//     cin >> n;
//     vector<string> a(n);
//     vector<char> letters;
//     string s;
//     for (int i=0; i<n; i++){
//         cin >> a[i];
//         for(char x : a[i]){
//             letters.push_back(x);
//         }
//     }
    
//     sort(letters.begin(),letters.end());
//     letters.erase(unique(letters.begin(),letters.end()),letters.end());

//     vector<int> d;
//     int m = letters.size();
//     for(int i=9; i>9-m; i--){
//         d.push_back(i);
//     }

//     sort(d.begin(),d.end());
    
//     int result = 0;
//     do{
//         int cur = calculate(a, letters, d);
//         if (cur > result) result = cur;
//     } while(next_permutation(d.begin(),d.end()));

//     cout << result << '\n';

    
//     return 0;
// }


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;

char ascii[256];


int calc(vector<string> &s, vector<char> &letters, vector<int> &d){
    int sum =0;
    int m = letters.size();
    for(int i=0; i<m; i++){
        ascii[letters[i]] = d[i];
    }
    
    for(string a : s){
        int cur = 0;
        for(char x : a){
            cur = 10*cur + ascii[x];
        }
        sum += cur;
    }
    return sum;
}

int main() {
    

    int n;

    cin >> n;

    vector<string> s(n);
    vector<char> letters;

    for(int i=0; i<n; i++){
        cin >> s[i];
        int m = s[i].size();
        for(char x : s[i]){
            letters.push_back(x);
        }
    }
        
        sort(letters.begin(),letters.end());

       letters.erase(unique(letters.begin(),letters.end()),letters.end());

       vector<int> d;

       int m = letters.size();

       for(int i=9; i>9-m; i++){
            d.push_back(i);
       }

       sort(d.begin(),d.end());

        int result =0;

        do{
            int temp = calc(s,letters,d);
            if(result < temp ) result = temp; 
        }while(next_permutation(d.begin(),d.end()));


        cout << result << "\n";





    }

    

