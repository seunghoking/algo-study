#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>

using namespace std;

int dp[100001];
int powList[100001];
int N;

int f(int n, int sqrt_num){
  if(n == 2){
    return 2;
  }
  if(n == 3){
    return 3;
  }
  if(dp[n] != -1){
    return dp[n];
  }
  dp[n] = f(n - powList[sqrt_num], int(sqrt(n - powList[sqrt_num]))) + 1;
  return dp[n];
}

int main(){
  freopen("input.txt", "r", stdin);
  cin >> N;
  memset(dp, -1, sizeof(dp));
  for(int i=1;i<=N;i++){
    powList[i] = pow(i,2);
    if(powList[i] < 100001){
      dp[powList[i]] = 1;
    }
  }
  cout << f(N, int(sqrt(N))) << '\n';

  return 0;
}