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
#define Y second
#define X first
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

#define pii pair<int,int>
vector<pii> in,save;

bool done[105];

int sm=0;

int dist( int x, int y , int a ,int b)
{
    int s=(x-a)*(x-a) + (y-b)*(y-b);

    double ret=sqrt( (double)s);

    return ceil(ret);
}

vector<int> solve( )
{
    int n=in.sz;



    int x=(in[0].X+in[n-1].X)/2;
    int y=(in[0].Y+in[n-1].Y)/2;
    int r=max( dist(in[0].X , in[0].Y , x , y) , dist( in[n-1].X , in[n-1].Y , x , y) );
        r=max(r,1);

        sm+=r;

    fill(done,0);

    for(int i=0;i<n;i++)
         if( (x-in[i].X)*(x-in[i].X) + (y-in[i].Y)*(y-in[i].Y) <= r*r )
           done[i]=true;

    vector< pii > tp;

    for(int i=0;i<n;i++)
         if( !done[i] )
            tp.pb( in[i] );


    in=tp;

    vector<int> ans;
            ans.pb(x);
            ans.pb(y);
            ans.pb(r);

            return ans;



}


int main()
{
 ios_base::sync_with_stdio(0);

 int n;

 cin>>n;

 int x,y;

 for(int i=0;i<n;i++)
 {
     cin>>x>>y;
     in.pb( mp(x,y) );
 }


 sort( in.bg,in.en);

 save=in;

 vector< vector<int> > ans;

 while(in.size())
 {
    ans.pb( solve() );
 }


 if( sm > n)
 {
      cout<<n<<endl;

      for(int i=0;i<n;i++)
         cout<<save[i].X<<" "<<save[i].Y<<" 1\n";

      return 0;
 }

 cout<<ans.sz<<endl;

 for( int i=0;i<ans.sz;i++,cout<<endl)
     for(int j=0;j<3;j++)
      cout<<ans[i][j]<<" ";

 return 0;

}
