#include <iostream>

using namespace std;

int cnt[3];
int paper[2188][2188];

bool same(int x, int y, int n){
  for(int i=x;i<x+n;i++){
    for(int j=y;j<y+n;j++){
      if(paper[x][y] != paper[i][j]){
        return false;
      }
    }
  }
  return true;
}

void solve(int x, int y, int n){
  if(same(x,y,n)){
    cnt[paper[x][y]+1]++;
    return;
  }

  int m = n/3;

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      solve(x+i*m, y+j*m, m);
    }
  }
}

int main(){
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;

  for(int i=0;i < n; i++){
    for(int j=0;j < n; j++){
      cin >> paper[i][j];
    }
  }

  solve(0, 0, n);

  for(int i=0;i<3;i++){
    cout << cnt[i] << '\n';
  }
  return 0;
}