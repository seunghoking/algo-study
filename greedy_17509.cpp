#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  vector<pair<int,int> > problems;
  for(int i=0;i<11;i++){
    int d, v;
    cin >> d >> v;
    problems.push_back(make_pair(d,v));
  }
  sort(problems.begin(), problems.end());
  int firstSum = 0;
  int answer = 0;
  for(int i=0;i<11;i++){
    firstSum += problems[i].first;
    answer += firstSum + (20 * problems[i].second);
  }
  cout << answer << '\n';
  return 0;
}