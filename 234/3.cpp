#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz size()
#define bg begin()
#define en end()
typedef long long ll;

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

#define print(a) cout<<(#a)<<" = "<<a<<"  ";
#define println(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );

vector <string> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;

  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);

  return ans;
}


/*Solution code starts here */


int main()
{
 ios_base::sync_with_stdio(0);

 int N,M,X,Y,Z,P;

 cin>>N>>M>>X>>Y>>Z>>P;

 X=X%4; Y=Y%2 ; Z=Z%4;



 for(int p=0;p<P;p++)
 {
      int x,y;
      cin>>x>>y;
      int n=N,m=M;

      for(int j=0;j<X;j++)
      {
            int nx=y;
            int ny=n-x+1;
            x=nx; y=ny;
            swap(n,m);
      }

      if(Y)
      {
          y=m-y+1;
      }

      for(int j=0;j<Z;j++)
      {
          int ny=x;
          int nx=m-y+1;
          x=nx ; y=ny;
          swap(n,m);
      }

      cout<<x<<" "<<y<<endl;
 }

 return 0;

}
