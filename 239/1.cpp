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


int main()
{
 ios_base::sync_with_stdio(0);

 vector<pii> a,b;

 int n,m;

 cin>>n>>m;

 for(int i=-n;i<=n;i++)
      for( int j=-n;j<=n;j++)
      {
            if(i==0 || j==0)
                 continue;

         if(i*i+j*j==n*n)
            {
                a.pb( mp(i,j) );
            }
     }

   for(int i=-m;i<=m;i++)
      for( int j=-m;j<=m;j++)
      {
             if(i==0 || j==0)
                 continue;

         if(i*i+j*j==m*m)
           {
             b.pb( mp(i,j) );
           }
      }

    bool mila=false;
    int x,y;

    //y/x*(yy/xx)=-1

    for(int i=0;i<a.sz;i++)
         for(int j=0;j<b.sz;j++)
            if( a[i]!=b[j])
    {
            if( a[i].Y*b[j].Y==-1*a[i].X*b[j].X)//90*
            {

                if( a[i].X==b[j].X)
                     continue;

                if( a[i].Y==b[j].Y)
                     continue;

                mila=true;
                x=i;
                y=j;
            }

    }

    if(!mila)
    {
        cout<<"NO\n";
        return 0;
    }

    cout<<"YES\n";
    cout<<"0 0\n";
    cout<<a[x].X<<" "<<a[x].Y<<endl;
    cout<<b[y].X<<" "<<b[y].Y<<endl;

    return 0;

}
