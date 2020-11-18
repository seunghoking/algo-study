#include <iostream>
#include <string.h>

using namespace std;

#define MAX 101

int n;
int map[MAX][MAX]={0,};
int check[MAX]={0,};
int result[MAX][MAX]={0,};

void dfs(int curr){
  for(int i=0;i<n;i++){
    if(!check[curr] && map[curr][i] == 1){
      check[curr] = 1;
      dfs(i);
    }
  }
}

int main(){
  freopen("input.txt", "r", stdin);
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin >> map[i][j];
    }
  }

  for(int i=0;i<n;i++){
    memset(check, 0, sizeof(check));
    dfs(i);
    for(int j=0;j<n;j++){
      if(check[j] == 1){
        result[i][j] = 1;
      }
    }
    
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout << result[i][j] << " ";
    }
    cout << '\n';
  }

  return 0;
}