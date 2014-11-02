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


ll wt[555][555];
ll val[555];

int main()
{
 ios_base::sync_with_stdio(0);

 fill(wt,0);

 int n,m;
 int a,b,c;

 cin>>n>>m;

 for(int i=0;i<n;i++)
     cin>>val[i];

   fill(wt,0) ;

  for(int i=0;i<m;i++)
  {
      cin>>a>>b>>c;
      a--; b--;
      wt[b][a]=wt[a][b]=c;
  }

  double ans=0;
  vector<int> ms;

  n--;//last vertex not connected

  for(int mask=1;mask<(1<<n);mask++)
  {
        vector<int> in;

        for(int i=0;i<n;i++)
             if( mask&(1<<i))
               in.pb(i);

        ll vs=0,es=0;

        for(int i=0;i<in.sz;i++)
        {
             vs+=val[ in[i] ];

               for(int j=i+1;j<in.sz;j++)
               {
                     es+=wt[ in[i] ][ in[j] ];
               }
        }

        if(es==0) continue;

        double curr=((double)vs)/( (double)es );

        if( curr>ans)
        {
            ans=curr;
            ms=in;
        }
  }


  print(ans);

  for(int i=0;i<ms.sz;i++)
     cout<<ms[i]<<" ";



 return 0;

}
