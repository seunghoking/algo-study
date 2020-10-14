#include <iostream>
using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++){
    int copy = i;
    int sum = i;
    while(copy){
      sum += copy % 10;
      copy /= 10;
    }

    if(i == n || sum == n){
      if(i == n){
        cout << 0 << '\n';
      } else {
        cout << i << '\n';
      }
      break;
    }
  }
  return 0;
}