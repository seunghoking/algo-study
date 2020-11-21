#include <iostream>
#include <vector>

using namespace std;

int L, C;
vector<string> answer;
vector<char> v;

void dfs(int idx, string result, int size1, int size2, int totalSize){
  if(idx == L){
    if(size1 >= 1 && size2 >= 2 && totalSize != 0){
      // answer.push_back(result);
      cout << result << '\n';
    }
    return;
  }
  
  if(v[idx] == 'a' || v[idx] == 'e' || v[idx] == 'i' || v[idx] == 'o' || v[idx] == 'u'){
    dfs(idx+1, result + v[idx], size1+1, size2, totalSize+1);
    cout << "모음" << '\n';
  } else{
    dfs(idx+1, result + v[idx], size1, size2+1, totalSize+1);
    cout << "자음" << '\n';
  }
  dfs(idx+1, result, size1, size2, totalSize);
  
}

int main(){
  freopen("input.txt", "r", stdin);
  cin >> L >> C;
  for(int i=0;i<C;i++){
    char x;
    cin >> x;
    v.push_back(x);
  }
  dfs(0, "", 0, 0, 0);
  // for(int i=0;i<answer.size();i++){
  //   cout << answer[i] << '\n';
  // }
  return 0;
}