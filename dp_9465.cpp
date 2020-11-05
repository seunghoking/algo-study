#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int N, value[2][100001], dp[100001][3];

int sticker(int c, int status){
  if(c == N) return 0;
  if(dp[c][status] != -1) return dp[c][status];

  int result = sticker(c+1, 0);
  if(status != 1){
    result = max(result, sticker(c+1, 1) + value[0][c]);
  }
  if(status != 2){
    result = max(result, sticker(c+1, 2) + value[1][c]);
  }
  dp[c][status] = result;
  return result;
}

int main(){
  freopen("input.txt", "r", stdin);
  int T;
  cin >> T;
  for(int i = 0;i<T;i++){
    cin >> N;
    for(int j=0;j<2;j++){
      for(int k=0;k<N;k++){
        cin >> value[j][k];
      }
    }

    memset(dp, -1, sizeof(dp));
    // for(int j=0;j<N;j++){
    //   for(int k=0;k<3;k++){
    //     dp[j][k] = -1; 
    //   }
    // }

    cout << sticker(0,0) << '\n';

  }
  return 0;
}