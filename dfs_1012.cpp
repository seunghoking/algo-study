#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

// width는 y
// height는 x
int t, width, height, k;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0 ,1};
int graph[51][51];
bool visit[51][51];
int cnt=0;

int dfs(int x, int y){
  visit[x][y] = true;
  int currX = x;
  int currY = y;
  int cnt = 1;
  for(int i=0;i<4;i++){
    int nx = dx[i] + currX;
    int ny = dy[i] + currY;
    if(0 <= nx && nx < height && 0 <= ny && ny < width){
      if(!visit[nx][ny] && (graph[nx][ny] == 1)){
        dfs(nx, ny);
      }
    }
  }
  return cnt;
}

int main(){
  freopen("input.txt", "r", stdin);
  cin >> t;
  for(int i=0;i<t;i++){
    cin >> width >> height >> k;
    memset(graph, 0, sizeof(graph));
    memset(visit, false, sizeof(visit));
    cnt = 0;
    for(int j=0;j<k;j++){
      int x, y;
      cin >> x >> y;
      graph[y][x] = 1;
    }
    for(int k=0;k<height;k++){
      for(int l=0;l<width;l++){
        if(!visit[k][l] && (graph[k][l] == 1)){
          dfs(k,l);
          cnt++;
        }
      }
    }
    cout << cnt << '\n';
  }
  return 0;
}