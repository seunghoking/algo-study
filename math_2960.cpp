#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int v[1001];
int answer = 0;

void func(int n, int k){
  for(int i=2;i<=n;i++){
    for(int j=i;j<=n;j+=i){
      if(!v[j]){
        v[j] = 1;
        answer++;
      }
      if(answer == k){
        cout << j << '\n';
        return;
      }
    }
  }
}

int main(){
  freopen("input.txt", "r", stdin);
  int N, K;
  cin >> N >> K;
  memset(v, 0, sizeof(v));
  func(N, K);
  return 0;
}