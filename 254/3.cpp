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

#define maxn 555

ll val[maxn];
ll wt[maxn][maxn];

//ll vs[maxn];
//ll es[maxn];


int boss[maxn];

int root(int x)
{
    if( boss[x]==x) return x;

    return boss[x]=root( boss[x] );
}



vector< pair<int, pair<int,int> > >all;

double solve( int a, int b , int n)
{
    vector<int> in;

     for(int i=1;i<=n;i++)
         if( ( root(a)==root(i) ) ||( root(b)==root(i) ) )
             in.pb(i);

    double vsum=0,esum=0;

           for(int i=0;i<in.sz;i++)
           {
             vsum+=val[ in[i] ];

               for(int j=i+1;j<in.sz;j++)
               {
                     esum+=wt[ in[i] ][ in[j] ];
               }
            }

           return (vsum/esum)  ;
}

void join( int x,int y)
{
    int xp=root(x) , yp=root(y);

    if(xp==yp) return;

    if( rand() &1 )
        boss[xp]=yp;
    else
        boss[yp]=xp;
}


int main()
{
 ios_base::sync_with_stdio(0);

 int n,m;

 cin>>n>>m;

 for(int i=1;i<=n;i++)
     cin>>val[i];

  int a,b,c;

  fill(wt,0);

  for(int i=0;i<m;i++)
  {
      cin>>a>>b>>c;

      wt[a][b]=wt[b][a]=c;

      all.pb( mp(c , mp(a,b) ) );
  }

  sort(all.bg,all.en);

  for(int i=1;i<=n;i++)
    boss[i]=i;

  double ans=0;

  for(int i=0;i<m;i++)
  {
      a=all[i].Y.X;
      b=all[i].Y.Y;
      c=all[i].X;

      if( root(a)==root(b) )
         continue;

      double tp=solve(a,b,n);

      if( tp >  ans)
      {
          join(a,b);
          ans=tp;
      }

  }


  printf("%.15lf\n",ans);

 return 0;

}
