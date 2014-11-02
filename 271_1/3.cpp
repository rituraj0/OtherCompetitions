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


const ll mod = 1000000007 ;

ll memo[100005];

ll dp[100005];

int k;

ll solve( int n)
{
    if(n < 0) return 0;

    if(n==0) return 1;

    if( memo[n]!=-1) return memo[n];

    ll ans=0;

    //eat W
    ans=solve(n-k);

    ans=(ans + solve(n-1) )%mod;

    return memo[n]=ans;
}


int main()
{
 ios_base::sync_with_stdio(0);

 fill( memo, -1);

 int t;

 cin>>t>>k;

 for(int i=0;i<=100000;i++)
     solve(i);

  fill(dp,0);

  for(int i=1;i<=100000;i++)
     dp[i]=( dp[i-1] + solve(i) )%mod;

 int a,b;

 while(t--)
 {
     cin>>a>>b;

     ll ans= ( dp[b] + ( mod*3LL- dp[a-1])%mod )%mod;;

     cout<<ans<<endl;
 }

 return 0;

}
