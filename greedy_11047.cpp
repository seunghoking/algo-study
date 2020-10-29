#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
  return a > b;
}

int main(){
  freopen("input.txt", "r", stdin);
  int goalMoney;
  int n;
  int answer = 0;
  vector<int> kindOfMoney;
  cin >> n >> goalMoney;

  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    kindOfMoney.push_back(x);
  }
  sort(kindOfMoney.begin(), kindOfMoney.end(), cmp);
  for(int i=0;i<kindOfMoney.size();i++){
    if(goalMoney == 0){
      break;
    }
    if(goalMoney >= kindOfMoney[i]){
      answer += goalMoney / kindOfMoney[i];
      goalMoney %= kindOfMoney[i];
    }
  }
  cout << answer << '\n';
  return 0;
}