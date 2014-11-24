#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(s) ((int)(s.size()))
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


#define maxn 3005

int  all[maxn][maxn];

bool done[maxn][maxn];

vector<int> graf[maxn];

void dfs( int curr ,int p)
{
    if( done[curr][p] )
         return;

    done[curr][p]=true;

    for(int i=0;i<sz( graf[curr]);i++)
    {
        int nx=graf[curr][i];

        if(nx==p)
            continue;
        all[p][nx]++;

        dfs(nx,curr);
    }

}

int main()
{
 ios_base::sync_with_stdio(0);

 int n,m;

 cin>>n>>m;

 int a,b;

 while(m--)
 {
     cin>>a>>b;
     graf[a].pb(b);
 }

 fill(done,0);
 fill(all,0);

 for(int i=1;i<=n;i++)
    for(int j=0;j<sz( graf[i] );j++)
      dfs( graf[i][j],i); //for every edge

 ll ans=0;

 for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
 {
     ll cc= all[i][j];

     ans+=cc*(cc-1)/2LL;
 }

 cout<<ans<<endl;

 return 0;

}
