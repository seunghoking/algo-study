#include <iostream>

using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  int T;
  cin >> T;
  int result[T+1];
  int answer[T+1];
  int triArr[50+1];
  for(int i=0;i<T; i++){
    cin >> result[i];
  }

  for(int i=1;i<=50;i++){
    triArr[i] = (i * (i+1)) / 2;
  }

  for(int m=0;m<T;m++){
    for(int i=1;i<=50;i++){
      for(int j=1;j<=50;j++){
        for(int k=1;k<=50;k++){
          if(triArr[i] + triArr[j] + triArr[k] == result[m]){
            answer[m] = 1;
          }
        }
      }
    }
  }
  for(int i=0;i<T;i++){
    cout << answer[i] << '\n';
  }
  return 0;
}