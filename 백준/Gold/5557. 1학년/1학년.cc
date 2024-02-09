#include <iostream>

#include <vector>

#include <algorithm>

#include <climits>

#include <cstring>

  

using namespace std;

long long d[101][101];

  

long long a[101];

  

int main(){

ios_base :: sync_with_stdio(false);

cin.tie(NULL);

cout.tie(NULL);

  

int n;

cin >> n;

n -= 1;

for(int i=1; i<=n; i++){

cin >> a[i];

}

int goal;

cin >> goal;

  

memset(d,0,sizeof(d));

d[1][a[1]] = 1;

for(int i=1; i<=n-1; i++){

for(int j=0; j<=20; j++){

if(d[i][j] != 0){

if(j+a[i+1]<= 20){

d[i+1][j+a[i+1]] += d[i][j];

}

if(j-a[i+1]>= 0){

d[i+1][j-a[i+1]] += d[i][j];

}

}

}

}

  

cout << d[n][goal]<< endl;

}