#include <bits/stdc++.h>
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
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

#define maxn 100009
#define pii pair<int,int>

int boss[maxn];

vector<pii> in;

int root( int x)
{
    if( boss[x]==-1) return x;

    return boss[x]=root( boss[x] );
}

void join( int x, int y)
{
      int xp=root(x) , yp=root(y);

      if(xp==yp) return;

      if( rand()&1)
         boss[xp]=yp;
      else
        boss[yp]=xp;
}


int main()
{
 int n,k,p,x;

 scanf("%d%d%d",&n,&k,&p);

 for(int i=0;i<n;i++)
 {
     scanf("%d",&x);
     in.pb( mp(x,i+1) );
 }

 sort( in.bg , in.en);

  fill( boss, -1);

 for(int i=0;i<n;i++)
 {
      if( i > 0)
      {
          if( in[i].X - in[i-1].X <=k )
          { join( in[i].Y,in[i-1].Y);
          }
      }

      if( i < n-1)
      {
           if( in[i+1].X - in[i].X <=k )
           {
               join( in[i+1].Y , in[i].Y);
           }
      }
 }

 int y;

 for(int i=0;i<p;i++)
 {
      scanf("%d%d",&x,&y);

      if( root(x)==root(y))
         printf("Yes\n");
      else
         printf("No\n");
 }

 return 0;

}
