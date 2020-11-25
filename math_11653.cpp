#include <iostream>
#include <vector>

using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  int n;
  vector<int> v;
  cin >> n;

  int num = n;
  for(int i=2;i<=n;i++){
    if(num == 1){
      break;
    }
    while(num % i == 0){
      num /= i;
      v.push_back(i);
    }
  }
  for(int j=0;j<v.size();j++){
    cout << v[j] << '\n';
  }

  return 0;
}