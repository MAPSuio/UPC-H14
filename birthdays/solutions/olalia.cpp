/*
@EXPECTED_RESULTS@: CORRECT
*/

#include<iostream>
#include<vector>


using namespace std;

bool before(int a1, int a2, int a3, int a4, int a5, int a6){
  if (a3<a6)
    return 1;
  if (a3>a6)
    return 0;
  if (a2<a5)
    return 1;
  if (a2>a5)
    return 0;
  if (a1>a4)
    return 0;
  return 1;
}

int main(){
  vector<int> goodyear;
  int y=4; int d=0;
  while(y<3000){
    //cout<<y<<" "<<d<<endl;
    if (d>4)
      goodyear.push_back(y);
    if (((y+4)%100) || !((y+4)%400)){
      y+=4;
      d+=4*365+1;
      d%=7;
    }
    else{
      y+=8;
      d+=1+8*365;
      d%=7;
    }
  }
  int a, b, c, e, f;
  string s;
  cin>>a>>b>>c>>s>>d>>e>>f;
  int ans=0;
  for (int i=0; i<goodyear.size(); ++i){
    //cout<<goodyear[i]<<endl;
    if (before(a, b, c, 29, 2, goodyear[i]) && before(29, 2, goodyear[i], d, e, f))
      ++ans;
  }
  cout<<ans<<endl;
  return 0;
}
