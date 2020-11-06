#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int dp[1001];
int N;

int f(int n){
  if(n == 1){
    return 1;
  }
  if(n == 2){
    return 3;
  }
  if(dp[n] != -1){
    return dp[n] % 10007;
  }
  dp[n] = f(n-1) + 2 * f(n-2);
  return dp[n] % 10007;
}

int main(){
  freopen("input.txt", "r", stdin);
  cin >> N;

  memset(dp, -1, sizeof(dp));
  cout << f(N) % 10007 << '\n';
  return 0;
}