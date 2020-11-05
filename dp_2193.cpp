#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

long long dp[91];
long long N;

long long f(long long n){
  if(n == 1){
    return 1;
  }
  if(n == 2){
    return 1;
  }
  if(dp[n] != -1){
    return dp[n];
  }
  dp[n] = f(n-1) + f(n-2);
  return dp[n];
}

int main(){
  freopen("input.txt", "r", stdin);
  cin >> N;
  memset(dp, -1, sizeof(dp));
  cout << f(N) << '\n';
  return 0;
}