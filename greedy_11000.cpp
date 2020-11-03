#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  int n;
  int answer = 1;
  vector<pair<int, int> > lecture;
  priority_queue<int, vector<int>, greater<int> > pq;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i=0;i<n;i++){
    int x,y;
    cin >> x >> y;
    lecture.push_back(make_pair(x,y));
  }
  sort(lecture.begin(), lecture.end());

  pq.push(lecture[0].second);

  for(int i=1;i<lecture.size();i++){
    if(lecture[i].first >= pq.top()){
      pq.pop();
      pq.push(lecture[i].second);
    } else {
      pq.push(lecture[i].second);
    }
  }

  cout << pq.size() << '\n';

  return 0;
}