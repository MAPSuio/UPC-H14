#include<iostream>
#include<cmath>

#define sq(x) ((x)*(x))

using namespace std;

int main() {
  double area = 0.0;
  int n;
  double x0,xi,xii,y0,yi,yii;
  cin>>n;
  n-=3;
  cin>>x0>>y0>>xi>>yi;
  do {
    cin>>xii>>yii;
    double l1 = sqrt(sq(xi-x0)+sq(yi-y0));
    double l2 = sqrt(sq(xii-xi)+sq(yii-yi));
    double l3 = sqrt(sq(x0-xii)+sq(y0-yii));
    double S = (l1+l2+l3)/2;
    // does not take convexity into account
    area += sqrt(S*(S-l1)*(S-l2)*(S-l3));
    xi = xii;
    yi = yii;
  } while(n-->0);
  cout<<area<<endl;
}
