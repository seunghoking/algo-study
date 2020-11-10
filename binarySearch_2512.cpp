#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  int N, max_int;
  vector<int> budget;
  cin >> N;
  for(int i=0;i<N;i++){
    int x;
    cin >> x;
    budget.push_back(x);
  }
  cin >> max_int;
  
  sort(budget.begin(), budget.end());
  long long sum = 0;
  for(int i=0;i<N;i++){
    sum += budget[i];
  }

  if(sum <= max_int){
    cout << budget[budget.size()-1] << '\n';
  } else {
    int left = 0;
    int right = 1000000000;
    while(left + 1 < right){
      int mid = (left + right) / 2;
      long long total = 0;
      for(int i=0;i<N;i++){
        if(budget[i] >= mid){
          total += mid;
        }
        else{
          total += budget[i];
        }
      }
      if(total <= max_int){
        left = mid;
      }
      else{
        right = mid;
      }
    }
    cout << left << '\n';
  }
  return 0;
}