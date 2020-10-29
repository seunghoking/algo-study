#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b){
  if(a.second == b.second){
    return a.first < b.first;
  } else {
    return a.second < b.second;
  }
}

int main(){
  freopen("input.txt", "r", stdin);
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  vector<pair<int, int> > schedule;
  cin >> n;
  for(int i=0;i<n;i++){
    int x, y;
    cin >> x >> y;
    schedule.push_back(make_pair(x,y));
  }
  sort(schedule.begin(), schedule.end(), cmp);


  int currentScheduleLastTime = schedule[0].second;
  int answer = 1;
  for(int i=1;i<schedule.size();i++){
    if(schedule[i].first >= currentScheduleLastTime){
      currentScheduleLastTime = schedule[i].second;
      answer++;
    } 
  }
  cout << answer << '\n';

  return 0;
}