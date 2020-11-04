#include <iostream>
#include <vector>

using namespace std;

long long int a, b, c;
int result = 0;

long long int pow(long long int x, long long int m){
  if(m == 1){
    return x % c;
  }

  long long int temp = pow(x, m/2) % c;

  if(m%2){
    return ( ((temp * temp) %c) * (x % c)) % c;
  } 
  else{
    return (temp * temp) % c;
  }

}

int main(){
  freopen("input.txt", "r", stdin);
  cin >> a >> b >> c;

  cout << pow(a,b) << '\n';

  return 0;
}