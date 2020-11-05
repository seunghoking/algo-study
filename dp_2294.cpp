#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

#define IMPOSSIBLE 1000000000

int N, K;
int cost[101];
int dp[101][10001];

int coin(int n, int k){
  if(n == N){
    return (k == 0 ? 0 : IMPOSSIBLE);
  }
  if(dp[n][k] != -1){
    return dp[n][k];
  }
  int result = coin(n+1, k);
  if(k >= cost[n]){
    result = min(result, coin(n, k-cost[n]) + 1);
  }
  dp[n][k] = result;
  return result;
}

int main(){
  freopen("input.txt", "r", stdin);
  cin >> N >> K;
  for(int i=0;i<N;i++){
    cin >> cost[i];
  }
  memset(dp, -1, sizeof(dp));
  int result = coin(0, K);
  if(result == IMPOSSIBLE){
    puts("-1");
  } else{
    cout << result << '\n';
  }
  
  return 0;
}