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

ll in[maxn];
vector<ll> adj[maxn];

int main()
{
 ios_base::sync_with_stdio(0);

 int n,m;

 cin>>n>>m;

 for(int i=0;i<m;i++)
     cin>>in[i];

 ll ans=0,imp=0;

 for(int i=1;i<m;i++)
 {
        if( in[i]!=in[i-1])
        {
            adj[ in[i] ].pb( in[i-1] );
            adj[ in[i-1] ].pb( in[i] );
        }
        ans+=llabs( in[i]-in[i-1] );
 }

 for(ll x=1;x<maxn;x++)
 {
      if( adj[x].sz==0) continue;

      sort( adj[x].bg , adj[x].en);

      ll y=adj[x][ ( (int)adj[x].sz )/2 ];

      ll tp=0;

      for(int i=0;i<adj[x].sz;i++)
         tp+=llabs( adj[x][i]-x) - llabs(adj[x][i]-y);

      imp=max(imp,tp);
 }

 cout<<ans-imp<<endl;

 return 0;

}
