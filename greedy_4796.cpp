#include <iostream>

using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  int P,L,V,answer,cnt;
  cnt = 1;
  while(1){
    cin >> L >> P >> V;
    if(L == 0 && P == 0 && V == 0){
      break;
    }
    if(V%P > L){
      answer = (V/P*L) + L;
    } else {
      answer = (V/P*L)+(V%P);
    }
    cout << "Case" << " " << cnt << ":" << " " << answer << '\n';
    cnt++;
  }
  return 0;
}