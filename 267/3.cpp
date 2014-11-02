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


ll mini=-(1LL<<62);

ll memo[5005][5005];
bool done[5005][5005];

ll sum[5005];

int n,m,k;
ll in[5005];

ll solve( int curr  ,int d)
{
    if( curr > n+1 )
         return mini;

    if( curr==n+1)
    {
        if( d==k)
              return 0;

        return mini;
    }

    if( done[curr][d] )
          return memo[curr][d];

    done[curr][d]=true;
    memo[curr][d]=mini;

    ll ans=mini;

     ans=max(ans, solve(curr+1,d) );

    if( curr+m-1 < 5004)
     ans=max( ans , solve(curr+m,d+1) + sum[curr+m-1]-sum[curr-1] );

     return memo[curr][d]=ans;

}

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>n>>m>>k;

 for(int i=1;i<=n;i++)
    cin>>in[i];

 fill(sum,0);

 for(int i=1;i<=n;i++)
      { sum[i]=sum[i-1]+in[i];
      //  cout<<sum[i]<<"  ";
      }

 fill(done,0);

 for(int i=n;i>=1;i--)
     for(int j=k;j>=0;j--)
        solve(i,j);

//cout<<mini<<endl;
//
// cout<<solve(4,0)<<endl;

 cout<<solve(1,0)<<endl;

 return 0;

}
