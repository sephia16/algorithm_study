#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

const long long mod = 1000000007LL;
long long d[5001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    d[0] = 1; // 올바른 괄호 문자열의 기본 케이스
    for(int i=2; i<=5000; i+=2){
        for(int j=2; j<=i; j+=2){
            d[i] = (d[i] + d[j-2] * d[i-j]) % mod; // 점화식 적용 및 모듈로 연산
        }
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << d[n] << '\n';
    }
}
