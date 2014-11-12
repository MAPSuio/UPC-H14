/*
@EXPECTED_RESULTS@: CORRECT
*/

#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<string>

using namespace std;

struct antistring{
  string s;
};

bool operator<(const antistring &a, const antistring &b){
  return b.s<a.s;
}
		 

int main(){
  map<string, int> m;
  vector<string> v;
  string s1, s2, s3;
  vector<vector<int> > before;
  int n=0;
  while(cin>>s1>>s2>>s3){
    //cout<<s1<<s2<<s3<<endl;
    if (m.find(s1)==m.end()){
      before.push_back(vector<int>());
      m[s1]=n;
      ++n;
      v.push_back(s1);
    }
    if (m.find(s3)==m.end()){
      before.push_back(vector<int>());
      m[s3]=n;
      ++n;
      v.push_back(s3);

    }
    if (s2[0]=='B')
      before[m[s1]].push_back(m[s3]);
    else
      before[m[s3]].push_back(m[s1]);
  }
  vector<int> nbef(n,0);
  for (int i=0; i<n; ++i)
    for (int j=0; j<before[i].size(); ++j)
      nbef[before[i][j]]++;
  antistring as;
  priority_queue<antistring> q;
  for (int i=0; i<n; ++i){
    if (nbef[i]==0){
      as.s=v[i];
      q.push(as);
    }
  }
  while(q.size()>0){
    as=q.top();
    q.pop();
    cout<<as.s<<endl;
    int k=m[as.s];
    for (int i=0; i<before[k].size(); ++i){
      nbef[before[k][i]]--;
      if (nbef[before[k][i]]==0){
	as.s=v[before[k][i]];
	q.push(as);
      }
    }
  }
  return 0;
}
