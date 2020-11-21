#include <iostream>
#include <vector>

using namespace std;

int n, s, cnt;
vector<int> v;

void dfs(int idx, int sum, int size){
  if(idx == n){
    if(sum == s && size != 0){
      cnt++;
    }
    return;
  }
  
  dfs(idx+1, sum + v[idx], size+1);
  dfs(idx+1, sum, size);
}

int main(){
  freopen("input.txt", "r", stdin);
  cin >> n >> s;
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    v.push_back(x);
  }
  dfs(0,0,0);
  cout << cnt << '\n';
  return 0;
}