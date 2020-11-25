#include <iostream>

using namespace std;

void func(int a, int b, int n){
  if(n==1){
    cout << "1 : " << a << ' ' << b << '\n';
    return;
  }
  int c = 6-a-b;
  func(a,c,n-1);
  cout << "2 : " << a << ' ' << b << '\n';
  func(c,b,n-1);
}

int main(){
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  cout << (1<<n)-1 << '\n';
  func(1,3,n);

  return 0;
}