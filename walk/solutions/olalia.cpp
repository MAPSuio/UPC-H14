/*
# @EXPECTED_RESULTS@: CORRECT
*/

#include<iostream>

using namespace std;

int main(){
  int n; cin>>n;
  int a, b;
  a=1;
  for (int i=0; i<n+1; ++i){
    cin>>b;
    if (b==1)
      a=!a;
    else
      break;
  }
  if (a)
    cout<<"Angwusnasomtaqa\n";
  else
    cout<<"Bob\n";
  return 0;
}
