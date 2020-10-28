#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  int N, L;
  int answer = 0;
  vector<int> pipeVector;
  cin >> N >> L;
  for(int i=0;i<N;i++){
    int x;
    cin >> x;
    pipeVector.push_back(x); 
  }

  sort(pipeVector.begin(), pipeVector.end());

  int currentLoc = pipeVector[0];
  answer++;
  for(int i=0;i<pipeVector.size();i++){
    if(pipeVector[i] > currentLoc + L-1){
      currentLoc = pipeVector[i];
      answer++;
    }
  }
  cout << answer << '\n';
  return 0;
}