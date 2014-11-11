/*
@EXPECTED_RESULTS@: CORRECT
*/

#include<iostream>
#include<vector>

using namespace std;

int main(){
  string s; cin>>s;
  int L=0, R=0;
  int n=s.size();
  for (int i=0; i<n; ++i){
    L+=(s[i]=='L');
    R+=(s[i]=='R');
  }
  int x=1;
  if (R==L){
    cout<<"Too Bad\n";
    return 0;
  }
  if (R>L)
    x=-1;
  vector<int> v(n,0);
  for (int i=0; i<n; ++i)
    v[i]=x*((s[i]=='L')-(s[i]=='R'));
  int i=0, a=0, b=0;
  while(a<n || b>0){
    if (v[i]==-1){
      v[i]=0;
      ++b;
    }
    if (v[i]==1 && b>0){
      --b;
      v[i]=0;
    }
    ++a;
    i=(i+n+x)%n;
  }
  for (i=0; i<n; ++i)
    if (v[i])
      cout<<i<<" ";
  cout<<endl;
  return 0;
}
