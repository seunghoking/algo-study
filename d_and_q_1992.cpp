#include <iostream>
#include <vector>

using namespace std;

int media[65][65];
vector<char> v;

bool check(int x, int y, int n){
  for(int i=x;i<x+n;i++){
    for(int j=y;j<y+n;j++){
      if(media[i][j] != media[x][y]){
        v.push_back('(');
        return false;
      }
    }
  }
  return true;
}

void solve(int x, int y, int n){
  if(check(x,y,n)){
    if(media[x][y] == 1){
      v.push_back('1');
    } else {
      v.push_back('0');
    }
    return;
  }

  int m = n/2;
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      solve(x+i*m, y+j*m, m);
    }
  }
  v.push_back(')');
  
}

int main(){
  freopen("input.txt", "r", stdin);

  int n;
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%1d", &media[i][j]);
    }
  }

  solve(0,0,n);

  for(int i=0;i<v.size();i++){
    cout << v[i];
  }

  return 0;
}