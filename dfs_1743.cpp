#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int height, width, k;
int map[101][101];
bool visit[101][101];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int total_count;
int max_result = 0;

int dfs(int x, int y, int cnt){
  visit[x][y] = true;
  int currX = x;
  int currY = y;
  for(int i=0;i<4;i++){
    int nx = dx[i] + currX;
    int ny = dy[i] + currY;
    if(0 <= nx && nx < height && 0 <= ny && ny < width){
      if(!visit[nx][ny] && (map[nx][ny] == 1)){
        total_count++;
        // cout << "nx : " << nx << " ny : " << ny << '\n';
        dfs(nx, ny, total_count);
      }
    }
  }
  return total_count;
}

int main(){
  freopen("input.txt", "r", stdin);
  cin >> height >> width >> k;
  memset(map, 0, sizeof(map));
  memset(visit, false, sizeof(visit));
  for(int i=0;i<k;i++){
    int x, y;
    cin >> x >> y;
    map[x-1][y-1] = 1;
  }
  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
      if(!visit[i][j] && (map[i][j] == 1)){
        total_count = 1;
        total_count = dfs(i, j, total_count);
        if(total_count > max_result){
          max_result = total_count;
        }
      }
    }
  }
  cout << max_result << '\n';

  return 0;
}