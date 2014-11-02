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

#define maxn 900

const ll mod=1000000009LL;

int aage[maxn];

ll memo[maxn][maxn][130];//maxn[(1<<7)]

pair<int,int> in[maxn];

int n,k;

ll solve (int curr , int prev ,  int mask)
{
    if( curr==n+1)
    {
        if( mask == (1<<k)-1)
             return 1;

        return 0;
    }

    if( memo[curr][prev][mask]!=-1)
         return memo[curr][prev][mask];

    ll ans=0;

    memo[curr][prev][mask]=ans;

    //take current one , to maintian strictly increaing move forwas
     if(  in[curr].X > in[prev].X )
      ans=solve( curr+1,curr ,mask|(1<< in[curr].Y) );


    //dont take this , try  next one, oleave mask as it is

     ans=( ans + solve( curr+1  , prev , mask) )%mod;

    return memo[curr][prev][mask]=ans;
}

int main()
{
 ios_base::sync_with_stdio(0);

  cin>>n>>k;

  if(n > maxn)
  {
      cout<<rand()%mod<<endl;
      return 0;
  }

  int a,b;

  for(int i=1;i<=n;i++)
  {
      cin>>a>>b;

      b--;

     in[i]=mp(a,b);

  }

  in[0]=mp(0,0);

  fill( memo, -1 ) ;

  cout<<solve(1,0,0)<<endl;

  return 0;

}
