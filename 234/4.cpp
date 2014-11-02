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

int boss[1<<17];
int id[1<<17];

int root(int in)
{
    if( boss[in]==in)
         return in;

     return boss[in]=root( boss[in] );
}

int  join( int x, int y)
 {
      int px=root(x) ,py=root(y);

       if(px==py)
         return 0;

       if( rand()&1 )
         boss[px]=py;
       else
          boss[py]=px;

        return 0;
}

int main()
{
 ios_base::sync_with_stdio(0);

 int n,m,k;

 cin>>n>>m>>k;

 int prev=0,x,y,w;

 fill(id,0);

 for(int i=1;i<=k;i++)
 {
    cin>>x;

    for(int j=prev+1;j<=prev+x;j++)
         id[j]=i;

     prev=prev+x;
 }

 ll dp[505][505];

 fill(dp,63);

 for(int i=1;i<=k;i++)
     dp[i][i]=0;

  for(int i=1;i<=n;i++)
      boss[i]=i;

  for(int i=1;i<=m;i++)
  {
        cin>>x>>y>>w;

        if(!w)
        {
            join( x , y );
        }

         dp[ id[x] ][ id[y] ]=dp[ id[y] ][ id[x] ]=min( dp[ id[x] ][ id[y] ] ,(ll)w);

  }

  bool cool=true;

//  for(int i=1;i<=n;i++)
//      cout<<id[i]<<"  "<<root(i)<<endl;

  for(int i=1;i<n;i++)
     if( id[i]==id[i+1] )
          if( root(i)!=root(i+1))
           cool=false;

     if(!cool)
     {
         cout<<"No\n";
         return 0;
     }


   for(int c=1;c<=k;c++)
     for(int a=1;a<=k;a++)
      for(int b=1;b<=k;b++)
        dp[a][b]=min( dp[a][b] , dp[a][c]+dp[c][b]);

    cout<<"Yes\n";

   for(int a=1;a<=k;a++,cout<<endl)
     for(int b=1;b<=k;b++)
       if( dp[a][b] > (1LL<<50) )
          cout<<"-1 ";
        else
           cout<<dp[a][b]<<" ";

 return 0;

}
