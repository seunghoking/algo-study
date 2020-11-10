#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  int N,M;
  vector<int> tree;
  cin >> N >> M;
  for(int i=0;i<N;i++){
    int x;
    cin >> x;
    tree.push_back(x);
  }

  int left = 0;
  int right = 1000000000;
  while(left+1 < right){
    int mid = (left + right)/2;
    long long total = 0;
    for(int i=0;i<N;i++){
      if(tree[i] >= mid){
        total += tree[i] - mid;
      }
    }
    if(total >= M){
      left = mid;
    }
    else{
      right = mid;
    }
  }
  cout << left << '\n';
  return 0;
}