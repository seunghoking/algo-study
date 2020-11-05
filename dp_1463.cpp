#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int dp[1000001];

int f(int n){
  if(n == 1){
    return 0;
  }
  if(dp[n] != -1){
    return dp[n];
  }
  
  int result = f(n-1) + 1;
  if(n%3 == 0){
    result = min(result, f(n/3) + 1);
  }
  if(n%2 == 0){
    result = min(result, f(n/2) + 1);
  }
  dp[n] = result;
  return result;
}

int main(){
  freopen("input.txt", "r", stdin);
  int n;
  int cnt=0;
  cin >> n;
  memset(dp, -1, sizeof(dp));
  cout << f(n) << '\n';
  return 0;
}