#include <iostream>

using namespace std;

int dx[4] = {0,0,1,1};
int dy[4] = {0,1,0,1};

int N, r, c;
int answer=0;

void func(int n, int x, int y){
  if(n == 2){
    for(int i=0;i<4;i++){
      int nx = dx[i] + x;
      int ny = dy[i] + y;
      if(nx == r && ny == c){
        cout << answer << '\n';
        return;
      }
      answer++;
    }
    return;
  }
  func(n/2, x, y);
  func(n/2, x, y + n/2);
  func(n/2, x + n/2, y);
  func(n/2, x + n/2, y + n/2);
}

int main(){
  freopen("input.txt", "r", stdin);

  cin >> N >> r >> c;
  func((1<<N), 0, 0);

  return 0;
}