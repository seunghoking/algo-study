#include <iostream>
#include <string.h>

using namespace std;

int n;
int map[101][101];
int result[101][101];
bool visit[101];

void dfs(int curr){
  for(int k=0;k<n;k++){
    if((map[curr][k] == 1) && !visit[k]){
      visit[k] = true;
      dfs(k);
    }
  }
}

int main(){
  freopen("input.txt", "r", stdin);
  cin >> n;
  memset(visit, false, sizeof(visit));
  memset(result, 0, sizeof(result));
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> map[i][j];
    }
  }

  for(int i=0;i<n;i++){
    dfs(i);
    for(int j=0;j<n;j++){
      if(visit[j]){
        result[i][j] = 1;
      }
    }
    memset(visit, false ,sizeof(visit));
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout << result[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}