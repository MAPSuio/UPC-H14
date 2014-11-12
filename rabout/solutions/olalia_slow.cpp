/*
@EXPECTED_RESULTS@: TIMELIMIT
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
    cout<<"Too bad\n";
    return 0;
  }
  int k;
  for (int i=0; i<n; ++i){
    k=0;
    if (s[i]=='R'){
      for (int j=i+1; j!=i; j=(j+1)%n){
	if (s[j]=='L'){
	  if (!k){
	    s[j]='c';
	    s[i]='c';
	    break;
	  }
	  else
	    --k;
	}
	if (s[j]=='R')
	  ++k;
      }
    }
    if (s[i]=='L'){
      for (int j=(i-1+n)%n; j!=i; j=(j-1+n)%n){
	if (s[j]=='R'){
	  if (!k){
	    s[j]='c';
	    s[i]='c';
	    break;
	  }
	  else
	    --k;
	}
	if (s[j]=='L')
	  ++k;
      }
    }
  }
  for (int i=0; i<n; ++i)
    if (s[i]!='c')
      cout<<i<<" ";
  cout<<endl;
  return 0;
}
