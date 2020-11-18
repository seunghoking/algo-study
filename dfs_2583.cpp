#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int height, width, k;
int map[101][101];
bool visit[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0 ,1};
int total_count;
vector<int> answer;

void dfs(int x, int y){
  visit[x][y] = true;
  int currX = x;
  int currY = y;
  for(int i=0;i<4;i++){
    int nx = dx[i] + currX;
    int ny = dy[i] + currY;
    if(0 <= nx && nx < height && 0 <= ny && ny < width){
      if(!visit[nx][ny] && (map[nx][ny] == 0)){
        total_count++;
        dfs(nx, ny);
      }
    }
  }
}

int main(){
  freopen("input.txt", "r", stdin);
  int cnt = 0;
  cin >> height >> width >> k;
  memset(map, 0, sizeof(map));
  memset(visit, false, sizeof(visit));
  for(int i=0;i<k;i++){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int j=x1;j<x2;j++){
      for(int k=y1;k<y2;k++){
        map[k][j] = 1;
      }
    }
  }

  for(int i=0;i<height;i++){
    for(int j=0;j<width;j++){
      if(!visit[i][j] && (map[i][j] == 0)){
        total_count = 1;
        cnt++;
        dfs(i,j);
        answer.push_back(total_count);
      }
    }
  }

  cout << cnt << '\n';
  sort(answer.begin(), answer.end());
  for(int i=0;i<answer.size();i++){
    cout << answer[i] << ' ';
  }
  return 0;
}