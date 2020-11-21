#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

int personNum;
int compPerson1, compPerson2;
int n;
vector<vector<int> > adj;
queue<int> q;
int dist[101] = {0, };

int bfs(int p1, int p2){
  q.push(p1);
  while(!q.empty()){
    int front_val = q.front();
    q.pop();
    if(front_val == p2){
      return dist[p2];
    }
    for(int i=0;i<adj[front_val].size();i++){
      int next = adj[front_val][i];
      if(!dist[next]){
        dist[next] = dist[front_val] + 1;
        q.push(next);
      }
    }
  }
  return -1;
}

int main(){
  freopen("input.txt", "r", stdin);

  cin >> personNum;
  cin >> compPerson1 >> compPerson2;
  cin >> n;

  if(compPerson1 == compPerson2){
    cout << 0 << '\n';
    return 0;
  }

  adj.resize(101);

  for(int i=0;i<n;i++){
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  cout << bfs(compPerson1, compPerson2) << '\n';

  return 0;
}