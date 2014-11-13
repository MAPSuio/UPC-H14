/*
@EXPECTED_RESULTS@: CORRECT
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

struct po{
  int x, y;
};

int main(){
  int X, Y; cin>>Y>>X;
  vector<vector<int> > v(X+2, vector<int>(Y+2, -1));
  vector<string> u(X,"");
  for (int i=0; i<X; ++i)
    cin>>u[i];
  int ax, bx, ay, by;
  for (int i=0; i<X; ++i)
    for (int j=0; j<Y; ++j){
      if (u[i][j]!='X')
	v[i+1][j+1]=-2;
      if (u[i][j]=='S'){
	ax=i+1;
	ay=j+1;
      }
      if (u[i][j]=='G'){
	bx=i+1;
	by=j+1;
      }
    }
  
  po p, p2; p.x=ax; p.y=ay;
  v[ax][ay]=0;
  queue<po> q;
  q.push(p);
  while(q.size()>0){
    p=q.front();
    q.pop();
    for (int i=0; i<4; ++i)
      if (v[p.x+dx[i]][p.y+dy[i]]==-2){
	v[p.x+dx[i]][p.y+dy[i]]=1+v[p.x][p.y];
	p2.x=p.x+dx[i];
	p2.y=p.y+dy[i];
	q.push(p2);
      }
  }
  if (v[bx][by]==-2)
    cout<<"STAY WHERE YOU ARE\n";
  else
    cout<<v[bx][by]-1<<endl;
  


  return 0;
}
  
